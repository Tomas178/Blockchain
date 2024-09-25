#include "funkcijos.h"

int norimas_programos_veikimas;
string simboliu_seka;
string failo_pavadinimas;

int main() {
    cout << "Pasirinkite programos veikima:\n1. Vedimas rankiniu budu.\n2. Skaitymas is failo.\n3. 5 Uzduotis.\n4. Tikrinti 5 uzduoti.\n5. 6 Uzduotis.\n";
    cout << "6. Tikrinti 6 uzduoti procentailiai." << endl;
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
                simboliu_seka = Failo_apdorojimas(failo_pavadinimas);
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
        case 3:
            try{
                poru_hashinimas_5_uzduociai();
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
        case 4:
            try{
                Tikrinti_5_uzduoti();	
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
        case 5: 
            try{
                poru_hashinimas_6_uzduociai();
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
        case 6:
            try{
                Tikrinti_6_uzduoti_procentaliai();
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
    }

    //cout << ConvertToBinary(simboliu_seka) << endl;
    //cout << Add_More_Bits(simboliu_seka) << endl;
    const auto start = chrono::high_resolution_clock::now();
    //cout << Maisos_funkcija(simboliu_seka) << endl;
    const auto end = chrono::high_resolution_clock::now();
    cout << "Programos vykdymo laikas: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000 << "s" << endl;
    
    return 0;
}