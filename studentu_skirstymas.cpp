#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
//#include <Timer.h>

using namespace std;

void IvestisIsvestis(int kiekis);


int main()
{
    /*
    for(int i=1000; i<=10000000; i*=10){
        Timer t;
        IvestisIsvestis(i);
        cout << "Failas su: " << i << " studentais buvo paskirstytas.\n";
        cout << i << " eiluciu failo perskirstymas i skirtingus failus uztruko: " << t.elapsed() << " s\n";
    }
*/

    system("pause");
    return 0;
}


void IvestisIsvestis(int kiekis)
{
    int galutinis_balas;
    float sk[16];
    string INFILENAME = "failai/sugeneruoti/studentai" + to_string(kiekis) + ".txt";
    string OUTFILENAME_5 = "failai/paskirstyti/nepasiseke" + to_string(kiekis) + ".txt";
    string OUTFILENAME_10 = "failai/paskirstyti/pasiseke" + to_string(kiekis) + ".txt";

    try{
        ifstream infile(INFILENAME);
        ofstream outfile5(OUTFILENAME_5);
        ofstream outfile10(OUTFILENAME_10);

        stringstream temp_ss;

        const int buf_size = 1024;
        char* buffer = new char[buf_size];
        outfile5.rdbuf()->pubsetbuf(buffer, buf_size);
        outfile10.rdbuf()->pubsetbuf(buffer, buf_size);


        outfile5 << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
                << "Galutinis (Vid.)\n" << string(70, '-') << endl;
        outfile10 << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
                << "Galutinis (Vid.)\n" << string(70, '-') << endl;

        string vardas, pavarde, eilute;
        getline(infile, eilute);

        vector<string> buffer5, buffer10;
        buffer5.reserve(kiekis / 2);
        buffer10.reserve(kiekis / 2);

        for(int i=0; i<kiekis; i++)
        {
            float pazymiu_suma = 0;

            // Nuskaitom ir apskaiciuojam vidurki
            getline(infile, eilute);
            stringstream eilute_stream(eilute);
            eilute_stream >> vardas >> pavarde;

            for(int j=0; j<15; j++){
                eilute_stream >> sk[j];
                pazymiu_suma += sk[j];
            }
            eilute_stream >> sk[15];

            galutinis_balas = (pazymiu_suma/15 * 0.4) + (sk[15] * 0.6);

            temp_ss << setw(17) << left << pavarde << setw(17) << vardas 
                << setw(17) << fixed << setprecision(2) << galutinis_balas;
            
            if(galutinis_balas < 5.0){
                buffer5.push_back(temp_ss.str());
            } else {
                buffer10.push_back(temp_ss.str());
            }

            temp_ss.str("");

            if (i % 1000 == 0) { // write to file every 1000 records
                for (auto& s : buffer5) {
                    outfile5.write(s.c_str(), s.size());
                    outfile5.write("\n", 1);
                }
                buffer5.clear();

                for (auto& s : buffer10) {
                    outfile10.write(s.c_str(), s.size());
                    outfile10.write("\n", 1);
                }
                buffer10.clear();
                cout << "1000 records written" << endl;
            }
        }
        // write remaining records to file
        for (auto& s : buffer5) {
            outfile5.write(s.c_str(), s.size());
            outfile5.write("\n", 1);
        }
        for (auto& s : buffer10) {
            outfile10.write(s.c_str(), s.size());
            outfile10.write("\n", 1);
        }

    } catch(std::exception const& e){
        cout << e.what() << endl;
    }
}


/*
int main()
{
    ifstream infile(INFILENAME);
    ofstream outfile(OUTFILENAME_10);

    outfile << endl << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
            << "Galutinis (Vid.)" << string(70, '-') << endl;
    outfile << endl << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
            << "Galutinis (Vid.)" << string(70, '-') << endl;

    string vardas, pavarde;

    vector<string> buffer5, buffer10;
    buffer5.reserve(kiekis / 2);
    buffer10.reserve(kiekis / 2);

    /////////////////////




    for(int i=0; i<kiekis; i++)
    {
        float pazymiu_suma = 0;
        float sk[16];
        infile >> vardas >> pavarde;
        for(int j=0; j<15; j++){
            infile >> sk[j];
            pazymiu_suma += sk[j];
        }
        infile >> sk[15];

        float galutinis_balas = (pazymiu_suma/15 * 0.4) + (sk[15] * 0.6);

        if(galutinis_balas < 5.0){
            buffer5.push_back(
                setw(17) << left << pavarde << setw(17) << vardas 
                << setw(17) << fixed << setprecision(2) << galutinis_balas
            );
        } else {
            buffer10.push_back(
                setw(17) << left << pavarde << setw(17) << vardas 
                << setw(17) << fixed << setprecision(2) << galutinis_balas
            );
        }

        if (i % 100 == 0) { // write to file every 100 records
            for (auto& s : buffer5) {
                outfile << s << endl;
            }
            buffer5.clear();

            for (auto& s : buffer10) {
                outfile << s << endl;
            }
            buffer10.clear();
        }
    }

    // write remaining records to file
    for (auto& s : buffer5) {
        outfile << s << endl;
    }
    for (auto& s : buffer10) {
        outfile << s << endl;
    }

    return 0;
}
*/