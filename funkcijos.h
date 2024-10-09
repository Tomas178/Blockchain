#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <bitset>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include <openssl/sha.h>
#include "hashes/sha256.h"
#include "hashes/sha1.h"
#include "hashes/MD5.h"

using namespace std;

string Maisos_funkcija(string& simboliu_seka);
string Failo_apdorojimas(string failo_pavadinimas);
void poru_hashinimas_5_uzduociai();
void poru_hashinimas_6_uzduociai();
void Tikrinti_5_uzduoti();
string Tikrinti_6_uzduoti_procentaliai_hex_lygmenyje();
string hexToBinary(const string& hex);
string Tikrinti_6_uzduoti_procentaliai_bitu_lygmenyje();
void PaddedInput(string& simboliu_seka);
void salt(string& simboliu_seka);
void Mano_Hash_vs_Geriausi_hash(string simboliu_seka);

extern int norimas_programos_veikimas;
extern string simboliu_seka;
extern string failo_pavadinimas;

#endif