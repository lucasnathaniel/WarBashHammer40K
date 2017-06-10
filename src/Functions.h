/**
  *@file Functions.h
  *@brief Arquivo com as declaracoes das funcoes do arquivo Functions.cpp
  */

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Card.h"
#include "List.h"

void Interface();
void StartGame();
List* ReadRace(string address);
void part(string& str, char delim, vector<string>& pedacos);
void Playing(List* your_list, List* enemy_list);
void GameInterface(List* your_list, List* your_cards_on_field, List* enemy_cards_on_field);
List* PutACardOnField(List* the_list, List* the_list_on_field, Card* put_card);
void PrintColor(string classe);
void Tutorial();
void ClassTable();
void AboutRaces();


#endif