#include "funkcijos.h"

bool compareStudentasByVardas(const Studentas& s1, const Studentas& s2) {
    return s1.vardas < s2.vardas;
}

void sortList(list<Studentas>& studentai) {
    studentai.sort(compareStudentasByVardas);
}

void sortDeque(deque<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compareStudentasByVardas);
}

void sortVector(vector<Studentas>& studentai) {
    sort(studentai.begin(), studentai.end(), compareStudentasByVardas);
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

template<typename T>
void Isvestis(T& studentai)
{
    std::cout << std::endl << std::setw(17) << std::left << "Pavardė" << std::setw(17) << "Vardas" << std::setw(17)
        << "Galutinis (Vid.)"<< "/ Galutinis (Med.)\n" << std::string(70, '-') << std::endl;

    for(const auto& s : studentai)
    {
        std::cout << std::setw(17) << std::left << s.pavarde << std::setw(17) << s.vardas
            << std::setw(17) << std::fixed << std::setprecision(2) << s.vidurkis << s.mediana << std::endl;
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

template <typename T>
void Ivestis(T &studentai, int tipas){
    cout << "Ivestis func works " << endl;
    // Open file for buffered reading
    ifstream infile_count(INFILENAME);
    if (!infile_count) {
        cout << "Failas negalejo buti atidarytas." << endl;
    } else{
        infile_count.rdbuf()->pubsetbuf(new char[1 << 20], 1 << 20); // Set buffer to 1 MB
        string s;
        getline(infile_count, s);
        int n = CountN(s);
        int m = 0;
        while (getline(infile_count, s)) m++;
        infile_count.close();

        ifstream infile(INFILENAME);
        //infile.rdbuf()->pubsetbuf(new char[1 << 20], 1 << 20); // Set buffer to 1 MB
        string vardas, pavarde;
        int sk[100];
        getline(infile, vardas);

        for (int i = 0; i < m; i++)
        {
            float pazymiu_suma = 0;

            // Nuskaitom ir apskaiciuojam vidurki
            infile >> vardas >> pavarde;
            for (int j = 0; j < n; j++) {
                infile >> sk[j];
                pazymiu_suma += sk[j];
            }
            infile >> sk[n];

            float mediana = RastiMediana(sk, n);

            Studentas studentas{
                vardas, pavarde,
                ((pazymiu_suma / n * 0.4) + (sk[n] * 0.6)),
                mediana
            };

            studentai.push_back(studentas);
        }
        infile.close();
    }
}