#pragma once

#include "headers.h"
#include "Studentas.h"
#include "Vector.h"

//----------------------------------------------------------------Skaiciavimai
double vidurkis(Vector<int> p, int egz);
double mediana(Vector<int> p, int egz);

//----------------------------------------------------------------Apsaugos
int genrand();
int sveikojoApsauga(int& a);
char charApsauga(char& a);
char konteinerioApsauga(char& a);

//----------------------------------------------------------------Rikiavimai
bool rikiuotiPazymi(Studentas& a, Studentas& b);
bool rikiuotiVarda(Studentas& a, Studentas& b);

//----------------------------------------------------------------Su failais
void automatinisGen();
void automatinisBeGen();

inline bool egzistuojaFailas(string& fname);
void generuotifailus(string& failopavadinimas, int kiek, int nd);
void skaitymas(Vector<Studentas>& s, string fname);
void paskirstymas(Vector<Studentas>& s, Vector<Studentas>& Kieti, Vector<Studentas>& Vargsai, char vm, char stratType);
void rasymas(Vector<Studentas>& s, string fname, char vm);
void buffFaila(string fname, std::stringstream& buffer);

//----------------------------------------------------------------Ranka
void Ranka();
void skaitymasRanka(data& st);
void rasymasRanka(data& st, char vm);
void pridetiRanka(data& st, int& it, int& kiek);
void skaiciavimai(Vector<data>& st, char vm);
void antraste(char vm);



#pragma once
#include "headers.h"
#include "Studentas.h"

//----------------------------------------------------------------Skaiciavimai
double vidurkis(Vector<int> p, int egz);
double mediana(Vector<int> p, int egz);

//----------------------------------------------------------------Apsaugos
int genrand();
int sveikojoApsauga(int& a);
char charApsauga(char& a);
char konteinerioApsauga(char& a);

//----------------------------------------------------------------Rikiavimai
bool rikiuotiPazymi(Studentas& a, Studentas& b);
bool rikiuotiVarda(Studentas& a, Studentas& b);

//----------------------------------------------------------------Su failais
void automatinisGen();
void automatinisBeGen();

inline bool egzistuojaFailas(string& fname);
void generuotifailus(string& failopavadinimas, int kiek, int nd);
void skaitymas(Vector<Studentas>& s, string fname);
void paskirstymas(Vector<Studentas>& s, Vector<Studentas>& Kieti, Vector<Studentas>& Vargsai, char vm, char stratType);
void rasymas(Vector<Studentas>& s, string fname, char vm);
void buffFaila(string fname, std::stringstream& buffer);

//----------------------------------------------------------------Ranka
void Ranka();
void skaitymasRanka(data& st);
void rasymasRanka(data& st, char vm);
void pridetiRanka(data& st, int& it, int& kiek);
void skaiciavimai(Vector<data>& st, char vm);
void antraste(char vm);



