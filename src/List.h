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
		/**
  		  *@brief Construtor
  		  */
		List();
    	/**
  		  *@brief Destrutor
  		  */
    	~List();
    	/**
  		  *@brief getter First elemento da lista
  		  *@return primeiro elemento da lista
  		  */
    	Card* getFirst();
    	/**
  		  *@brief getter Quantidade de elementos da lista
  		  *@return quantidade de elementos da lista
  		  */
    	int getQuantity();
    	/**
  		  *@brief insere um elemento no final da lista atraves dos parametros
  		  *@param Type tipo da classe da carta
  		  *@param Name nome da classe da carta
  		  *@param Life vida da classe da carta
  		  *@param Strength força da classe da carta
  		  *@param Sanity sanidade da classe da carta
  		  *@param Hability habilidade especial da classe da carta
  		  */
    	void Insert(string Type, string Name, int Life, int Strength, int Sanity, int Hability);
    	/**
  		  *@brief insere um elemento no final da lista atraves de carta passada por parametro
  		  *@param new_card carta para ser inserida na lista
  		  */
    	void Insert(Card* new_card);
    	/**
  		  *@brief Escreve a lista na tela
  		  */
    	void PrintList();
    	/**
  		  *@brief Busca uma carta na lista
  		  *@param indice indice passado para percorrer a lista
  		  *@return retornar a carta achada
  		  */
    	Card* SearchCard(int indice);
    	/**
  		  *@brief Remove uma carta na lista
  		  *@param indice indice passado para percorrer a lista
  		  */
    	void RemoveCard(int indice);
    	/**
  		  *@brief Seleciona um alvo para dar dano, caso o alvo morra, retorna o elemento
  		  *@param target elemento para ser atacado
  		  *@param damage dano para ser desferido
  		  *@return retorna se o alvo morreu ou nao
  		  */
    	int Attack(int target, int damage);
    	/**
  		  *@brief Habilidade ativa do Boss
  		  *@param damage dano para ser desferido
  		  *@return retorna os elementos que foram mortos
  		  */
    	vector<int> BossTremmor(int damage);
    	/**
  		  *@brief Passiva do ranger
  		  *@return retorna a soma do dano de todos os rangers de um campo
  		  */
    	int RangerPassive();
    	/**
  		  *@brief Verifica se ha medicos na lista
  		  *@return retorna a soma da cura de todos os medicos da lista
  		  */
    	int MedicPassive();
    	/**
  		  *@brief continuacao da passiva do medico, percorre a lista e adiciona a cura
  		  *@param cura para ser adicionada
  		  */
    	void MedicSunshine(int medic_cure);
    	/**
  		  *@brief Habilidade passiva do mago, verifica se ha magos na lista e retorna o dano
  		  *@return retorna o dano referido aos magos do lado oposto
  		  */
    	int MagePassive();
    	/**
  		  *@brief continuacao da passiva do mago
  		  *@param damage dano para ser desferido
  		  *@return retorna os elementos que foram mortos
  		  */
    	vector<int> MageSpell(int mage_damage);
    	/**
  		  *@brief Passiva do Boss
  		  *@return retorna o dano adicional caso haja algum boss
  		  */
    	int BossPassive();
    	/**
  		  *@brief Diminui os cooldowns das cartas
  		  */
    	void ReduceCds();
};

#endif