#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>


class Studentas {
// realizacija
private:
  std::string vardas_;
  std::string pavarde_;
  double vidurkis_;
  double mediana_;

// interfeisas
public:
    inline std::string vardas() const { return vardas_; }    // get'eriai, inline
    inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline
    inline double vidurkis() const { return vidurkis_; }    // get'eriai, inline
    inline double mediana() const { return mediana_; }       // get'eriai, inline

    // Rule of five
    Studentas() = default;
    Studentas(std::string vardas, std::string pavarde, double vidurkis, double mediana)
    : vardas_{vardas}, pavarde_{pavarde}, vidurkis_{vidurkis}, mediana_{mediana} {}

    Studentas(const Studentas& s) = default;
    Studentas& operator=(const Studentas& s) = default;
    ~Studentas() = default;

    // Overloading << operator
    friend std::ostream& operator<< (std::ostream& out, const Studentas& point);

};


void sortVector(std::vector<Studentas>& studentai);
int GetIntInput();
int CountN(std::string line);

// Generates randomly
void Ivestis3(std::vector<Studentas> &studentai);
// Gets from user input
void Ivestis2(std::vector<Studentas> &studentai);
// Reads from file
void Ivestis(std::vector<Studentas> &studentai, int &kiekis);

#endif