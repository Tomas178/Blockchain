#include "funkcijos.h"

string ConvertToBinary(string simboliu_seka){
    bitset<8> Binary{simboliu_seka.length()};
    return Binary.to_string();
}

string Maisos_funkcija(string simboliu_seka){
    bitset<32> bit_map[simboliu_seka.length()];
    bitset<32> copy;
    return copy;
}