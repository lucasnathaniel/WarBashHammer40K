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
/**
  *@brief Interface super legal e bacana que vai me garantir um 10 no projeto
  */
void Interface();
/**
  *@brief Menu do StartGame, para escolher as raças para serem jogadas
  */
void StartGame();
/**
  *@brief Função de leitura das raças
  *@param address endereço para ser lido
  *@return Retorna a lista da raça que foi lida
  */
List* ReadRace(string address);
/**
  *@brief Separador de strings em substrings
  *@param str string para ser dividida
  *@param delim char que irá dividir a string
  *@param pieces vetor para receber as substrings
  */
void part(string& str, char delim, vector<string>& pedacos);
/**
  *@brief Principal função do jogo
  Aqui ocorre toda a jogabilidade do game, qualquer duvida, mande um e-mail para: lucasnataniel@hotmail.com
  *@param your_list sua lista
  *@param enemy_list lista inimiga
  */
void Playing(List* your_list, List* enemy_list);
/**
  *@brief Mini-interface para organizar o jogo
  *@param your_list sua lista
  *@param your_cards_on_fiel suas cartas que estão no campo
  *@param enemy_cards_on_fiel cartas do inimigo que estão no campo
  */
void GameInterface(List* your_list, List* your_cards_on_field, List* enemy_cards_on_field);
/**
  *@brief A função coloca sua carta no campo
  *@param your_list sua lista
  *@param your_cards_on_fiel suas cartas que estão no campo
  *@param put_card carta para ser colocada
  *@return retorna a lista atualizada
  */
List* PutACardOnField(List* the_list, List* the_list_on_field, Card* put_card);
/**
  *@brief Função para selecionar a cor de uma classe
  *@param classe classe
  */
void PrintColor(string classe);
/**
  *@brief Tutorial
  */
void Tutorial();
/**
  *@brief Tabela de classes
  */
void ClassTable();
/**
  *@brief Sobre as classes
  */
void AboutRaces();


#endif