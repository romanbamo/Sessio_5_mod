#ifndef TUTOR_H
#define TUTOR_H
#include<iostream>
#include <fstream>
#include <string>

using namespace std;

class Tutor {

private:
    string a_codi;
    string a_nom;
    string a_especialitat;
    int a_n_curs;
    int a_n_def;

public:
    //constructors
    Tutor();
    Tutor(string codi, string nom, string especialitat);
    //consultors
    void mostrar();
    string setCodi();
    bool operator < (const Tutor& b) const;
    bool operator <= (const Tutor& b) const;
    bool operator > (const Tutor& b) const;
    bool operator >= (const Tutor& b) const;
    bool operator == (const Tutor& b) const;
    bool operator != (const Tutor& b) const;

    //modificadors
    void llegir_tutor(ifstream& f_in);
    void sumar_n_curs();
    void restar_n_curs();
    void sumar_n_def();
    void restar_n_def();
};
#endif //TUTORS_H