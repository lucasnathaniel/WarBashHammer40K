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
int List::getQuantity(){
  return Quantity;
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

void List::Insert(Card* new_card){
    Card* card;
    if(new_card->getType() == "Boss"){
    	Boss* boss = (Boss*)new_card;
    	card = new Boss(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), boss->getFury());
    }else if(new_card->getType() == "Infantary"){
    	Infantary* infantary = (Infantary*)new_card;
    	card = new Infantary(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), infantary->getDetermination());
    }else if(new_card->getType() == "Mage"){
		Mage* mage = (Mage*)new_card;
		card = new Mage(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), mage->getIntelligence());
    }else if(new_card->getType() == "Tech"){
    	Tech* tech = (Tech*)new_card;
    	card = new Tech(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), tech->getHability());
    }else if(new_card->getType() == "Tank"){
    	Tank* tank = (Tank*)new_card;
    	card = new Tank(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), tank->getHardness());
    }else if(new_card->getType() == "Medic"){
    	Medic* medic = (Medic*)new_card;
    	card = new Medic(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), medic->getCure());
    }else if(new_card->getType() == "Ranger"){
    	Ranger* ranger = (Ranger*)new_card;
    	card = new Ranger(new_card->getType(), new_card->getName(), new_card->getLife(), new_card->getStrength(), new_card->getSanity(), ranger->getAccuracy());
    }else{
    	cout << "Unidef type, exit!" << endl;
    	exit(0);
    }
    if(First == NULL){
    	card->setNext(First);
    	First = card;
    	this->Quantity++;
		return;
	}
    
    Card* percorre = First;
    
    while(percorre->getNext() != NULL){
    	percorre = percorre->getNext();
    	if(percorre->getNext() == percorre){
    		percorre->setNext(card);
    		this->Quantity++;
    		return;
    	}
    }
    percorre->setNext(card);
    this->Quantity++;
}

void List::PrintList(){
	int i = 1;
    for(Card* card = First; card != NULL; card = card->getNext()){
      if(card->getType() == "Boss"){
        Boss* boss = (Boss*)card;
        cout << "(" << i << ") " <<"\033[95m";
        cout << boss->getType() << " " << boss->getName() << " " << boss->getLife() << " " << boss->getStrength() << " " << boss->getSanity() << " " << boss->getFury();
      }else if(card->getType() == "Infantary"){
        Infantary* infantary = (Infantary*)card;
        cout << "(" << i << ") " << "\033[93m";
        cout << infantary->getType() << " " << infantary->getName() << " " << infantary->getLife() << " " << infantary->getStrength() << " " << infantary->getSanity() << " " << infantary->getDetermination();
      }else if(card->getType() == "Mage"){
        Mage* mage = (Mage*)card;
        cout << "(" << i << ") " << "\033[34m";
        cout << mage->getType() << " " << mage->getName() << " " << mage->getLife() << " " << mage->getStrength() << " " << mage->getSanity() << " " << mage->getIntelligence();
      }else if(card->getType() == "Tech"){
        Tech* tech = (Tech*)card;
        cout << "(" << i << ") " << "\033[91m";
        cout << tech->getType() << " " << tech->getName() << " " << tech->getLife() << " " << tech->getStrength() << " " << tech->getSanity() << " " << tech->getHability();
      }else if(card->getType() == "Tank"){
        Tank* tank = (Tank*)card;
        cout << "(" << i << ") " << "\033[37m";
        cout << tank->getType() << " " << tank->getName() << " " << tank->getLife() << " " << tank->getStrength() << " " << tank->getSanity() << " " << tank->getHardness();
      }else if(card->getType() == "Medic"){
        Medic* medic = (Medic*)card;
        cout << "(" << i << ") " << "\033[96m";
        cout << medic->getType() << " " << medic->getName() << " " << medic->getLife() << " " << medic->getStrength() << " " << medic->getSanity() << " " << medic->getCure();
      }else if(card->getType() == "Ranger"){
        Ranger* ranger = (Ranger*)card;
        cout << "(" << i << ") " << "\033[92m";
        cout << ranger->getType() << " " << ranger->getName() << " " << ranger->getLife() << " " << ranger->getStrength() << " " << ranger->getSanity() << " " << ranger->getAccuracy();
      }
    i++;
    cout << "\033[0m" << endl;
    if(card->getNext() == card){
        return;    
    }
    }
}

Card* List::SearchCard(int indice){
	if(indice>this->getQuantity() || indice == 0){
		return nullptr;
	}
	Card* card = First;
	for(int i = 1; i < indice; i++){
		card = card->getNext();
		if(card->getNext() == card){
			return card;
		}
	}
	return card;
}

void List::RemoveCard(int indice){
	
	if(this->getQuantity() == 1){
		delete First;
		Quantity--;
		return;
	}
	if(indice == 1){
		Card* fir = First->getNext();
		delete First;
		First = fir;
		this->Quantity--;
		return;
	}
	Card* run_before = First;
	Card* run = run_before->getNext();
	for(int i = 1; i < indice-1; i++){
		run_before = run_before->getNext();
		run = run_before->getNext();
	}
	run_before->setNext(run->getNext());
    delete run;
	this->Quantity--;
}
int List::Attack(int target, int damage){
    Card* card = First;
    int i = 1;
    for(int i = 1; i < target; i++){
        card = card->getNext();
    }
    card->setLife(card->getLife() - damage);
    if(card->getLife() <=0){
        return i;
    }
    return -1;
}
void List::BossTremmor(int damage){
    Card* card = First;
    for(int i = 1; i < this->Quantity; i++){
        card->setLife(card->getLife() - damage);
        if(card->getLife() <=0){
            Card* nextdied = card->getNext();
            RemoveCard(i);
            card = nextdied;
        }
    }
}

int List::RangerPassive(){
    int damage = 0;
    if(Quantity == 1){
    	if(First->getType() == "Ranger"){
            Ranger* ranger = (Ranger*)First;
            damage += ranger->getAccuracy() * (ranger->getStrength()/10);
        	return damage;
        }
    }
    for(Card* card = First; card != NULL; card = card->getNext()){
        if(card->getNext() == card){
        	return damage;
        }
        if(card->getType() == "Ranger"){
            Ranger* ranger = (Ranger*)card;
            damage += ranger->getAccuracy() * (ranger->getStrength()/10);
        }
    }
    return damage;
}

int List::MedicPassive(){
    int cure = 0;
    if(Quantity == 1){
    	if(First->getType() == "Medic"){
            Medic* medic = (Medic*)First;
            cure += medic->getCure() * 20;
        	return cure;
        }
    }
    for(Card* card = First; card != NULL; card = card->getNext()){
        if(card->getNext() == card){
        	return cure;
        }
        if(card->getType() == "Medic"){
            Medic* medic = (Medic*)card;
            cure += medic->getCure() * 20;
        }
    }
    return cure;
}

void List::MedicSunshine(int medic_cure){
    if(Quantity == 0){
    	return;
    }

    for(Card* card = First; card != NULL; card = card->getNext()){
        card->setLife(card->getLife() + medic_cure);
        if(card->getNext() == card){
        	return;
        }
    }
}

int List::MagePassive(){
    int damage = 0;
    if(Quantity == 1){
    	if(First->getType() == "Mage"){
            Mage* mage = (Mage*)First;
            damage += mage->getIntelligence() * 10;
        	return damage;
        }
    }
    for(Card* card = First; card != NULL; card = card->getNext()){
        if(card->getNext() == card){
        	return damage;
        }
        if(card->getType() == "Mage"){
            Mage* mage = (Mage*)card;
            damage += mage->getIntelligence() * 10;
        }
    }
    return damage;
}

vector<int> List::MageSpell(int mage_damage){
    vector<int> vector_elements_to_remove;
    int i = 1;
    for(Card* card = First; card != NULL; card = card->getNext()){
        card->setLife(card->getLife() - mage_damage);
        if(card->getLife() <= 0){
        	cout << "\033[1;93;91mTHE \033[1;93;13m" << card->getName() << "\033[1;93;91m WAS SLAIN BY \033[1;93;13mMAGE PASSIVE\033[0;0;0m"<< endl;
        	vector_elements_to_remove.push_back(i);
        }
        i++;
        if(card->getNext() == card){
        	return vector_elements_to_remove;
        }
    }
    return vector_elements_to_remove;
}
int List::BossPassive(){
    for(Card* card = First; card != NULL; card = card->getNext()){
        if(card->getType() == "Boss"){
            Boss* boss = (Boss*)card;
            return boss->getFury() * (boss->getStrength()/20);
        }
    }
    return 0;
}

void List::ReduceCds(){
    for(Card* card = First; card != NULL; card = card->getNext()){
        card->setCooldown(card->getCooldown()-1);
        if(card->getNext() == card){
        	return;
        }
    }
}