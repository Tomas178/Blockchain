# Blockchain

## void PaddedInput(string& simboliu_seka)
- prie **simboliu_seka** yra pridedamas string'as **"11111"**.

## Maišos funkcija
```cpp
string Maisos_funkcija(string& simboliu_seka){

    Salt(simboliu_seka);
    const unsigned int size = simboliu_seka.length();
    bitset<8> bit_map(size);
    string nauja_simboliu_seka;
    const unsigned int hash_parts = 4;

    unsigned long long hashes[hash_parts] = {
        0x6a09e667f3bcc908,
        0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b,
        0x5be0cd19137e2179
    };

    PaddedInput(simboliu_seka);

    for(char c : simboliu_seka){
        bit_map = bitset<8>(c);
        bit_map.flip();
        for(int i = 0; i < hash_parts; i++){
            hashes[i] ^= bit_map.to_ulong() * 0x9e3779b97f4a7c15;
            hashes[i] = (hashes[i] << 5) | (hashes[i] >> 59);
        }
    }

    ostringstream oss;
    for(int i = 0; i < hash_parts; i++){
        oss << hex << setw(16) << setfill('0') << hashes[i];
    }
    return oss.str();
}
```
- **string& simboliu_seka** – Tekstas, kuris yra hash'inamas.
- **Salt(Simboliu_seka)** – Grąžina "padruskintą" įvestį pagal nustatyta reikšmę.
- **bitset<8> bit_map(size)** – Kiekvienas simbolis verčiamas į 8 bitų seką, bit_map(size) talpina simboliu_seka.length()*8 bitų.
```cpp
    unsigned long long hashes[hash_parts] = {
        0x6a09e667f3bcc908,
        0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b,
        0x5be0cd19137e2179
    };
```
- **for(char c : simboliu_seka)** – iteruoja per kiekvieną simbolį **simboliu_seka** string'e

 - **bit_map = bitset<8>(c)** konvertuoja simbolį į 8 bitų seką.
 - **bit_map.flip()** paverčia 0 –> 1 ir 1 –> 0.
 - **hashes[i] ^= bit_map.to_ulong() * 0x9e3779b97f4a7c15** naudojmas XOR tarp hashes[i] reiksmes ir **bit_map.to_ulong() * 0x9e3779b97f4a7c15**, kur **bit_map.to_ulong()** yra bitų sekos konvertavimas į dešimtainį skaičių.
 - **hashes[i] << 32** pastuma 32  bit'us į kairę.
 - **hashes[i] >> 32** pastuma 32  bit'us į dešinę.
 - **oss << hex << setw(16) << setfill('0') << hashes[i];** – į ostringstream objektą yra įrašoma 16 simbolių hex vertė iš **hashes[i]**(taip iteruoja 4 kartus iš viso), jei truksta simbolių, tada pripildoma tiek nulių kiek jų truksta.
 ```cpp
    for(int i = 0; i < hash_parts; i++){
        oss << hex << setw(16) << setfill('0') << hashes[i];
    }
```
- **oss.str()** – grąžina reikšmę kaip string'ą.

## Skaitymas iš failo
```cpp
string Failo_apdorojimas(string failo_pavadinimas){
    ifstream DF(failo_pavadinimas);
    failo_pavadinimas = "";

    if(!DF.is_open()){
        __throw_runtime_error("Nepavyko atidaryti failo");
    }

    string line;
    while(getline(DF, line)){
        failo_pavadinimas += line;
        //cout << line << endl;
    }
    DF.close();
    //cout << failo_pavadinimas;
    return failo_pavadinimas;
}
```
- **string failo_pavadinimas** – failo pavadinimas
- Funkcija nuskaito visą failą kas eilute ir grąžina visa failo tekstą kaip string'ą.

## Tyrimas su Konstitucija.txt
![Konstitucijos Tyrimas](Tyrimas.png)

## 2 Uzduotis
```cpp
//Paprastas tekstas
Iveskite failo pavadinima: 1uzduotis/Blockchain.txt
fb8dfb4068990bd3a449c97bc7fb0147765bd3bf58bafe023f4a5fed931a0072

//Paprastas tekstas su šauktuku gale
Iveskite failo pavadinima: 1uzduotis/Blockchain!.txt
661f1034b7f479d39e9957415bb52b58dcda0fd2b38ac3e2feeb858bc7950deb

//Paprastas tekstas ir paprastas tekstas su šauktuku gale Hex lygmenyje sutapo 4.69%, o bitų 53.91%

//Random tekstas su 1370 simboliais
Iveskite failo pavadinima: 1uzduotis/random1370.txt
52b0d1debea0e9618a3274c94fac678a5a4da5bdcb2ad6adb27239af8f49c21f

//Random tekstas su 2000 simboliais
Iveskite failo pavadinima: 1uzduotis/random2000.txt
d023c3998b38f96f08a1668e7a347784d8deb7fafeb2c6a330e12be8bad1d211

//Random2000.txt su šauktuku viduryje teksto
Iveskite failo pavadinima: 1uzduotis/random2001.txt
99a0742f94375a3368acfac44cb5ff24ec2a4be39cca2e50a8495f5174f5b242

//random2000.txt ir random2001.txt Hex lygmenyje sutapo 7.81%, o bitų 53.91%

//Tuscias failas
Iveskite failo pavadinima: 1uzduotis/tuscias.txt
9e5311ee3aaa152346d1b4f9cba69bc896ae658d4f202aef7e91f99f0b433e5d
```

## Hash'as, kuomet skiriasi per viena simbolį
```cpp
Iveskite savo simboliu seka: Tomas
a9e0ee28320dabec3dbf2a1a09a2c9e6786d3800cd3d88190824298c9ff628e7

Iveskite savo simboliu seka: tomas
5c61f26d574dc52ac83e365f6ce2a7208dec2445a87de6dffda535c9fab64621

Iveskite savo simboliu seka: Tomas!
2bbdbd3fe5607e39a0453b78908c3f6b1a07782003640083132549aa5a101f4d
```
- **"Tomas"** ir **"tomas"** Hex lygmenyje sutapo **6.25%**, o bitų **56.25%**.

## Bitų ir Hex Max, Min ir Avg panašumai:
```cpp
Max bitu panasumas: 72.27 %
Min bitu panasumas: 57.23 %
Vidutinis bitu panasumas: 65.09 %

Max hex panasumas: 6.25 %
Min hex panasumas: 0.00 %
Vidutinis hex panasumas: 4.68 %
```

## Tyrimas su SHA256, SHA1 ir md5 hash algoritmais su 4 užduoties tekstu
```cpp
Iveskite failo pavadinima: 4Uzduotis.txt
Mano hash reiksme: 407c88f34f4ce6ee97cd8db960aefff3d86d721b89a7f291bdbd0d23ad2f34b8
Mano hash'o vykdymo laikas: 4.1486s

SHA256 reiksme: c166e3d51ddb70b494c9f29d3ddade1c381e54cb4281d89bba5f3935962f614b
sha256 hash'o vykdymo laikas: 1.19493s

SHA1 reiksme: 801a8883d801b3a876ad365b7dfa537d3e00edea
sha1 hash'o vykdymo laikas: 0.950222s

md5 reiksme: 0d0437d6e59de37e9e44e3bc9ca21546
md5 hash'o vykdymo laikas: 1.03567s
```

