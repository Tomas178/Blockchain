#include "funkcijos.h"

int norimas_programos_veikimas;
string simboliu_seka;
string failo_pavadinimas;

int main() {
    cout << "Pasirinkite programos veikima:\n1. Vedimas rankiniu budu.\n2. Skaitymas is failo.\n3. 5 Uzduotis.\n4. Tikrinti 5 uzduoti.\n5. 6 Uzduotis.\n";
    cout << "6. Tikrinti 6 uzduoti procentaliai Hex'u lygmenyje.\n7. Tikrinti 6 uzduoti procentaliai Bit'u lygmenyje.\n8. Mano Hash vs sha256." << endl;
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
                Tikrinti_6_uzduoti_procentaliai_hex_lygmenyje();
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
            break;
        case 7:
            try{
                Tikrinti_6_uzduoti_procentaliai_bitu_lygmenyje();
            } catch (const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
        case 8:
            try{
                cout << "Iveskite failo pavadinima: "; cin >> simboliu_seka;
                Mano_Hash_vs_Geriausi_hash(simboliu_seka);
            } catch(const std::exception &err){
                cout << "Ivyko klaida: " << err.what() << endl;
            }
    }

    //cout << ConvertToBinary(simboliu_seka) << endl;
    //cout << Add_More_Bits(simboliu_seka) << endl;
    const auto start = chrono::high_resolution_clock::now();
    if(norimas_programos_veikimas == 1 || norimas_programos_veikimas == 2){
        cout << Maisos_funkcija(simboliu_seka) << endl;
    }
    const auto end = chrono::high_resolution_clock::now();
    cout << "Programos vykdymo laikas: " << chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000 << "s" << endl;
    
    return 0;
}