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
    	new_card = new Boss(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Infantary"){
    	new_card = new Infantary(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Mage"){
		  new_card = new Mage(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Tech"){
    	new_card = new Tech(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Tank"){
    	new_card = new Tank(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Medic"){
    	new_card = new Medic(Type, Name, Life, Strength, Sanity, Hability);
    }else if(Type == "Ranger"){
    	new_card = new Ranger(Type, Name, Life, Strength, Sanity, Hability);
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

void List::PrintList(){

    for(Card* card = First; card != NULL; card = card->getNext()){
      if(card->getType() == "Boss"){
        cout << "\033[95m";
      }else if(card->getType() == "Infantary"){
        cout << "\033[93m";
      }else if(card->getType() == "Mage"){
        cout << "\033[34m";
      }else if(card->getType() == "Tech"){
        cout << "\033[91m";
      }else if(card->getType() == "Tank"){
        cout << "\033[37m";
      }else if(card->getType() == "Medic"){
        cout << "\033[96m";
      }else if(card->getType() == "Ranger"){
        cout << "\033[92m";
      }
      cout << card->getType() << " " << card->getName() << " " << card->getLife() << " " << card->getStrength() << " " << card->getSanity() << " ";
    cout << "\033[0m" << endl;
    }
}