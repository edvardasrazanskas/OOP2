#include <iostream>
#include "funkcijos.h"
#include "Timer.h"

using namespace std;

int main()
{
    vector<Studentas> studentai;
    list<Studentas> studentaiList;
    deque<Studentas> studentaiDeq;

    float tipas;
    int kiekis;
    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";
    while (true)
    {
        float pasirinkimas = GetIntInput();
        if ( pasirinkimas == 1 ){
            
            Timer t;
            cout << "Pasirinkite kaip noresite skaityti:\na) su vectors (rasykite 1)\na) su lists (rasykite 2)\nb) su deque (rasykite 3): ";
            while(true){
                tipas = GetIntInput();

                cout << "Iveskite kieki kuri skaitysite pagal failo pavadinima: ";
                cin >> kiekis;

                t.reset();

                if (tipas == 1){
                    Ivestis(studentai, kiekis); // ***** Reading from a file
                    cout << "Failas nuskaitytas. Rikiuojama..." << endl;
                    sortVector(studentai);
                }
                else if (tipas == 2)
                {
                    Ivestis(studentaiList, kiekis); // ***** Reading from a file
                    cout << "Failas nuskaitytas. Rikiuojama..." << endl;
                    sortList(studentaiList);
                }
                else if (tipas == 3)
                {
                    Ivestis(studentaiDeq, kiekis); // ***** Reading from a file
                    cout << "Failas nuskaitytas. Rikiuojama..." << endl;
                    sortDeque(studentaiDeq);
                }
                else if (cin.eof()) {
                    break;
                }

                else cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
                break;
            }
            
            cout << "Failas buvo nuskaitytas ir išrikiuotas per: " <<  t.elapsed() << endl;
            break;
        }
        else if (pasirinkimas == 2){
            Ivestis2(studentai); // Reading from user input
            break;
        }
        else if (pasirinkimas == 3){
            Ivestis3(studentai); // Generating random number of random grades for random number of students
            break;
        }
        else if (cin.eof()) {
            break;
        }
        else cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
    }
    system("pause");
    
    cout << endl << setw(17) << left << "Pavarde" << setw(17) << "Vardas" << setw(17)
        << "Galutinis (Vid.)"<< "/ Galutinis (Med.)\n" << string(70, '-') << endl;
    
    if(tipas==1){
        for(const auto& s : studentai)
            cout << setw(17) << left << s.pavarde << setw(17) << s.vardas << setw(17) << fixed << setprecision(2) << s.vidurkis << s.mediana << endl;
    } else if(tipas == 2){
        for(const auto& s : studentaiList)
            cout << setw(17) << left << s.pavarde << setw(17) << s.vardas << setw(17) << fixed << setprecision(2) << s.vidurkis << s.mediana << endl;
    } else if(tipas == 3){
        for(const auto& s : studentaiDeq)
            cout << setw(17) << left << s.pavarde << setw(17) << s.vardas << setw(17) << fixed << setprecision(2) << s.vidurkis << s.mediana << endl;
    }
    system("pause");
    return 0;
}