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

    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";

    while (true)
    {
        float pasirinkimas = GetIntInput();

        if ( pasirinkimas == 1 ){
            
            Timer t;
            cout << "Pasirinkite kaip noresite skaityti:\na) su vectors (rasykite 1)\na) su lists (rasykite 2)\nb) su deque (rasykite 3): ";
            while(true){

                tipas = GetIntInput();
                t.reset();

                if (tipas == 1){
                    Ivestis<vector<Studentas>>(studentai, tipas); // ***** Reading from a file
                    cout << "after ivestis vecotr" << endl;
                    sortVector(studentai);
                    cout << "after quicksort vector" << endl;
                }
                else if (tipas == 2)
                {
                    Ivestis<list<Studentas>>(studentaiList, tipas); // ***** Reading from a file
                    cout << "after ivestis list" << endl;
                    sortList(studentaiList);
                    cout << "after quicksort list" << endl;
                }
                else if (tipas == 3)
                {
                    Ivestis<deque<Studentas>>(studentaiDeq, tipas); // ***** Reading from a file
                    sortDeque(studentaiDeq);
                }
                else if (cin.eof()) {
                    cout << "cin.eof triggered" << endl;
                    break;
                }

                else cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
                break;
            }
            
            cout << "Failas buvo nuskaitytas per: " <<  t.elapsed() << endl;
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
    
    if(tipas == 1) Isvestis<vector<Studentas>>(studentai);
    else if(tipas == 2) Isvestis<list<Studentas>>(studentaiList);
    else if(tipas == 3) Isvestis<deque<Studentas>>(studentaiDeq);

    system("pause");
    return 0;
}