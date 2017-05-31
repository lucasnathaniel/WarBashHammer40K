/**
  *@file List.cpp
  *@brief Arquivo com a implementação da lista
  *
  */

#include "List.h"
#include "Card.h"
/**
  *@brief Construtor
  */
List::List(){
    First = NULL;
    this->Quantity = 0;
}
/**
  *@brief Destrutor
  */
List::~List(){

}
/**
  *@brief retorna o primeiro elemento
  */
Card* List::getFirst(){
	return First;
}
/**
  *@brief insere um elemento no final da lista
  */
void List::Insert(string Type, string Name, int Life, int Strength, int Sanity, int Hability){
      Card* new_card;
    if(Type == "Boss"){
    	Boss* new_card = new Boss(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Infantary"){
    	Infantary* new_card = new Infantary(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Mage"){
		  Mage* new_card = new Mage(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Tech"){
    	Tech* new_card = new Tech(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Tank"){
    	Tank* new_card = new Tank(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Medic"){
    	Medic* new_card = new Medic(Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Ranger"){
    	Ranger* new_card = new Ranger(Name, Life, Strength, Sanity, Hability);
    }else{
    	cout << "Unidef type, exit!" << endl;
    	exit(0);
    }
    if(First == NULL){
		  new_card->setNext(First);
    	First = new_card;
    	this->Quantity++;
		return;
	}
    
    Card* percorre = First;
    
    while(percorre->getNext() != NULL){
    	percorre = percorre->getNext();
    }
    percorre->setNext(new_card);
    this->Quantity++;
}