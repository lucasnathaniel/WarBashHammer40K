/**
  *@file Card.cpp
  *@brief funcao com a implementacao dos nós da lista
  */
#include "Card.h"
/**
  *@brief Construtor com parâmetros
  */
Card::Card(string type, string name, int life, int strength, int sanity, int cooldown, bool tanked){
  this->setNext(nullptr);
  this->setTanked(false);
}
Card::Card(){
	this->setNext(nullptr);
}
/**
  *@brief Destrutor
  */
Card::~Card(){

}
/**
  *@brief Construtor sem parâmetros
  */
void Card::setType(string Type){
  this->Type = Type;
}
string Card::getType(){
  return this->Type;
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
void Card::setCooldown(int Cooldown){
  this->Cooldown = Cooldown;
}
int Card::getCooldown(){
  return this->Cooldown;
}
void Card::setTanked(bool Tanked){
  this->Tanked = Tanked;
}
bool Card::getTanked(){
  return this->Tanked;
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
Boss::Boss(string type, string name, int life, int strength, int sanity, int fury){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(3);
  this->setTanked(false);
  this->setFury(fury);
}

void Boss::setFury(int fury){
  this->Fury = fury;
}

int Boss::getFury(){
	return this->Fury;
}

Infantary::Infantary(string type, string name, int life, int strength, int sanity, int determination){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(2);
  this->setTanked(false);
  this->setDetermination(determination);
}

void Infantary::setDetermination(int determination){
    this->Determination = determination;
}

int Infantary::getDetermination(){
	return this->Determination;
}

Mage::Mage(string type, string name, int life, int strength, int sanity, int intelligence){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(3);
  this->setTanked(false);
  this->setIntelligence(intelligence);
}
void Mage::setIntelligence(int intelligence){
    this->Intelligence = intelligence;
}
int Mage::getIntelligence(){
	return this->Intelligence;
}

Tech::Tech(string type, string name, int life, int strength, int sanity, int hability){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(3);
  this->setTanked(false);
  this->setHability(hability);
}
void Tech::setHability(int hability){
    this->Hability = hability;
}
int Tech::getHability(){
	return this->Hability;
}

Tank::Tank(string type, string name, int life, int strength, int sanity, int hardness){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(2);
  this->setTanked(true);
  this->setHardness(hardness);
}
void Tank::setHardness(int hardness){
    this->Hardness = hardness;
}
int Tank::getHardness(){
	return this->Hardness;
}

Medic::Medic(string type, string name, int life, int strength, int sanity, int cure){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(2);
  this->setTanked(false);
  this->setCure(cure);
}
void Medic::setCure(int cure){
    this->Cure = cure;
}
int Medic::getCure(){
	return this->Cure;
}

Ranger::Ranger(string type, string name, int life, int strength, int sanity, int accuracy){
  this->setType(type);
  this->setName(name);
  this->setLife(life);
  this->setStrength(strength);
  this->setSanity(sanity);
  this->setCooldown(2);
  this->setTanked(false);
  this->setAccuracy(accuracy);
}
void Ranger::setAccuracy(int accuracy){
    this->Accuracy = accuracy;
}
int Ranger::getAccuracy(){
	return this->Accuracy;
}