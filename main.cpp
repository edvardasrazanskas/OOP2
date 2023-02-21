#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
};

int CountN(string line);
float RastiMediana(int arr[], int n);

void Ivestis(Studentas studentai[], int &m);
void Ivestis2(Studentas studentai[], int &m);
void Ivestis3(Studentas studentai[], int &m);
void Isvestis(Studentas studentai[], int m);


const string INFILENAME = "studentai10000.txt";
const int ARR_SIZE = 10000;

int main(){
    int m = 0;
    Studentas studentai[ARR_SIZE];

    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if ( pasirinkimas == 1 ) Ivestis(studentai, m); // ***** Reading from a file
    else if (pasirinkimas == 2) Ivestis2(studentai, m); // Reading from user input
    else if (pasirinkimas == 3) Ivestis3(studentai, m); // Generating random number of random grades for random number of students
    else {
        cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
        cin >> pasirinkimas;
    }

    Isvestis(studentai, m);
    return 0;
}

void Isvestis(Studentas studentai[], int m){
    cout << endl << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
        << "Galutinis (Vid.)"<< "/ Galutinis (Med.)\n" << string(70, '-') << endl;

    for(int i=0; i<m; i++){
        cout << setw(17) << left << studentai[i].pavarde << setw(17) << studentai[i].vardas 
            << setw(17) << fixed << setprecision(2) << studentai[i].vidurkis << studentai[i].mediana << endl;
    }
}

void Ivestis3(Studentas studentai[], int &m){

    // Generates random number between 100 and 10'000
    srand(time(nullptr));
    m = rand() % 9901 + 100;

    // array for holding grades of every student
    int sk[25];

    for(int i=0; i<m; i++){

        float pazymiu_suma = 0;

        // generates between 2 and 20 random numbers (of values between 1 and 10)
        // last number in an array is grade for exam
        int n = rand() % 19 + 2;
        for(int j=0; j<=n; j++){
            sk[j] = rand() % 10 + 1;
            pazymiu_suma += sk[j];
        }

        pazymiu_suma -= sk[n]; // atimam egzamino rezultato verte

        float mediana = RastiMediana(sk, n);

        studentai[i].vardas = "Vardas" + to_string(i);
        studentai[i].pavarde = "Pavarde" + to_string(i);
        studentai[i].vidurkis = (pazymiu_suma/(n-1) * 0.4) + (sk[n] * 0.6);
        studentai[i].mediana = mediana;
    }
}


void Ivestis2(Studentas studentai[], int &m){

    string vardas, pavarde;
    int sk[100], egz_rez;

    cout << "Iveskite varda: ";
    while(cin >> vardas){

        float pazymiu_suma = 0;
        cout << "Iveskite pavarde: ";
        cin >> pavarde;
        cout << "Iveskite visus pazymius (paskutnis pazymys yra egzamino rezultatas). Surase visus pazymius iveskite: 11 ir spauskite enter: ";

        int n=0;
        while (n < 100 && cin >> sk[n]) {
            if(sk[n] == 11) break;
            pazymiu_suma += sk[n];
            n++;
        }

        pazymiu_suma -= sk[n-1]; // atimam egzamino rezultato verte, nes paskutine verte yra egzamino rezultatas
        
        float mediana = RastiMediana(sk, n);

        studentai[m].vardas = vardas;
        studentai[m].pavarde = pavarde;
        studentai[m].vidurkis = (pazymiu_suma/(n-1) * 0.4) + (sk[n-1] * 0.6);
        studentai[m].mediana = mediana;

        m++;

        cout << "Iveskite varda arba nutraukite (ctrl+Z ir Entetr): ";
    }
}

void Ivestis(Studentas studentai[], int &m){

    // Count n and m
    ifstream infile_count(INFILENAME);
    string s;
    getline(infile_count, s);
    int  n = CountN(s);
    while(getline(infile_count, s)) m++;
    //infile.close();

    ifstream infile(INFILENAME);
    string vardas, pavarde;
    int sk[30], egz_rez;
    getline(infile, vardas);

    for(int i=0; i<m; i++){
        float pazymiu_suma = 0;

        // Nuskaitom ir apskaiciuojam vidurki
        infile >> vardas >> pavarde;
        for(int j=0; j<n; j++){
            infile >> sk[j];
            pazymiu_suma += sk[j];
        }
        infile >> sk[n];

        float mediana = RastiMediana(sk, n);

        studentai[i].vardas = vardas;
        studentai[i].pavarde = pavarde;
        studentai[i].vidurkis = (pazymiu_suma/n * 0.4) +(sk[n] * 0.6);
        studentai[i].mediana = mediana;
    }
}

float RastiMediana(int arr[], int n){

    // Isrikiuojam didejimo tvarka, kad galetume rasti mediana
    for(int j=0; j<n; j++){
        for(int z=j+1; z<n+1; z++)
        {
            if(arr[j]>arr[z]) swap(arr[j], arr[z]);
        }
    }

    if( (n+1) %2 == 0 ) return (arr[n/2] + arr[n/2+1])/2.0;
    else return arr[n/2];
}


int CountN(string line){

    stringstream s (line);

    string word;
    int count = 0;
    while (s >> word)
        count++;

    return count-3;
}