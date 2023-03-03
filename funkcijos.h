#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "vector"
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

const string INFILENAME = "studentai10000.txt";

struct Studentas{
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
};

int Partition(std::vector<Studentas>& arr, int low, int high){
    Studentas pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp((arr[j].vardas).c_str(), (pivot.vardas).c_str()) < 0) {
            i++;
            swap(arr[i], arr[j]);
        } else if(strcmp((arr[j].vardas).c_str(), (pivot.vardas).c_str()) == 0){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void Quicksort(std::vector<Studentas>& arr, int low, int high){
    if (low < high) {
        int pi = Partition(arr, low, high);
        Quicksort(arr, low, pi - 1);
        Quicksort(arr, pi + 1, high);
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

            if(num >= 0 && num < 11){
                break;
            } else if(num == 11){
                return num;
            } else {
                cout << "Pazymys " << num << " neegzistuoja. Jis bus ignoruojamas." << endl;                
            }

        } catch (invalid_argument const &e) {
            if (cin.eof()) {
                cout << "Programa baigiama." << endl;
                break;
            }
            cout << "Vienas is ivestu simboliu nėra skaicius. Jis bus ignoruojamas." << endl;
        }
    }
    return num;
}

float RastiMediana(int arr[], int n)
{
    // Isrikiuojam didejimo tvarka, kad galetume rasti mediana
    for(int j=0; j<n; j++)
    {
        for(int z=j+1; z<n+1; z++)
        {
            if(arr[j]>arr[z]) swap(arr[j], arr[z]);
        }
    }

    if( (n+1) %2 == 0 ) return (arr[n/2] + arr[n/2+1])/2.0;
    else return arr[n/2];
}

int CountN(string line)
{
    stringstream s (line);

    string word;
    int count = 0;
    while (s >> word)
        count++;

    return count-3;
}

void Isvestis(vector<Studentas> &studentai)
{
    Quicksort(studentai, 0, studentai.size() - 1);
    cout << endl << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
        << "Galutinis (Vid.)"<< "/ Galutinis (Med.)\n" << string(70, '-') << endl;

    for(int i=0; i<studentai.size(); i++)
    {
        cout << setw(17) << left << studentai[i].pavarde << setw(17) << studentai[i].vardas 
            << setw(17) << fixed << setprecision(2) << studentai[i].vidurkis << studentai[i].mediana << endl;
    }
}

// Generates randomly
void Ivestis3(vector<Studentas> &studentai)
{
    // Generates random number between 100 and 10'000
    srand(time(nullptr));
    int m = rand() % 9901 + 100;

    // array for holding grades of every student
    int sk[100];

    for(int i=0; i<m; i++)
    {
        float pazymiu_suma = 0;

        // generates between 2 and 20 random numbers (of values between 1 and 10)
        // last number in an array is grade for exam
        int n = rand() % 19 + 2;
        for(int j=0; j<=n; j++)
        {
            sk[j] = rand() % 10 + 1;
            pazymiu_suma += sk[j];
        }

        pazymiu_suma -= sk[n]; // atimam egzamino rezultato verte

        float mediana = RastiMediana(sk, n);
        Studentas studentas{
            ("Vardas" + to_string(i)),
            ("Pavarde" + to_string(i)),
            ((pazymiu_suma/n * 0.4) + (sk[n] * 0.6)),
            mediana
        };

        studentai.push_back(studentas);
    }
}



// Gets from user input
void Ivestis2(vector<Studentas> &studentai)
{
    string vardas, pavarde;
    int sk[100], m;
    
    while(true)
    {
        float pazymiu_suma = 0;
        cout << "Iveskite varda: \n>>> ";
        cin >> vardas;
        if (cin.eof()) break;

        cout << "Iveskite pavarde:\n>>> ";
        cin >> pavarde;
        if (cin.eof()) break;

        cout << "Iveskite visus pazymius (paskutnis pazymys yra egzamino rezultatas). Surase visus pazymius iveskite 11 ir spauskite enter:\n>>> ";

        int n=0;

        while (n < 100)
        {
            sk[n] = GetIntInput();
            if(sk[n] == 11 && n>1){
                break;
            } else if(sk[n] == 11 && n<2){
                cout << "Reikia įvesti bent 2 skaicius. Veskite is naujo\n>>> ";
                n = 0;
            }

            pazymiu_suma += sk[n];
            n++;
        }

        n--; // nes mums nereikia paskutinio skaiciaus, nes jis reiskia skaiciu ivedimo pabaiga
        pazymiu_suma -= sk[n]; // atimam egzamino rezultato verte, nes paskutine verte yra egzamino rezultatas

        cout << "Ivesti sie pazymiai: \n";
        for(int za=0; za<n; za++) cout << sk[za] << " ";
        cout << "Egzamino rez: " << sk[n] << endl;
        cout << "Enter -> testi  /  r + enter -> ivesti is naujo\n>>> ";

        string pasirinkimas;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, pasirinkimas);
        cout << "Pasirinkimas: " << pasirinkimas << endl;

        if(pasirinkimas == "r"){
            cout << "\nIvedimas is naujo\n";
            m--;
        } else {
            float mediana = RastiMediana(sk, n);

            Studentas studentas{
                vardas, pavarde,
                ((pazymiu_suma/(n) * 0.4) + (sk[n] * 0.6)),
                mediana
            };
            studentai.push_back(studentas);
        }

        m++;

        cout << "\n(norint nutraukti -> ctrl+Z ir Enter)\n";
    }
}


// Reads from file
void Ivestis(vector<Studentas> &studentai)
{
    try{
        // Count n and m
        ifstream infile_count(INFILENAME);
        string s;
        getline(infile_count, s);
        int  n = CountN(s);
        int m = 0;
        while(getline(infile_count, s)) m++;

        ifstream infile(INFILENAME);
        string vardas, pavarde;
        int sk[100];
        getline(infile, vardas);

        for(int i=0; i<m; i++)
        {
            float pazymiu_suma = 0;

            // Nuskaitom ir apskaiciuojam vidurki
            infile >> vardas >> pavarde;
            for(int j=0; j<n; j++){
                infile >> sk[j];
                pazymiu_suma += sk[j];
            }
            infile >> sk[n];

            float mediana = RastiMediana(sk, n);

            Studentas studentas{
                vardas, pavarde,
                ((pazymiu_suma/n * 0.4) + (sk[n] * 0.6)),
                mediana
            };

            studentai.push_back(studentas);
        }
    } catch(std::exception const& e){
        cout << "Nepavyko nuskaityti failo:\n" << e.what() << endl;
    }
}

#endif