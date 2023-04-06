#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct Studentas{
    string vardas;
    string pavarde;
    double vidurkis;
    double mediana;
};

bool compareStudentasByVardas(const Studentas& s1, const Studentas& s2);

void sortList(list<Studentas>& studentai);

void sortDeque(deque<Studentas>& studentai);

void sortVector(vector<Studentas>& studentai);


int GetIntInput();

float RastiMediana(int arr[], int n);

int CountN(string line);

template<typename T> void Isvestis(T& studentai);

// Generates randomly
void Ivestis3(vector<Studentas> &studentai);
// Gets from user input
void Ivestis2(vector<Studentas> &studentai);


void Ivestis(vector<Studentas> &studentai, int &kiekis);
void Ivestis(list<Studentas> &studentai, int &kiekis);
void Ivestis(deque<Studentas> &studentai, int &kiekis);

#endif