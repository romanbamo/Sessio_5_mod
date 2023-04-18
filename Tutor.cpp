#include "Tutor.h"
#include <limits>

using namespace std;


Tutor::Tutor() {
    a_codi =" ";
    a_nom = " ";
    a_especialitat= " ";
    a_n_curs=0;
    a_n_def=0;
}
Tutor::Tutor(string codi, string nom, string especialitat) {
    a_codi = codi;
    a_nom = nom;
    a_especialitat = especialitat;
    a_n_curs = 0;
    a_n_def = 0;
}
void Tutor::mostrar() {
    cout << a_nom << " (" << a_codi << "), " << a_especialitat << "[" << a_n_curs << ":" << a_n_def << "]" << endl;
}
string Tutor::setCodi() {
    return a_codi;
}

bool Tutor::operator < (const Tutor& b) const {
    return this->a_codi < b.a_codi;
}
bool Tutor::operator <= (const Tutor& b) const {
    return this->a_codi <= b.a_codi;
}
bool Tutor::operator > (const Tutor& b) const {
    return this->a_codi > b.a_codi;
}
bool Tutor::operator >= (const Tutor& b) const {
    return this->a_codi >= b.a_codi;
}
bool Tutor::operator == (const Tutor& b) const {
    return this->a_codi == b.a_codi;
}
bool Tutor::operator != (const Tutor& b) const {
    return this->a_codi != b.a_codi;
}
//modificadors

void Tutor::llegir_tutor(ifstream& f_in) {
    if (not f_in.eof()) {
        getline(f_in, a_codi);
        getline(f_in, a_nom);
        getline(f_in, a_especialitat);
        a_n_curs = 0;
        a_n_def = 0;
    }
}

void Tutor::sumar_n_curs() {
    a_n_curs++;
}
void Tutor::restar_n_curs() {
    a_n_curs--;
}
void Tutor::sumar_n_def() {
    a_n_def++;
}
void Tutor::restar_n_def() {
    a_n_def--;
}
