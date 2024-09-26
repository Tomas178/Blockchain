# Blockchain

## void PaddedInput(string& simboliu_seka)
- prie **simboliu_seka** yra pridedamas string'as **"11111"**.

## Maišos funkcija
```cpp
string Maisos_funkcija(string& simboliu_seka){

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
            hashes[i] = (hashes[i] << 32) | (hashes[i] >> 32);
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
- **bitset<8> bit_map(size)** – Kiekvienas simbolis verčiamas į 8 bitų seką, bit_map(size) talpina simboliu_seka.length()*8 bitų.
– Keturios atsitiktines reikšmės po 64 bit'us.
```cpp
    unsigned long long hashes[hash_parts] = {
        0x6a09e667f3bcc908,
        0x9b05688c2b3e6c1f,
        0x1f83d9abfb41bd6b,
        0x5be0cd19137e2179
    };
- **for(char c : simboliu_seka)** – iteruoja per kiekvieną simbolį **simboliu_seka** string'e

 – **bit_map = bitset<8>(c)** konvertuoja simbolį į 8 bitų seką.
 - **bit_map.flip()** paverčia 0 –> 1 ir 1 –> 0.<br>**hashes[i] ^= bit_map.to_ulong() * 0x9e3779b97f4a7c15** naudojmas XOR tarp hashes[i] reiksmes ir **bit_map.to_ulong() * 0x9e3779b97f4a7c15**, kur **bit_map.to_ulong()** yra konvertavimas į dešimtainį skaičių.
 - **hashes[i] = (hashes[i] << 32) | (hashes[i] >> 32)** - **hashes[i] << 32** pastuma 32  bit'us į kairę, o **hashes[i] >> 32** pastuma 32  bit'us į dešinę.

## Tyrimas su Konstitucija.txt
![Konstitucijos Tyrimas](Tyrimas.png)

