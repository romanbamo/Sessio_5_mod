#ifndef T_TUTOR_H
#define T_TUTOR_H
#include<iostream>
#include <fstream>
#include <string>
#include"Tutor.h"

using namespace std;


class T_tutor
{
private:
	Tutor a_tTutor[100];
	int a_n;

public:
	//constructors
	T_tutor();
	Tutor tutor(const int& pos);
	//modificadors
	void inserir(Tutor t);
	void sumar_n_curs_t(string codi);
	void restar_n_curs_t(string codi);
	void sumar_n_def_t(string codi);
	void restar_n_def_t(string codi);
	//consultors
	int cerca_dic(string codi);
	void mostrar();
	bool cerca_codi(const string& codi);
	

};
#endif //T_TUTOR_H
