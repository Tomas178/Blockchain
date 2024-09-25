#include "funkcijos.h"

void poru_hashinimas_5_uzduociai(){
    string failas = "4uzduotis.txt";
    ifstream DF(failas);
    ofstream RF("5Uzduotis.txt");
    string line,zodis1, zodis2, hash1, hash2;
    while(getline(DF, line)){
        istringstream iss(line);
        iss >> zodis1 >> zodis2;
        hash1 = Maisos_funkcija(zodis1);
        hash2 = Maisos_funkcija(zodis2);
        RF << hash1 << " " << hash2 << endl;
    }
    cout << "Poru hashinimas atliktas sekmingai." << endl;
}

void poru_hashinimas_6_uzduociai(){
    string failas = "6uzduotis.txt";
    ifstream DF(failas);
    ofstream RF("6Uzduotis_uzhashinta.txt");
    string line, zodis1, zodis2, hash1, hash2;
    while(getline(DF, line)){
        istringstream iss(line);
        iss >> zodis1 >> zodis2;
        hash1 = Maisos_funkcija(zodis1);
        hash2 = Maisos_funkcija(zodis2);
        RF << hash1 << " " << hash2 << endl;
    }
    cout << "Poru hashinimas atliktas sekmingai." << endl;
}

bool Tikrinti_5_uzduoti(string failas){
    ifstream DF(failas);
    string line;
    int linecounter = 0;
    string hash1;
    string hash2;
    while(getline(DF, line)){
        istringstream iss(line);
        linecounter++;
        iss >> hash1 >> hash2;
        if(hash1 == hash2){
            cout << linecounter << " eiluteje sutapo hash'ai." << endl;
            return false;
        }
    }
    cout << "Hash'ai nesutapo." << endl;	
    return true;
}

string Tikrinti_6_uzduoti_procentaliai(){
    string failas = "6Uzduotis_uzhashinta.txt";
    ofstream RF("6Uzduoties_uzhashinimas_procentaliai_hexu_lygmenyje.txt");
    ifstream DF(failas);
    string line, hash1, hash2;
    int linecounter = 0;
    while(getline(DF, line)){
        double sutape_simboliai = 0.0;
        istringstream iss(line);
        linecounter++;
        iss >> hash1 >> hash2;
        for(int i = 0; i < hash1.length(); i++){
            if(hash1[i] == hash2[i]){
                sutape_simboliai++;
            }
        }
        if(sutape_simboliai > 0.0)
        RF << linecounter << " Eiluteje sutapo " << fixed << setprecision(2) << sutape_simboliai/64*100 << "% simboliu." << endl;
    }
    return "Viskas OK";
}

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

void PaddedInput(string& simboliu_seka){
    simboliu_seka += "11111";
}


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