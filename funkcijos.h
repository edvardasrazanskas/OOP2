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

const char* INFILENAME = "failai/sugeneruoti/studentai1000000.txt";

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

template<typename T>
void Isvestis(T& studentai);

// Generates randomly
void Ivestis3(vector<Studentas> &studentai);
// Gets from user input
void Ivestis2(vector<Studentas> &studentai);

template <typename T>
void Ivestis(T &studentai, int tipas);

#endif