#include "funkcijos.h"

string Failo_apdorojimas(string failo_pavadinimas){
    ifstream DF(failo_pavadinimas);
    failo_pavadinimas = "";

    if(!DF.is_open()){
        __throw_runtime_error("Nepavyko atidaryti failo");
    }

    string line;
    while(getline(DF, line)){
        failo_pavadinimas += line;
    }
    DF.close();
    return failo_pavadinimas;
}

string BinaryToHex(const string& binary){
    stringstream HEX;
    unsigned long long int HexValue = 0;

    for (size_t i = 0; i < binary.size(); i += 4) {
        string binaryChunk = binary.substr(i, 4); 
        HexValue = bitset<4>(binaryChunk).to_ulong();   
        HEX << hex << HexValue;                  
    }

    return HEX.str();
}

void PaddedInput(string& simboliu_seka){
    simboliu_seka += "11111";
    if(simboliu_seka.length() % 512 != 448){
        for(int i = 0; i < 448 - (simboliu_seka.length() % 512); i++){
            simboliu_seka += "0";
        }
    }
}


string Maisos_funkcija(string simboliu_seka){

    const unsigned int size = simboliu_seka.length();
    vector<bitset<8>> bit_map(size);
    string nauja_simboliu_seka;

    for (unsigned int i = 0; i < size; i++) {
        bit_map[i] = simboliu_seka[i];
        nauja_simboliu_seka += bit_map[i].to_string();
    }
    //nauja_simboliu_seka += "11111";

    PaddedInput(nauja_simboliu_seka);
    cout << nauja_simboliu_seka << endl;

    string HexString = BinaryToHex(nauja_simboliu_seka);

    cout << "Bitu skaicius: "<< nauja_simboliu_seka.size() << endl;
    cout << HexString << endl;


    //bitset<32> bit_map[simboliu_seka.length()];
    //bitset<32> copy;
    return "hello";
}