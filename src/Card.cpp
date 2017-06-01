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
void Card::setName(string Name){
  this->Name = Name;
}
string Card::getName(){
  return this->Name;
}
void Card::setLife(int Life){
  this->Life = Life;
}
int Card::getLife(){
  return this->Life;
}
void Card::setStrength(int Strength){
  this->Strength = Strength;
}
int Card::getStrength(){
  return this->Strength;
}
void Card::setSanity(int Sanity){
  this->Sanity = Sanity;
}
int Card::getSanity(){
  return this->Sanity;
}
/**
  *@brief Setter Next
  */
void Card::setNext(Card* card){
    this->Next = card;
}
/**
  *@brief Getter Next
  */
Card* Card::getNext(){
    return this->Next;
}
/**
  *@brief Interface Gráfica
  */
Boss::Boss(string name, int life, int strength, int sanity, int fury){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setFury(fury);
}

void Boss::setFury(int fury){
  this->Fury = fury;
}

int Boss::getFury(){
	return this->Fury;
}

Infantary::Infantary(string name, int life, int strength, int sanity, int determination){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setDetermination(determination);
}

void Infantary::setDetermination(int determination){
    this->Determination = determination;
}

int Infantary::getDetermination(){
	return this->Determination;
}

Mage::Mage(string name, int life, int strength, int sanity, int intelligence){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setIntelligence(intelligence);
}
void Mage::setIntelligence(int intelligence){
    this->Intelligence = intelligence;
}
int Mage::getIntelligence(){
	return this->Intelligence;
}

Tech::Tech(string name, int life, int strength, int sanity, int hability){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setHability(hability);
}
void Tech::setHability(int hability){
    this->Hability = hability;
}
int Tech::getHability(){
	return this->Hability;
}

Tank::Tank(string name, int life, int strength, int sanity, int hardness){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setHardness(hardness);
}
void Tank::setHardness(int hardness){
    this->Hardness = hardness;
}
int Tank::getHardness(){
	return this->Hardness;
}

Medic::Medic(string name, int life, int strength, int sanity, int cure){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCure(cure);
}
void Medic::setCure(int cure){
    this->Cure = cure;
}
int Medic::getCure(){
	return this->Cure;
}

Ranger::Ranger(string name, int life, int strength, int sanity, int accuracy){
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setAccuracy(accuracy);
}
void Ranger::setAccuracy(int accuracy){
    this->Accuracy = accuracy;
}
int Ranger::getAccuracy(){
	return this->Accuracy;
}