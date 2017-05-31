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
  *@brief insere um elemento no comeco da lista
  */
void List::InsertBegin(string Name, int Life, int Strength, int Sanity, int Hability, string type, int Especial){
    if(type == "Boss"){

    }else if(type == "Infantary"){
    	Card* new_card = new Infantary(Name, Life, Strength, Sanity, Hability, Especial);
    }else if(type == "Mage"){

    }else if(type == "Tech"){

    }else if(type == "Tank"){

    }else if(type == "Medic"){

    }else if(type == "Ranger"){

    }else{
    	cout << "Unidef type, exit!" << endl;
    	exit(0);
    }
    novo->setNext(First);
    First = novo;
    this->Quantity++;
}
/**
  *@brief insere um elemento no final da lista
  */
void List::InsertEnd(string Name, int Life, int Strength, int Sanity, int Hability, int Especial){
    
    if(First == NULL){
		InsertBegin(Name, Life, Strength, Sanity, Hability, Especial);
		return;
	}
    
    Card* novo = new Card(Name, Life, Strength, Sanity, Hability, Especial);
    Card* percorre = First;
    
    while(percorre->getNext() != NULL){
    	percorre = percorre->getNext();
    }
    percorre->setNext(novo);
    this->Quantity++;
}
/**
  *@brief Separador de string em substrings
  */
void separar(string& str, char delim, vector<string>& pedacos) {
    string::size_type i = 0;
    string::size_type j = str.find(delim);

    while (j != string::npos) {
        pedacos.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(delim, j);

        if (j == string::npos)
            pedacos.push_back(str.substr(i, str.length()));
    }
}