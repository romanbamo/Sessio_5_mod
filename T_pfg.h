#ifndef T_PGF_H
#define T_PGF_H
#include<iostream>
#include <fstream>
#include <string>
#include"Tutor.h"
#include"Pfg.h"

using namespace std;

class T_pfg
{
private:
	Pfg a_tPfg[1000];
	int a_n;

public:
	//constructors
	T_pfg();
	Pfg pfg(const int& pos);
	//modificadors
	void inserir(Pfg p);
	void eliminar(string codi);
	void puntuar_t(int pos, int nota);
	void ordena(int criteri);
	//consultors
	int cerca_dic(string codi);
	void mostrar();
	bool cerca_codi(const string& codi);
	int setN();
	
};
#endif //T_PFG_H


