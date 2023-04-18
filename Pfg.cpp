#include "Pfg.h"


using namespace std;

//constructors
Pfg::Pfg() {
    a_codi_a = " ";
    a_nom = " ";
    a_titol = " ";
    a_especialitat = " ";
    a_codi_t = " ";
    a_nota = -1;
}
Pfg::Pfg(string codi_a, string nom, string titol, string especialitat, string codi_t, int nota ) {
    a_codi_a = codi_a;
    a_nom = nom;
    a_titol = titol;
    a_especialitat = especialitat;
    a_codi_t = codi_t;
    a_nota = nota;
}
//consultors
void Pfg::mostrar() {
    cout << a_titol << " (" << a_especialitat << "), " << a_nom << " (" << a_codi_a << "), codi tutor: " << a_codi_t << endl;
}
string Pfg::setCodi() {
    return a_codi_a;
}
int Pfg::setNota() {
    return a_nota;
}
string Pfg::setEspecialitat() {
    return a_especialitat;
}
string Pfg::setTitol() {
    return a_titol;
}
bool Pfg::operator < (const Pfg& b) const {
    return this->a_codi_a < b.a_codi_a;
}
bool Pfg::operator <= (const Pfg& b) const {
    return this->a_codi_a <= b.a_codi_a;
}
bool Pfg::operator > (const Pfg& b) const {
    return this->a_codi_a > b.a_codi_a;
}
bool Pfg::operator >= (const Pfg& b) const {
    return this->a_codi_a >= b.a_codi_a;
}
bool Pfg::operator == (const Pfg& b) const {
    return this->a_codi_a == b.a_codi_a;
}
bool Pfg::operator != (const Pfg& b) const {
    return this->a_codi_a != b.a_codi_a;
}
//modificadors
void Pfg::llegir_pfg(const string& codi) {
    cout << "Cognoms, nom:" << endl;
    getline(cin, a_nom);
    cout << "Titol:" << endl;
    getline(cin, a_titol);
    cout << "Especialitat:" << endl;
    getline(cin, a_especialitat);
    a_codi_a = codi;
}
void Pfg::puntuar(const int& nota) {
    a_nota = nota;
}
void Pfg::assignar_tutor(string tutor) {
    a_codi_t = tutor;
}


