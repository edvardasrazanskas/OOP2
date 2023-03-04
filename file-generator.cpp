#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void GeneratorAndWriter(int kiekis);

// Isvesti i folderi, kuris yra .gitignore faile
// failai/sugeneruoti

int main()
{
    for(int i=1000; i<=10000000; i*=10){
        GeneratorAndWriter(i);
        cout << "File with: " << i << " students was created.\n";
    }    
    
    
    return 0;
}


void GeneratorAndWriter(int kiekis)
{
    string pavadinimas = "failai/sugeneruoti/studentai" + to_string(kiekis) + ".txt";

    //pradeti laiko skaiciavima
    ofstream out_file(pavadinimas);

    out_file << setw(17) << left << "Vardas" << setw(17) << "Pavardė";
    for(int i=1; i<=15; i++) out_file << setw(17) << ("ND" + to_string(i));
    out_file << setw(17) << "Egz.";

    srand(time(nullptr));

    for(int i=1; i<=kiekis; i++)
    {
        out_file << endl << setw(17) << ("Vardas" + to_string(i)) << setw(17) << ("Pavarde" + to_string(i));

        for(int j=0; j<16; j++) out_file << setw(17) << (rand() % 10 + 1);
    }
}


int GetIntInput()
{
    int num;
    string input;

    while (true)
    {
        cin >> input;

        try {
            num = stoi(input);
            break;
        } catch (invalid_argument const &e) {
            if (cin.eof()) {
                cout << "Programa baigiama." << endl;
                break;
            }
            cout << "Ivestas ne skaicius. Problema: " << e.what() << endl;
        }
    }
    return num;
}