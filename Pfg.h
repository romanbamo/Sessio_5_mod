#ifndef PFG_H
#define PFG_H

#include<iostream>
#include <fstream>
#include <string>
#include"Tutor.h"

using namespace std;

class Pfg {
private:
    string a_codi_a;
    string a_nom;
    string a_titol;
    string a_especialitat;
    string a_codi_t;
    int a_nota;

public:
    //constructors
    Pfg();
    Pfg(string codi_a, string nom, string titol, string especialitat, string codi_t, int nota=-1);
    //consultors
    void mostrar();
    string setCodi();
    int setNota();
    string setEspecialitat();
    string setTitol();
    bool operator < (const Pfg& b) const;
    bool operator <= (const Pfg& b) const;
    bool operator > (const Pfg& b) const;
    bool operator >= (const Pfg& b) const;
    bool operator == (const Pfg& b) const;
    bool operator != (const Pfg& b) const;
    //modificadors
    void llegir_pfg(const string& codi);

    void puntuar(const int& nota);

    void assignar_tutor(string tutor);

};
#endif //PFG_H
