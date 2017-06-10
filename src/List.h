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
    int getQuantity();
    void Insert(string Type, string Name, int Life, int Strength, int Sanity, int Hability);
    void Insert(Card* new_card);
    void PrintList();
    Card* SearchCard(int indice);
    void RemoveCard(int indice);
    int Attack(int target, int damage);
    void BossTremmor(int damage);
    int MagePassive();
    int RangerPassive();
    int BossPassive();
    void ReduceCds();
};

#endif