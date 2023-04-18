#include "T_tutor.h"


using namespace std;

T_tutor::T_tutor() {
	a_n = 0;
}
Tutor T_tutor::tutor(const int& pos) {
    return a_tTutor[pos];
}
int T_tutor::cerca_dic(string codi) {
    int esq = 0, dret = a_n - 1, mig;
    bool trobat = false;
    while (not trobat and esq <= dret) {
        mig = (esq + dret) / 2;
        if (this->a_tTutor[mig].setCodi() == codi) trobat = true;
        else if (this->a_tTutor[mig].setCodi() < codi) esq = mig + 1;
        else dret = mig - 1;
    }
    if (trobat) return mig;
    else return esq;
}
void T_tutor::mostrar() {
    for (int i = 0; i < a_n; i++) {
        a_tTutor[i].mostrar();
    }
}

bool T_tutor::cerca_codi(const string& codi) {
    int i = 0;
    while (a_tTutor[i].setCodi() != codi and i < a_n)
        i++;
    return i < a_n;
}

void T_tutor::inserir(Tutor t) {
    int pos = cerca_dic(t.setCodi());
    for (int i = a_n; i > pos; i--) {
        a_tTutor[i + 1] = a_tTutor[i];
    }
    a_tTutor[pos] = t;
    a_n++;
}

void T_tutor::sumar_n_curs_t(string codi) {
    int pos = cerca_dic(codi);
    a_tTutor[pos].sumar_n_curs();
}
void T_tutor::sumar_n_def_t(string codi) {
    int pos = cerca_dic(codi);
    a_tTutor[pos].sumar_n_def();
}
void T_tutor::restar_n_curs_t(string codi) {
    int pos = cerca_dic(codi);
    a_tTutor[pos].restar_n_curs();
}
void T_tutor::restar_n_def_t(string codi) {
    int pos = cerca_dic(codi);
    a_tTutor[pos].restar_n_def();
}
