/**
  *@file Card.cpp
  *@brief funcao com a implementacao dos nós da lista
  */
#include "Card.h"
/**
  *@brief Construtor da carta com parâmetros
  *@param type tipo para ser colocado na carta
  *@param name nome para ser colocado na carta
  *@param life vida para ser colocada na carta
  *@param strength força para ser colocada na carta
  *@param sanity sanidade para ser colocada na carta
  *@param cooldown cooldown para ser colocado na carta
  *@param tanked variavel para dizer se o proximo ataque sera bloqueado
  */
Card::Card(string type, string name, int life, int strength, int sanity, int cooldown, bool tanked){
  this->setNext(nullptr);
  this->setTanked(false);
}
/**
  *@brief Construtor da carta sem parâmetros
  */
Card::Card(){
	this->setNext(nullptr);
}
/**
  *@brief Destrutor da carta
  */
Card::~Card(){

}
/**
  *@brief Setter do tipo da carta
  *@param type tipo para ser colocado na carta
  */
void Card::setType(string Type){
  this->Type = Type;
}
/**
  *@brief Getter do tipo da carta
  *@return retorna o tipo da carta
  */
string Card::getType(){
  return this->Type;
}
/**
  *@brief Setter do nome da carta
  *@param Name nome para ser colocado na carta
  */
void Card::setName(string Name){
  this->Name = Name;
}
/**
  *@brief Getter do nome da carta
  *@return retorna o nome da carta
  */
string Card::getName(){
  return this->Name;
}
/**
  *@brief Setter da vida da carta
  *@param Lige vida para ser colocada na carta
  */
void Card::setLife(int Life){
  this->Life = Life;
}
/**
  *@brief Getter da vida da carta
  *@return retorna a vida da carta
  */
int Card::getLife(){
  return this->Life;
}
/**
  *@brief Setter da força da carta
  *@param Strength força para ser colocada na carta
  */
void Card::setStrength(int Strength){
  this->Strength = Strength;
}
/**
  *@brief Getter da força da carta
  *@return retorna a força da carta
  */
int Card::getStrength(){
  return this->Strength;
}
/**
  *@brief Setter da sanidade da carta
  *@param Sanity sanidade para ser colocada na carta
  */
void Card::setSanity(int Sanity){
  this->Sanity = Sanity;
}
/**
  *@brief Getter da sanidade da carta
  *@return retorna a sanidade da carta
  */
int Card::getSanity(){
  return this->Sanity;
}
/**
  *@brief Setter do cooldown da carta
  *@param Cooldown cooldown para ser colocado na carta
  */
void Card::setCooldown(int Cooldown){
  this->Cooldown = Cooldown;
}
/**
  *@brief Getter do cooldown da carta
  *@return retorna o cooldown da carta
  */
int Card::getCooldown(){
  return this->Cooldown;
}
/**
  *@brief Setter para a carta bloquear o proximo ataque ou não
  *@param Tanked booleana para dizer se o próximo ataque será bloqueado
  */
void Card::setTanked(bool Tanked){
  this->Tanked = Tanked;
}
/**
  *@brief Getter para ver se a carta bloqueará o próximo ataque
  *@return retorna se a carta bloqueará
  */
bool Card::getTanked(){
  return this->Tanked;
}
/**
  *@brief Setter da próxima carta
  *@param card define a próxima carta
  */
void Card::setNext(Card* card){
    this->Next = card;
}
/**
  *@brief Getter da próxima carta
  *@return retorna a próxima carta
  */
Card* Card::getNext(){
    return this->Next;
}
/**
  *@brief Construtor do Boss
  *@param type tipo para ser colocado no Boss
  *@param name nome para ser colocado no Boss
  *@param life vida para ser colocada no Boss
  *@param strength força para ser colocada no Boss
  *@param sanity sanidade para ser colocada no Boss
  *@param fury furia para ser colocada no Boss
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
/**
  *@brief Setter da fúria do Boss
  *@param fury define a fúria do Boss
  */
void Boss::setFury(int fury){
  this->Fury = fury;
}
/**
  *@brief Getter da fúria do Boss
  *@return retorna a fúria do Boss
  */
int Boss::getFury(){
	return this->Fury;
}
/**
  *@brief Construtor da Infantaria
  *@param type tipo para ser colocado na Infantaria
  *@param name nome para ser colocado na Infantaria
  *@param life vida para ser colocada na Infantaria
  *@param strength força para ser colocada na Infantaria
  *@param sanity sanidade para ser colocada na Infantaria
  *@param determination determinação para ser colocada na Infantaria
  */
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
/**
  *@brief Setter da determinação da Infantaria
  *@param determination define a determinação da Infantaria
  */
void Infantary::setDetermination(int determination){
    this->Determination = determination;
}
/**
  *@brief Getter da determinação da Infantaria
  *@return retorna a determinação da Infantaria
  */
int Infantary::getDetermination(){
	return this->Determination;
}
/**
  *@brief Construtor do Mago
  *@param type tipo para ser colocado no Mago
  *@param name nome para ser colocado no Mago
  *@param life vida para ser colocada no Mago
  *@param strength força para ser colocada no Mago
  *@param sanity sanidade para ser colocada no Mago
  *@param intelligence inteligência para ser colocada no Mago
  */
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
/**
  *@brief Setter da inteligência do Mago
  *@param intelligence define a inteligência do Mago
  */
void Mage::setIntelligence(int intelligence){
    this->Intelligence = intelligence;
}
/**
  *@brief Getter da inteligência do Mago
  *@return retorna a inteligência do Mago
  */
int Mage::getIntelligence(){
	return this->Intelligence;
}
/**
  *@brief Construtor do Técnico
  *@param type tipo para ser colocado no Técnico
  *@param name nome para ser colocado no Técnico
  *@param life vida para ser colocada no Técnico
  *@param strength força para ser colocada no Técnico
  *@param sanity sanidade para ser colocada no Técnico
  *@param hability habilidade para ser colocada no Técnico
  */
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
/**
  *@brief Setter da habilidade do Técnico
  *@param hability define a habilidade do Técnico
  */
void Tech::setHability(int hability){
    this->Hability = hability;
}
/**
  *@brief Getter da habilidade do Técnico
  *@return retorna a habilidade do Técnico
  */
int Tech::getHability(){
	return this->Hability;
}
/**
  *@brief Construtor do Tank
  *@param type tipo para ser colocado no Tank
  *@param name nome para ser colocado no Tank
  *@param life vida para ser colocada no Tank
  *@param strength força para ser colocada no Tank
  *@param sanity sanidade para ser colocada no Tank
  *@param hardness dureza para ser colocada no Tank
  */
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
/**
  *@brief Setter da dureza do Tank
  *@param hardness define a dureza do Tank
  */
void Tank::setHardness(int hardness){
    this->Hardness = hardness;
}
/**
  *@brief Getter da dureza do Tank
  *@return retorna a dureza do Tank
  */
int Tank::getHardness(){
	return this->Hardness;
}
/**
  *@brief Construtor do Medico
  *@param type tipo para ser colocado no Medico
  *@param name nome para ser colocado no Medico
  *@param life vida para ser colocada no Medico
  *@param strength força para ser colocada no Medico
  *@param sanity sanidade para ser colocada no Medico
  *@param cure cura para ser colocada no Medico
  */
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
/**
  *@brief Setter da cura do Médico
  *@param cure define a cura do Médico
  */
void Medic::setCure(int cure){
    this->Cure = cure;
}
/**
  *@brief Getter da cura do Medico
  *@return retorna a cura do Medico
  */
int Medic::getCure(){
	return this->Cure;
}
/**
  *@brief Construtor do Atirador
  *@param type tipo para ser colocado no Atirador
  *@param name nome para ser colocado no Atirador
  *@param life vida para ser colocada no Atirador
  *@param strength força para ser colocada no Atirador
  *@param sanity sanidade para ser colocada no Atirador
  *@param accuracy acurácia para ser colocada no Atirador
  */
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
/**
  *@brief Setter da acurácia do Atirador
  *@param accuracy define a acurácia do Atirador
  */
void Ranger::setAccuracy(int accuracy){
    this->Accuracy = accuracy;
}
/**
  *@brief Getter da acurácia do Atirador
  *@return retorna a acurácia do Atirador
  */
int Ranger::getAccuracy(){
	return this->Accuracy;
}