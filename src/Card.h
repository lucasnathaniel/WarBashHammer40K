/**
  *@file Card.h
  *@class Card
  *@brief Arquivo com as declaracoes das funcoes da classe Card
  */

#ifndef __Card_H__
#define __Card_H__

using namespace std;
#include <iostream>
#include <string>


class Card{
	private:
		string Type;
		string Name;
		int Life;
		int Strength;
		int Sanity;
		Card* Next;

	public:
		Card(string Type, string Name, int Life, int Strength, int Sanity);
		Card();
		~Card();
		void setType(string Type);
		string getType();
		void setName(string Name);
		string getName();
		void setLife(int Life);
		int getLife();
		void setStrength(int Strength);
		int getStrength();
		void setSanity(int Sanity);
		int getSanity();
		void setNext(Card* book);
		Card* getNext();

};

class Boss : public Card{
	protected:
		int Fury;
	public:
		Boss(string Type, string Name, int Life, int Strength, int Sanity, int Fury);
		void setFury(int Fury);
		int getFury();
};
class Infantary : public Card{
	protected:
		int Determination;
	public:
		Infantary(string Type, string Name, int Life, int Strength, int Sanity, int Determination);
		void setDetermination(int Determination);
		int getDetermination();
};
class Mage : public Card{
	protected:
		int Intelligence;
	public:
		Mage(string Type, string Name, int Life, int Strength, int Sanity, int Intelligence);
		void setIntelligence(int Intelligence);
		int getIntelligence();
};
class Tech : public Card{
	protected:
		int Hability;
	public:
		Tech(string Type, string Name, int Life, int Strength, int Sanity, int Hability);
		void setHability(int Hability);
		int getHability();
};
class Tank : public Card{
	protected:
		int Hardness;
	public:
		Tank(string Type, string Name, int Life, int Strength, int Sanity, int Hardness);
		void setHardness(int Hardness);
		int getHardness();
};
class Medic : public Card{
	protected:
		int Cure;
	public:
		Medic(string Type, string Name, int Life, int Strength, int Sanity, int Cure);
		void setCure(int Cure);
		int getCure();
};
class Ranger : public Card{
	protected:
		int Accuracy;
	public:
		Ranger(string Type, string Name, int Life, int Strength, int Sanity, int Accuracy);
		void setAccuracy(int Accuracy);
		int getAccuracy();
};

#endif