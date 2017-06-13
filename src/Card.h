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
		int Cooldown;
		bool Tanked = false;
		Card* Next;

	public:
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
		Card(string Type, string Name, int Life, int Strength, int Sanity, int Cooldown, bool Tanked);
		/**
  		  *@brief Construtor da carta sem parâmetros
  		  */
		Card();
		/**
  		  *@brief Destrutor da carta
  		  */
		~Card();
		/**
  		  *@brief Setter do tipo da carta
  		  *@param type tipo para ser colocado na carta
  		  */
		void setType(string Type);
		/**
    	  *@brief Getter do tipo da carta
    	  *@return retorna o tipo da carta
    	  */
		string getType();
		/**
  		  *@brief Setter do nome da carta
  		  *@param Name nome para ser colocado na carta
  		  */
		void setName(string Name);
		/**
  		  *@brief Getter do nome da carta
  		  *@return retorna o nome da carta
  		  */
		string getName();
		/**
  		  *@brief Setter da vida da carta
  		  *@param Lige vida para ser colocada na carta
  		  */
		void setLife(int Life);
		/**
  		  *@brief Getter da vida da carta
  		  *@return retorna a vida da carta
  		  */
		int getLife();
		/**
  		  *@brief Setter da força da carta
  		  *@param Strength força para ser colocada na carta
  		  */
		void setStrength(int Strength);
		/**
  		  *@brief Getter da força da carta
  		  *@return retorna a força da carta
  		  */
		int getStrength();
		/**
  		  *@brief Setter da sanidade da carta
  		  *@param Sanity sanidade para ser colocada na carta
  		  */
		void setSanity(int Sanity);
		/**
  		  *@brief Getter da sanidade da carta
  		  *@return retorna a sanidade da carta
  		  */
		int getSanity();
		/**
  		  *@brief Setter do cooldown da carta
  		  *@param Cooldown cooldown para ser colocado na carta
  		  */
		void setCooldown(int Cooldown);
		/**
  		  *@brief Getter do cooldown da carta
  		  *@return retorna o cooldown da carta
  		  */
		int getCooldown();
		/**
  		  *@brief Setter para a carta bloquear o proximo ataque ou não
  		  *@param Tanked booleana para dizer se o próximo ataque será bloqueado
  		  */
		void setTanked(bool Tanked);
		/**
  		  *@brief Getter para ver se a carta bloqueará o próximo ataque
  		  *@return retorna se a carta bloqueará
  		  */
		bool getTanked();
		/**
  		  *@brief Setter da próxima carta
  		  *@param card define a próxima carta
  		  */
		void setNext(Card* book);
		/**
  		  *@brief Getter da próxima carta
  		  *@return retorna a próxima carta
  		  */
		Card* getNext();

};

class Boss : public Card{
	protected:
		int Fury;
	public:
		/**
  		  *@brief Construtor do Boss
  		  *@param type tipo para ser colocado no Boss
  		  *@param name nome para ser colocado no Boss
  		  *@param life vida para ser colocada no Boss
  		  *@param strength força para ser colocada no Boss
  		  *@param sanity sanidade para ser colocada no Boss
  		  *@param fury furia para ser colocada no Boss
  		  */
		Boss(string Type, string Name, int Life, int Strength, int Sanity, int Fury);
		/**
  		  *@brief Setter da fúria do Boss
  		  *@param fury define a fúria do Boss
  		  */
		void setFury(int Fury);
		/**
  		  *@brief Getter da fúria do Boss
  		  *@return retorna a fúria do Boss
  		  */
		int getFury();
};
class Infantary : public Card{
	protected:
		int Determination;
	public:
		/**
  		  *@brief Construtor da Infantaria
  		  *@param type tipo para ser colocado na Infantaria
  		  *@param name nome para ser colocado na Infantaria
  		  *@param life vida para ser colocada na Infantaria
  		  *@param strength força para ser colocada na Infantaria
  		  *@param sanity sanidade para ser colocada na Infantaria
  		  *@param determination determinação para ser colocada na Infantaria
  		  */
		Infantary(string Type, string Name, int Life, int Strength, int Sanity, int Determination);
		/**
  		  *@brief Setter da determinação da Infantaria
  		  *@param determination define a determinação da Infantaria
  		  */
		void setDetermination(int Determination);
		/**
  		  *@brief Getter da determinação da Infantaria
  		  *@return retorna a determinação da Infantaria
  		  */
		int getDetermination();
};
class Mage : public Card{
	protected:
		int Intelligence;
	public:
		/**
  		  *@brief Construtor do Mago
  		  *@param type tipo para ser colocado no Mago
  		  *@param name nome para ser colocado no Mago
  		  *@param life vida para ser colocada no Mago
  		  *@param strength força para ser colocada no Mago
  		  *@param sanity sanidade para ser colocada no Mago
  		  *@param intelligence inteligência para ser colocada no Mago
  		  */
		Mage(string Type, string Name, int Life, int Strength, int Sanity, int Intelligence);
		/**
  		  *@brief Setter da inteligência do Mago
  		  *@param intelligence define a inteligência do Mago
  		  */
		void setIntelligence(int Intelligence);
		/**
  		  *@brief Getter da inteligência do Mago
  		  *@return retorna a inteligência do Mago
  		  */
		int getIntelligence();
};
class Tech : public Card{
	protected:
		int Hability;
	public:
		/**
  		  *@brief Construtor do Técnico
  		  *@param type tipo para ser colocado no Técnico
  		  *@param name nome para ser colocado no Técnico
  		  *@param life vida para ser colocada no Técnico
  		  *@param strength força para ser colocada no Técnico
  		  *@param sanity sanidade para ser colocada no Técnico
  		  *@param hability habilidade para ser colocada no Técnico
  		  */
		Tech(string Type, string Name, int Life, int Strength, int Sanity, int Hability);
		/**
  		  *@brief Setter da habilidade do Técnico
  		  *@param hability define a habilidade do Técnico
  		  */
		void setHability(int Hability);
		/**
  		  *@brief Getter da habilidade do Técnico
  		  *@return retorna a habilidade do Técnico
  		  */
		int getHability();
};
class Tank : public Card{
	protected:
		int Hardness;
	public:
		/**
  		  *@brief Construtor do Tank
  		  *@param type tipo para ser colocado no Tank
  		  *@param name nome para ser colocado no Tank
  		  *@param life vida para ser colocada no Tank
  		  *@param strength força para ser colocada no Tank
  		  *@param sanity sanidade para ser colocada no Tank
  		  *@param hardness dureza para ser colocada no Tank
  		  */
		Tank(string Type, string Name, int Life, int Strength, int Sanity, int Hardness);
		/**
  		  *@brief Setter da dureza do Tank
  		  *@param hardness define a dureza do Tank
  		  */
		void setHardness(int Hardness);
		/**
  		  *@brief Getter da dureza do Tank
  		  *@return retorna a dureza do Tank
  		  */
		int getHardness();
};
class Medic : public Card{
	protected:
		int Cure;
	public:
		/**
  		  *@brief Construtor do Medico
  		  *@param type tipo para ser colocado no Medico
  		  *@param name nome para ser colocado no Medico
  		  *@param life vida para ser colocada no Medico
  		  *@param strength força para ser colocada no Medico
  		  *@param sanity sanidade para ser colocada no Medico
  		  *@param cure cura para ser colocada no Medico
  		  */
		Medic(string Type, string Name, int Life, int Strength, int Sanity, int Cure);
		/**
  		  *@brief Setter da cura do Médico
  		  *@param cure define a cura do Médico
  		  */
		void setCure(int Cure);
		/**
  		  *@brief Getter da cura do Medico
  		  *@return retorna a cura do Medico
  		  */
		int getCure();
};
class Ranger : public Card{
	protected:
		int Accuracy;
	public:
		/**
  		  *@brief Construtor do Atirador
  		  *@param type tipo para ser colocado no Atirador
  		  *@param name nome para ser colocado no Atirador
  		  *@param life vida para ser colocada no Atirador
  		  *@param strength força para ser colocada no Atirador
  		  *@param sanity sanidade para ser colocada no Atirador
  		  *@param accuracy acurácia para ser colocada no Atirador
  		  */
		Ranger(string Type, string Name, int Life, int Strength, int Sanity, int Accuracy);
		/**
  		  *@brief Setter da acurácia do Atirador
  		  *@param accuracy define a acurácia do Atirador
  		  */
		void setAccuracy(int Accuracy);
		/**
  		  *@brief Getter da acurácia do Atirador
  		  *@return retorna a acurácia do Atirador
  		  */
		int getAccuracy();
};

#endif