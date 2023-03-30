#include <iostream>
#include "funkcijos.h"
#include "Timer.h"

using namespace std;

int main()
{
    vector<Studentas> studentai;
    //list<Studentas> studentaiList;
    //deque<Studentas> studentaiDeq;

    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";

    while (true)
    {
        float pasirinkimas = GetIntInput();

        if ( pasirinkimas == 1 ){
            //list<Studentas> studentaiList;
            //deque<Studentas> studentaiDeq;
            Timer t;
            cout << "Pasirinkite kaip noresite skaityti:\na) su vectors (rasykite 1)\na) su lists (rasykite 2)\nb) su deque (rasykite 3): ";
            while(true){
                float tipas = GetIntInput();
                t.reset();
                if (tipas == 1)
                    Ivestis<vector<Studentas>>(studentai); // ***** Reading from a file
                else if (tipas == 2)
                {
                    Ivestis<vector<Studentas>>(studentai); // ***** Reading from a file
                }
                else if (tipas == 3)
                {
                    Ivestis<vector<Studentas>>(studentai); // ***** Reading from a file
                }
                else if (cin.eof()) {
                    break;
                }
                else cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
                break;
            }
            cout << "Failas buvo nuskaitytas per: " <<  t.elapsed() << endl;

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

    //Isvestis(studentai);
    system("pause");
    return 0;
}