/**
  *@file Card.cpp
  *@brief funcao com a implementacao dos nós da lista
  */
#include "Card.h"
/**
  *@brief Construtor com parâmetros
  */
Card::Card(string name, int life, int strength, int sanity){
	this->setNext(NULL);
}
/**
  *@brief Destrutor
  */
Card::~Card(){

}
/**
  *@brief Construtor sem parâmetros
  */
Card::Card(){
	this->setNext(NULL);
}
/**
  *@brief Getter Next
  */
Card* Card::getNext(){
    return this->Next;
}
/**
  *@brief Setter Next
  */
void Card::setNext(Card* card){
    this->Next = card;
}
/**
  *@brief Interface Gráfica
  */
Boss::Boss(string name, int life, int strength, int sanity, int fury):
Card(name, life, strength, sanity),
Fury(fury)
{}
void Boss::setFury(int fury){
    this->Fury = fury;
}
int Boss::getFury(){
	return this->Fury;
}

Infantary::Infantary(string name, int life, int strength, int sanity, int determination):
Card(name, life, strength, sanity),
Determination(determination)
{}
void Infantary::setDetermination(int determination){
    this->Determination = determination;
}
int Infantary::getDetermination(){
	return this->Determination;
}

Mage::Mage(string name, int life, int strength, int sanity, int intelligence):
Card(name, life, strength, sanity),
Intelligence(intelligence)
{}
void Mage::setIntelligence(int intelligence){
    this->Intelligence = intelligence;
}
int Mage::getIntelligence(){
	return this->Intelligence;
}

Tech::Tech(string name, int life, int strength, int sanity, int hability):
Card(name, life, strength, sanity),
Hability(hability)
{}
void Tech::setHability(int hability){
    this->Hability = hability;
}
int Tech::getHability(){
	return this->Hability;
}

Tank::Tank(string name, int life, int strength, int sanity, int hardness):
Card(name, life, strength, sanity),
Hardness(hardness)
{}
void Tank::setHardness(int hardness){
    this->Hardness = hardness;
}
int Tank::getHardness(){
	return this->Hardness;
}

Medic::Medic(string name, int life, int strength, int sanity, int cure):
Card(name, life, strength, sanity),
Cure(cure)
{}
void Medic::setCure(int cure){
    this->Cure = cure;
}
int Medic::getCure(){
	return this->Cure;
}

Ranger::Ranger(string name, int life, int strength, int sanity, int accuracy):
Card(name, life, strength, sanity),
Accuracy(accuracy)
{}
void Ranger::setAccuracy(int accuracy){
    this->Accuracy = accuracy;
}
int Ranger::getAccuracy(){
	return this->Accuracy;
}