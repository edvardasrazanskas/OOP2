#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
};

int CountN(string line);
void Ivestis(Studentas studentai[], int n, int m);
void Isvestis(Studentas studentai[], int m);


const string INFILENAME = "studentai10000.txt";
const int ARR_SIZE = 10000;

int main(){

    // Count N and M
    ifstream infile(INFILENAME);
    string s;
    getline(infile, s);
    int  n = CountN(s);
    int m = 0;
    while(getline(infile, s)) m++;

    Studentas studentai[ARR_SIZE];
    Ivestis(studentai, n, m);
    //cout << studentai[0].vardas << " " << studentai[0].pavarde << " " << studentai[0].vidurkis << " " << studentai[0].mediana << endl;
    Isvestis(studentai, m);
    return 0;
}

void Isvestis(Studentas studentai[], int m){
    cout << endl;
    cout << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17) << "Galutinis (Vid.)" << "/ Galutinis (Med.)" << endl;
    cout << string(70, '-') << endl;

    for(int i=0; i<m; i++){
        cout << setw(17) << left << studentai[i].pavarde << setw(17) << studentai[i].vardas 
        << setw(17) << fixed << setprecision(2) << studentai[i].vidurkis << studentai[i].mediana << endl;


    }
}


void Ivestis(Studentas studentai[], int n, int m){
    ifstream infile(INFILENAME);
    string vardas, pavarde;
    int sk[30], egz_rez;
    getline(infile, vardas);

    for(int i=0; i<m; i++){
        float suma = 0;

        // Nuskaitom ir apskaiciuojam vidurki
        infile >> vardas >> pavarde;
        for(int j=0; j<n; j++){
            infile >> sk[j];
            suma += sk[j];
        }
        infile >> egz_rez;

        // Išrikiuojame didejimo tvarka, kad galėtume rasti mediana
        sk[n] = egz_rez;
        for(int j=0; j<n; j++){
            for(int z=j+1; z<n+1; z++)
            {
                if(sk[j]>sk[z]) swap(sk[j], sk[z]);
            }
        }

        // TESTAVIMUI
        /*
        if(i==0){
            for(int j=0; j<=n; j++){
                cout << sk[j] << endl;
            }
        }*/

        float mediana;
        if( (n+1) %2 == 0 ) mediana = (sk[n/2] + sk[n/2+1])/2.0;
        else mediana = sk[n/2];

        studentai[i].vardas = vardas;
        studentai[i].pavarde = pavarde;
        studentai[i].vidurkis = (suma/n * 0.4) +(egz_rez * 0.6);
        studentai[i].mediana = mediana;
    }
}


int CountN(string line){

    stringstream s (line);

    string word;
    int count = 0;
    while (s >> word)
        count++;

    return count-3;
}