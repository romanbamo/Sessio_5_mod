#include "T_pfg.h"


using namespace std;

T_pfg::T_pfg() {
    a_n = 0;
}

Pfg T_pfg::pfg(const int& pos) {
    return a_tPfg[pos];
}

int T_pfg::cerca_dic(string codi) {
    int esq = 0, dret = a_n - 1, mig;
    bool trobat = false;
    while (not trobat and esq <= dret) {
        mig = (esq + dret) / 2;
        if (this->a_tPfg[mig].setCodi() == codi) trobat = true;
        else if (this->a_tPfg[mig].setCodi() < codi) esq = mig + 1;
        else dret = mig - 1;
    }
    if (trobat) return mig;
    else return esq;
}
void T_pfg::inserir(Pfg p) {
    int pos = cerca_dic(p.setCodi());
    for (int i = a_n; i > pos; i--) {
        a_tPfg[i + 1] = a_tPfg[i];
    }
    a_tPfg[pos] = p;
    a_n++;
}

void T_pfg::eliminar(string codi) {
    int pos = cerca_dic(codi);
    for (int i = pos; i < a_n - 1; i++) {
        a_tPfg[i] = a_tPfg[i + 1];
    }
    a_n--;
}

void T_pfg::puntuar_t(int pos, int nota) {
    a_tPfg[pos].puntuar(nota);
}

void T_pfg::ordena(int criteri) {
    if (criteri == 1) {
        //titol
        for (int i = 0; i < a_n-1; i++) {
            int pos_min = i;
            for (int j = i + 1; j < a_n; j++)
                if (a_tPfg[pos_min].setTitol() > a_tPfg[j].setTitol())pos_min = j;
            a_tPfg[i] = a_tPfg[pos_min];
        }
    }
}
void T_pfg::mostrar() {
    for (int i = 0; i < a_n; i++) {
        a_tPfg[i].mostrar();
    }
}
int T_pfg::setN() {
    return a_n;
}

bool T_pfg::cerca_codi(const string& codi) {
    int i = 0;
    while (a_tPfg[i].setCodi() != codi and i < a_n)
        i++;
    return i < a_n;
}
