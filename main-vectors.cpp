#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
};

int CountN(string line);
float RastiMediana(int arr[], int n);
int GetIntInput();

void Ivestis(vector<Studentas> &studentai);
void Ivestis2(vector<Studentas> &studentai);
void Ivestis3(vector<Studentas> &studentai);
void Isvestis(vector<Studentas> &studentai);


const string INFILENAME = "studentai10000.txt";

int main(){
    int m = 0;

    vector<Studentas> studentai;

    cout << "Pasirinkite ka noresite daryti:\na) skaityti pazymius is failo (rasykite 1)\nb) patys ivesite varda pavarde ir pazymius (rasykite 2)\nc) programa sugeneruos atsitiktini kieki atsitiktiniu pazymiu atsitiktiniam kiekiui studentu (rasykite 3): ";
    
    while (true){
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
        else cout << "Tokio pasirinkimo nera. Iveskite is naujo: ";
    }

    Isvestis(studentai);
    return 0;
}

void Isvestis(vector<Studentas> &studentai){
    cout << endl << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
        << "Galutinis (Vid.)"<< "/ Galutinis (Med.)\n" << string(70, '-') << endl;

    for(int i=0; i<studentai.size(); i++){
        cout << setw(17) << left << studentai[i].pavarde << setw(17) << studentai[i].vardas 
            << setw(17) << fixed << setprecision(2) << studentai[i].vidurkis << studentai[i].mediana << endl;
    }
}

int GetIntInput(){
    int num;
    string input;

    while (true) {
        cin >> input;

        try {
            num = stoi(input);
            break;
        } catch (invalid_argument const &e) {
            cout << "Ivedete ne skaiciu arba neteisinga skaiciu. Bandykite dar karta." << endl;
        }
    }
    return num;
}

void Ivestis3(vector<Studentas> &studentai){

    // Generates random number between 100 and 10'000
    srand(time(nullptr));
    int m = rand() % 9901 + 100;

    // array for holding grades of every student
    int sk[100];

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
        Studentas studentas{
            ("Vardas" + to_string(i)),
            ("Pavarde" + to_string(i)),
            ((pazymiu_suma/(n) * 0.4) + (sk[n] * 0.6)),
            mediana
        };

        if(studentas.vidurkis > 10){
                string x;
                cout << "\nFOUND IT: " << pazymiu_suma << " " << studentas.vidurkis << "\n";
                cout << sk[n] << " " << n <<  endl;
                cin >> x;
            for(int za=0; za<=n; za++){
                cout << sk[za] << " ";
            }
            cout << "\n";
            cin >> x;
        }

        studentai.push_back(studentas);
    }
}


void Ivestis2(vector<Studentas> &studentai){

    string vardas, pavarde;
    int sk[100], m;

    cout << "Iveskite varda: ";
    while(cin >> vardas){

        float pazymiu_suma = 0;
        cout << "Iveskite pavarde: ";
        cin >> pavarde;
        cout << "Iveskite visus pazymius (paskutnis pazymys yra egzamino rezultatas). Surase visus pazymius iveskite 11 ir spauskite enter:\n";

        int n=0;
        while (n < 100)
        {
            while(true){
                sk[n] = GetIntInput();
                if(sk[n] > 0 && sk[n] <= 11) break;
                cout << "Tokio pazymio ivesti negalima. Bandykite is naujo:\n"; 
            }
            
            if(sk[n] == 11) break;

            pazymiu_suma += sk[n];
            n++;
        }

        pazymiu_suma -= sk[n-1]; // atimam egzamino rezultato verte, nes paskutine verte yra egzamino rezultatas
        
        float mediana = RastiMediana(sk, n);

        Studentas studentas{
            ("Vardas" + to_string(m)),
            ("Pavarde" + to_string(m)),
            ((pazymiu_suma/n * 0.4) + (sk[n] * 0.6)),
            mediana
        };

        studentai.push_back(studentas);

        m++;

        cout << "Iveskite varda arba nutraukite (ctrl+Z ir Entetr): ";
    }
}

void Ivestis(vector<Studentas> &studentai){

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

        Studentas studentas{
            ("Vardas" + to_string(i)),
            ("Pavarde" + to_string(i)),
            ((pazymiu_suma/n * 0.4) + (sk[n] * 0.6)),
            mediana
        };

        studentai.push_back(studentas);
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