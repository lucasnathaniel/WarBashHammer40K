/**
  *@file List.h
  *@class List 
  *@brief Arquivo com as declaracoes das funcoes da List
  */

#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
#include <fstream>
#include "Card.h"
#include <string>
#include <vector>

using namespace std;

class List{
	private:
		int Quantity;
		Card* First;
	public:
		List();
    	~List();
    	Card* getFirst();
    	void InsertBegin(string Name, int Life, int Strength, int Sanity, int Hability, int Especial);
    	void InsertEnd(string Name, int Life, int Strength, int Sanity, int Hability, int Especial);
};

void separar(string& str, char delim, vector<string>& pedacos);

#endif