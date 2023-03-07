#include <iostream>
#include "funkcijos.h"

using namespace std;

int main()
{
    vector<Studentas> studentai;

    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";
    
    while (true)
    {
        float pasirinkimas = GetIntInput();

        if ( pasirinkimas == 1 ){
            Ivestis(studentai); // ***** Reading from a file
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

    Isvestis(studentai);
    system("pause");
    return 0;
}