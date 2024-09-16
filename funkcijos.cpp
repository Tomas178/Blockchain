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

string Maisos_funkcija(string simboliu_seka){

    const unsigned int size = simboliu_seka.length();
    bitset<8> bit_map[size];

    string nauja_simboliu_seka;
    for(int i = 0; i < size; i++){
        bit_map[i] = simboliu_seka[i];
        nauja_simboliu_seka += bit_map[i].to_string();
    }
    nauja_simboliu_seka += "11111";

    cout << "Bitu skaicius: "<< nauja_simboliu_seka.size() << endl;
    cout << nauja_simboliu_seka << endl;

    //bitset<32> bit_map[simboliu_seka.length()];
    //bitset<32> copy;
    return "hello";
}