#include "Timer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

#include <vector>
#include <deque>
#include <list>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    double galutinis_balas;
};

//c++ why does vector erase causes Unknown signal.

void IvestisIsvestis(int kiekis, int tipas);

int main()
{
    cout << "\n\n>>> Deque <<<\n\n";
    Timer t;
    for(int i=1000000; i<=10000000; i*=10){
        t.reset();
        IvestisIsvestis(i, 3);
        cout << "Failas su: " << i << " studentais buvo paskirstytas.\n";
        cout << i << " eiluciu failo perskirstymas i skirtingus failus uztruko: " << t.elapsed() << " s\n";
    }

    system("pause");
    return 0;
}


void IvestisIsvestis(int kiekis, int tipas)
{
    string INFILENAME = "failai/sugeneruoti/studentai" + to_string(kiekis) + ".txt";
    string OUTFILENAME_vargsiukai = "failai/2strategija/vargsiukai" + to_string(kiekis) + ".txt";
    string OUTFILENAME_kietiakai = "failai/2strategija/kietiakai" + to_string(kiekis) + ".txt";

    ifstream infile(INFILENAME);
    ofstream outfileV(OUTFILENAME_vargsiukai);
    ofstream outfileK(OUTFILENAME_kietiakai);

    //header'iai
    outfileV << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
                << "Galutinis (Vid.)\n" << string(70, '-') << endl;
    outfileK << setw(17) << left << "Pavardė" << setw(17) << "Vardas" << setw(17)
            << "Galutinis (Vid.)\n" << string(70, '-') << endl;


    Studentas studentas;
    string vardas, pavarde, eilute;
    double pazymiu_suma, sk[16];
    stringstream temp_ss;

    // header - nereikia
    getline(infile, eilute);

    if(tipas == 1){
        vector<Studentas> studentaiVector;
        studentaiVector.reserve(kiekis);

        vector<Studentas> studentaiVargsiukaiVector;
        studentaiVargsiukaiVector.reserve(kiekis);
        

        //nuskaitymas
        for(int i=0; i<kiekis; i++){
            getline(infile, eilute);
            stringstream eilute_stream(eilute);

            eilute_stream >> studentas.vardas >> studentas.pavarde;

            pazymiu_suma = 0;
            for(int j=0; j<15; j++){
                eilute_stream >> sk[j];
                pazymiu_suma += sk[j];
            }

            eilute_stream >> sk[15];

            studentas.galutinis_balas = (pazymiu_suma/15 * 0.4) + (sk[15] * 0.6);
            studentaiVector.push_back(studentas);
        }

        // idejimas i vargsiuku vecotor/list/deque ir istrynimas is bendro studentai masyvo

        for(int i=0; i<kiekis; i++){
            if(studentaiVector[i].galutinis_balas < 5.0){
                studentaiVargsiukaiVector.push_back(studentaiVector[i]);
                studentaiVector.erase(studentaiVector.begin() + i);
                kiekis--;
                i--;
            }
        }



        //rasymas
        for(auto it=studentaiVector.begin(); it != studentaiVector.end(); ++it) {
            temp_ss.str("");
            temp_ss << setw(17) << left << it->pavarde << setw(17) << it->vardas 
                << setw(17) << fixed << setprecision(2) << it->galutinis_balas << "\n";
            outfileK.write(temp_ss.str().c_str(), temp_ss.str().size());
        }

        for(auto it=studentaiVargsiukaiVector.begin(); it != studentaiVargsiukaiVector.end(); ++it) {
            temp_ss.str("");
            temp_ss << setw(17) << left << it->pavarde << setw(17) << it->vardas 
                << setw(17) << fixed << setprecision(2) << it->galutinis_balas << "\n";
            outfileV.write(temp_ss.str().c_str(), temp_ss.str().size());
        }

    }
    else if(tipas == 2){
        list<Studentas> studentaiList;
        list<Studentas> studentaiVargsiukaiList;


        for(int i=0; i<kiekis; i++){
            getline(infile, eilute);
            stringstream eilute_stream(eilute);

            eilute_stream >> studentas.vardas >> studentas.pavarde;

            pazymiu_suma = 0;
            for(int j=0; j<15; j++){
                eilute_stream >> sk[j];
                pazymiu_suma += sk[j];
            }

            eilute_stream >> sk[15];

            studentas.galutinis_balas = (pazymiu_suma/15 * 0.4) + (sk[15] * 0.6);
            studentaiList.push_back(studentas);
        }

        // idejimas i vargsiuku vecotor/list/deque ir istrynimas is bendro studentai masyvo
        for(auto it = studentaiList.begin(); it != studentaiList.end(); ) {
            if(it->galutinis_balas < 5.0) {
                studentaiVargsiukaiList.push_back(*it);
                it = studentaiList.erase(it);
            } else {
                ++it;
            }
        }

        //rasymas
        for(auto itr=studentaiList.begin(); itr != studentaiList.end(); ++itr) {
            temp_ss.str("");
            temp_ss << setw(17) << left << itr->pavarde << setw(17) << itr->vardas 
                << setw(17) << fixed << setprecision(2) << itr->galutinis_balas << "\n";
            outfileK.write(temp_ss.str().c_str(), temp_ss.str().size());
        }

        for(auto itr=studentaiVargsiukaiList.begin(); itr != studentaiVargsiukaiList.end(); ++itr) {
            temp_ss.str("");
            temp_ss << setw(17) << left << itr->pavarde << setw(17) << itr->vardas 
                << setw(17) << fixed << setprecision(2) << itr->galutinis_balas << "\n";
            outfileV.write(temp_ss.str().c_str(), temp_ss.str().size());
        }

    } else {
        deque<Studentas> studentaiDeque;
        studentaiDeque.resize(kiekis);

        deque<Studentas> studentaiVargsiukaiDeque;
        studentaiVargsiukaiDeque.resize(kiekis);

        for(int i=0; i<kiekis; i++){
            getline(infile, eilute);
            stringstream eilute_stream(eilute);

            eilute_stream >> studentas.vardas >> studentas.pavarde;

            pazymiu_suma = 0;
            for(int j=0; j<15; j++){
                eilute_stream >> sk[j];
                pazymiu_suma += sk[j];
            }

            eilute_stream >> sk[15];

            studentas.galutinis_balas = (pazymiu_suma/15 * 0.4) + (sk[15] * 0.6);
            studentaiDeque[i] = studentas;
        }

        // idejimas i vargsiuku vecotor/list/deque ir istrynimas is bendro studentai masyvo
        for(int i=0; i<kiekis; i++){
            if(studentaiDeque[i].galutinis_balas < 5.0){
                studentaiVargsiukaiDeque.push_back(studentaiDeque[i]);
                studentaiDeque.erase(studentaiDeque.begin() + i);
                kiekis--;
                i--;
            }
        }

        //rasymas
        for(auto itr=studentaiDeque.begin(); itr != studentaiDeque.end(); ++itr) {
            temp_ss.str("");
            temp_ss << setw(17) << left << itr->pavarde << setw(17) << itr->vardas 
                << setw(17) << fixed << setprecision(2) << itr->galutinis_balas << "\n";
            outfileK.write(temp_ss.str().c_str(), temp_ss.str().size());
        }

        for(auto itr=studentaiVargsiukaiDeque.begin(); itr != studentaiVargsiukaiDeque.end(); ++itr) {
            temp_ss.str("");
            temp_ss << setw(17) << left << itr->pavarde << setw(17) << itr->vardas 
                << setw(17) << fixed << setprecision(2) << itr->galutinis_balas << "\n";
            outfileV.write(temp_ss.str().c_str(), temp_ss.str().size());
        }
    }
}