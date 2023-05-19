#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector.h>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>

using std::vector;

/**
 * \brief Klasė Zmogus yra abstrakti klasė, kuri aprašo funkcijas, kurias privalo turėti jos child klasės.
*/

class Zmogus{
// realizacija
protected:
    std::string vardas_;
    std::string pavarde_;
public:
    Zmogus(std::string vardas = "", std::string pavarde = "") : vardas_{vardas}, pavarde_{pavarde} {}
    virtual inline std::string vardas() const = 0;
    virtual inline std::string pavarde() const = 0;
    virtual ~Zmogus() = default;
};

/**
 * \brief Ši klasė aprašo Studentą.
*/
class Studentas:public Zmogus{
// realizacija
private:
  double vidurkis_;
  double mediana_;

// interfeisas
public:
    // Rule of five
    Studentas() = default;
    /**
     * \brief Studento klasės kontruktorius
     * \param[in] vardas Studento vardas
     * \param[in] pavarde Studento pavardė
     * \param[in] vidurkis Studento pažymių vidurkis
     * \param[in] mediana Studento pažymių mediana
    */
    Studentas(std::string vardas="", std::string pavarde= "", double vidurkis=0, double mediana=0)
    : Zmogus{vardas, pavarde}, vidurkis_{vidurkis}, mediana_{mediana} {}

    Studentas(const Studentas& s) = default;
    Studentas& operator=(const Studentas& s) = default;
    ~Studentas() = default;

    // Overriding vardas() and pavarde() from Zmogus
    /**
     * \brief Studento vardas
     * \return Gražina studento vardą
    */
    inline std::string vardas() const { return vardas_; }    // get'eriai, inline
    /**
     * \brief Studento pavardė
     * \return Gražina studento pavardę
    */
    inline std::string pavarde() const { return pavarde_; }  // get'eriai, inline
    
    /**
     * \brief Studento pažymių vidurkis
     * \return Gražina pažymių studento vidurkį
    */
    inline double vidurkis() const { return vidurkis_; }    // get'eriai, inline
    /**
     * \brief Studento pažymių mediana
     * \return Gražina studento pažymių mediana
    */
    inline double mediana() const { return mediana_; }       // get'eriai, inline

    // Overloading << operator
    friend std::ostream& operator<< (std::ostream& out, const Studentas& point);

};

/**
 * \brief Išrikiuoja Studentų vektorių pagal vardą
*/
void sortVector(vector<Studentas>& studentai);
/**
 * \brief Funkcija, patikrinanti ar vartotojas teisingai įveda skaičius
*/
int GetIntInput();

/**
 * \brief Pagalbinė funkcija
*/
int CountN(std::string line);

// Generates randomly
/**
 * \brief Funkcija, automatiškai sugeneruojanti atsitiktinį kiekį studentų su atsitiktiniais pažymiais
*/
void Ivestis3(vector<Studentas> &studentai);

// Gets from user input
/**
 * \brief Funkcija, leidžianti vartotojui įvesti studentų vardą, pavardę ir turimus pažymius
*/
void Ivestis2(vector<Studentas> &studentai);

// Reads from file
/**
 * \brief Funkcija, skaitanti informaciją apie studentus iš failų
*/
void Ivestis(vector<Studentas> &studentai, int &kiekis);

#endif