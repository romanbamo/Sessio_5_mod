#include<iostream>
#include<fstream>
#include"Pfg.h"
#include"Tutor.h"
#include"T_pfg.h"
#include"T_tutor.h"

using namespace std;

void obrir_fitxer(ifstream& f_in) {
    string nom;
    cout << "NOM DEL FITXER:" << endl;
    cin >> nom;
    f_in.open(nom);
    while (!f_in.is_open()) {
        cout << "NOM DEL FITXER:" << endl;
        cin >> nom;
        f_in.open(nom);
    }
}

void llegir_fitxer(ifstream& f_in, T_tutor& t_t) {
    Tutor t;
    while (f_in.eof()) {
        t.llegir_tutor(f_in);
        if (!t.setCodi().empty()) t_t.inserir(t);
    }

}

string llegir_codi() {
    cout << "Codi de l'alumne:" << endl;
    string codi;
    cin >> codi;
    return codi;
}

void alta_pfg(T_pfg& t_p, T_tutor& t_t) {
    string codi = llegir_codi();
    if (not t_p.cerca_codi(codi)) {
        Pfg p;
        p.llegir_pfg(codi);
        cout << "Te tutor(s / n) :" << endl;
        char c;
        cin >> c;
        if (c == 's') {
            cout << "Codi tutor:" << endl;
            string codi_t;
            cin >> codi_t;
            if (t_t.cerca_codi(codi_t)) {
                p.assignar_tutor(codi_t);
                t_t.sumar_n_curs_t(codi_t);
                t_p.inserir(p);
                cout << "Nou PFG: ";
                t_p.mostrar();
            }
        }
    }
    else cout << "Codi existent" << endl;
}

void baixa_pfg(T_pfg& t_p, T_tutor& t_t) {
    string codi = llegir_codi();
    if (t_p.cerca_codi(codi)) {
        int pos=t_p.cerca_dic(codi);
        Tutor t=t_t.tutor(pos);
        t_t.restar_n_curs_t(t.setCodi());
        t_p.eliminar(codi);
    }
    else cout << "Codi inexistent" << endl;
}

void puntuar_pfg(T_pfg& t_p, T_tutor& t_t) {
    string codi = llegir_codi();
    if (t_p.cerca_codi(codi)) {
        int pos = t_p.cerca_dic(codi);
        cout << "Nota obtinguda a la defensa:" << endl;
        int nota;
        cin >> nota;
        t_p.puntuar_t(pos, nota);
        Tutor t = t_t.tutor(pos);
        t_t.restar_n_curs_t(t.setCodi());
        t_t.sumar_n_def_t(t.setCodi());
    }
    else cout << "Codi inexistent" << endl;
}

void completar_pfg(T_pfg& en_curs, T_pfg& completats) {
    for (int i = 0; i < en_curs.setN(); i++) {
        Pfg p = en_curs.pfg(i);
        if (p.setNota() >= 0) {
            completats.inserir(p);
            en_curs.eliminar(p.setCodi());
        }
    }
    cout << "S'han completat els projectes defensats" << endl;
    completats.mostrar();
}

void mostrar_pfg(T_pfg en_curs) {
    T_pfg titol;
    cout << "ESPECIALITAT:" << endl;
    string especialitat;
    getline(cin, especialitat);
    for (int i = 0; i < en_curs.setN(); i++) {
        Pfg p = en_curs.pfg(i);
        if (p.setEspecialitat() == especialitat) {
            titol.inserir(p);
        }
    }
    titol.ordena(1);
    titol.mostrar();
}

void mostrar_menu() {
    cout << "OPCIONS:" << endl << "A: ALTA PFG" << endl << "B : BAIXA PFG" << endl << "P : PUNTUAR PFG" << endl << "C : COMPLETAR PFG" << endl << "L : MOSTRAR PFGs EN CURS D'UNA ESPECIALITAT" << endl << "T : MOSTRAR TUTORS" << endl << "H : MOSTRAR EL MENU" << endl << "S : FI DEL PROGRAMA" << endl;
}

char escollir_opcio() {
    char c;
    cout << "-- OPCIO:" << endl;
    cin >> c;
    return c;
}

int main()
{
    ifstream f_in;
    T_tutor tutors;
    T_pfg en_curs, completats;
    char c;
    obrir_fitxer(f_in);
    if (f_in.is_open()) {
        llegir_fitxer(f_in, tutors);
        mostrar_menu();
        c = escollir_opcio();
        while (c != 'S') {
            if (c == 'A')alta_pfg(en_curs, tutors);
            else if (c == 'B')baixa_pfg(en_curs, tutors);
            else if (c == 'P')puntuar_pfg(en_curs, tutors);
            else if (c == 'C')completar_pfg(en_curs, completats);
            else if (c == 'L')mostrar_pfg(en_curs);
            else if (c == 'T')tutors.mostrar();
            else if (c == 'H')mostrar_menu();
            cout << endl;
            c = escollir_opcio();
        }
    }
    else cout << "FITXER NO TROBAT";

    return 0;
}