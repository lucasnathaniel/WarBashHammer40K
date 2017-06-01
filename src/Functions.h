/**
  *@file Functions.h
  *@brief Arquivo com as declaracoes das funcoes do arquivo Functions.cpp
  */

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"
#include "List.h"

void Interface();
void StartGame();
List* ReadRace(string address);
void part(string& str, char delim, vector<string>& pedacos);
void Tutorial();
void ClassTable();
void AboutRaces();


#endif