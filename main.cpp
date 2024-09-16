#include "funkcijos.h"

int norimas_programos_veikimas;
string simboliu_seka;
string failo_pavadinimas;

int main() {
    cout << "Pasirinkite programos veikima:\n1. Vedimas rankiniu budu.\n2. Skaitymas is failo" << endl;
    cin >> norimas_programos_veikimas;
    switch(norimas_programos_veikimas){
        case 1: 
            try{
                cout << "Iveskite savo simboliu seka: ";
                cin >> simboliu_seka;
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            } 
            break;
        case 2:
            try{
                cout << "Iveskite failo pavadinima: ";
                cin >> failo_pavadinimas;
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
    }

    cout << ConvertToBinary(simboliu_seka) << endl;
    cout << Maisos_funkcija(simboliu_seka) << endl;
    
    return 0;
}