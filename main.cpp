#include "funkcijos.h"

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
}