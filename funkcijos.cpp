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
    DF.close();
    RF.close();
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
    DF.close();
    cout << "Poru hashinimas atliktas sekmingai." << endl;
}

void Tikrinti_5_uzduoti(){
    string failas = "6Uzduotis_uzhashinta.txt";
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
        }
    }
    DF.close();
    cout << "Hash'ai nesutapo." << endl;	
}

string Tikrinti_6_uzduoti_procentaliai_hex_lygmenyje(){
    string failas = "6Uzduotis_uzhashinta.txt";
    ofstream RF("6Uzduoties_uzhashinimas_procentaliai_hexu_lygmenyje.txt");
    ifstream DF(failas);
    double HexMax = 0.0;
    double HexMin = 100.0;
    double HexAvg = 0.0;
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
        RF << linecounter << " Eiluteje sutapo " << fixed << setprecision(2) << sutape_simboliai/64*100 << "% simboliu." << endl;
        HexMax = (sutape_simboliai/64*100 > HexMax) ? sutape_simboliai/64*100 : HexMax;
        HexMin = (sutape_simboliai/64*100 < HexMin) ? sutape_simboliai/64*100 : HexMin;
        HexAvg += sutape_simboliai/64*100;
    }
    cout << "Max hex panasumas: " << fixed << setprecision(2) << HexMax << " %" << endl;
    cout << "Min hex panasumas: " << fixed << setprecision(2) << HexMin << " %" << endl;
    cout << "Vidutinis hex panasumas: " << fixed << setprecision(2) << HexAvg/linecounter << " %" << endl;
    DF.close();
    RF.close();
    return "Viskas OK";
}

void Mano_Hash_vs_Geriausi_hash(string simboliu_seka){
    ifstream DF(simboliu_seka);
    simboliu_seka = "";

    if(!DF.is_open()){
        __throw_runtime_error("Nepavyko atidaryti failo");
    }

    string line;
    while(getline(DF, line)){
        simboliu_seka += line;
    }
    DF.close();

    auto My_hash_pradzia = chrono::high_resolution_clock::now();
    string my_hash1 = Maisos_funkcija(simboliu_seka);
    cout << "Mano hash reiksme: "<< my_hash1 << endl;
    double My_hash_pabaiga = chrono::duration<double>(chrono::high_resolution_clock::now() - My_hash_pradzia).count();
    cout << "Mano hash'o vykdymo laikas: " << My_hash_pabaiga << "s" << endl << endl;	

    auto Sha256_pradzia = chrono::high_resolution_clock::now();
    string sha256_hash = sha256(simboliu_seka);
    cout << "SHA256 reiksme: "<< sha256_hash << endl;
    double Sha256_pabaiga = chrono::duration<double>(chrono::high_resolution_clock::now() - Sha256_pradzia).count();
    cout << "sha256 hash'o vykdymo laikas: " << Sha256_pabaiga << "s" << endl << endl;

    auto Sha1_pradzia = chrono::high_resolution_clock::now();
    string sha1_hash = sha1(simboliu_seka);
    cout << "SHA1 reiksme: "<< sha1_hash << endl;
    double Sha1_pabaiga = chrono::duration<double>(chrono::high_resolution_clock::now() - Sha1_pradzia).count();
    cout << "sha1 hash'o vykdymo laikas: " << Sha1_pabaiga << "s" << endl << endl;

    auto md5_pradzia = chrono::high_resolution_clock::now();
    string md5_hash = md5(simboliu_seka);
    cout << "md5 reiksme: "<< md5_hash << endl;
    double md5_pabaiga = chrono::duration<double>(chrono::high_resolution_clock::now() - md5_pradzia).count();
    cout << "md5 hash'o vykdymo laikas: " << md5_pabaiga << "s" << endl << endl;

}

string hexToBinary(const string& hex) {
    string binary;
        for (std::size_t i = 0; i < hex.size(); ++i){
            binary += bitset<8>(hex[i]).to_string();
        }
    return binary;
}

string Tikrinti_6_uzduoti_procentaliai_bitu_lygmenyje(){
    string failas = "6Uzduotis_uzhashinta.txt";
    ofstream RF("6Uzduoties_uzhashinimas_procentaliai_bitu_lygmenyje.txt");
    ifstream DF(failas);
    string line, hash1, hash2;
    double BitMax = 0.0;
    double BitMin = 100.0;
    double BitAvg = 0.0;
    int linecounter = 0;
    while(getline(DF, line)){
        double sutape_simboliai = 0.0;
        istringstream iss(line);
        linecounter++;
        iss >> hash1 >> hash2;
        string hash_to_binary1 = hexToBinary(hash1);
        string hash_to_binary2 = hexToBinary(hash2); 
        for(int i = 0; i < hash_to_binary1.length(); i++){
            if(hash_to_binary1[i] == hash_to_binary2[i]){
                sutape_simboliai++;
            }
        }
        //RF << hash_to_binary1 << " " << hash_to_binary2 << endl;
        RF << linecounter << " Eiluteje sutapo " << fixed << setprecision(2) << sutape_simboliai/512*100 << "% simboliu." << endl;
        BitMax = (sutape_simboliai/512*100 > BitMax) ? sutape_simboliai/512*100 : BitMax;
        BitMin = (sutape_simboliai/512*100 < BitMin) ? sutape_simboliai/512*100 : BitMin;
        BitAvg += sutape_simboliai/512*100;
    }
    cout << "Max bitu panasumas: " << fixed << setprecision(2) << BitMax << " %" << endl;
    cout << "Min bitu panasumas: " << fixed << setprecision(2) << BitMin << " %" << endl;
    cout << "Vidutinis bitu panasumas: " << fixed << setprecision(2) << BitAvg/linecounter << " %" << endl;
    DF.close();
    RF.close();
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

void Salt(string& simboliu_seka){
    string salt = "AZ!@#()&,v;em.gT";
    simboliu_seka += salt;
}


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