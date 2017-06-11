#include "Functions.h"

void Interface(){

cout << " \033[01;93m __          __        \033[96m____            _                        " << endl;
cout << " \033[01;93m \\ \\        / /       \033[96m|  _ \\          | |                       " << endl;
cout << " \033[01;93m  \\ \\  /\\  / /_ _ _ __\033[96m| |_) | __ _ ___| |__    By: Lucas          " << endl;
cout << " \033[01;93m   \\ \\/  \\/ / _` | '__\033[96m|  _ < / _` / __| '_ \\     Nathaniel                " << endl;
cout << " \033[01;93m  _ \\  /\\  / (_| | |  \033[96m| |_) | (_| \\__ \\ | | |\033[31m_  _    ___  _  __ " << endl;
cout << " \033[01;93m | | \\/ |\\/ \\__,_|_|  \033[96m|____/ \\__,_|___/_| |_\033[31m| || |  / _ \\| |/ / " << endl;
cout << " \033[01;93m | |__| | __ _ _ __ ___  _ __ ___   ___ _ __\033[31m| || |_| | | | ' /  " << endl;
cout << " \033[01;93m |  __  |/ _` | '_ ` _ \\| '_ ` _ \\ / _ \\ '__\033[31m|__   _| | | |  <   " << endl;
cout << " \033[01;93m | |  | | (_| | | | | | | | | | | |  __/ |     \033[31m| | | |_| | . \\  " << endl;
cout << " \033[01;93m |_|  |_|\\__,_|_| |_| |_|_| |_| |_|\\___|_|     \033[31m|_|  \\___/|_|\\_\\ " << endl;

  cout <<"\n\033[96mWelcome to the \033[01;93mWar\033[96mBash\033[01;93mHammer\033[96m, press \033[31mstart\033[00;0m" << endl;
}

void StartGame(){

	cout << "\n\033[96mChoose your race!\033[0m" << endl;
	char your_race, enemy_race;
	string address;
	cout << "(1) SpaceMarines" << endl;
	cout << "(2) Eldars" << endl;
	cout << "(3) Orks" << endl;
	cin >> your_race;
	if(your_race == '1'){
		address = "../db/SpaceMarines.txt";
	}else if(your_race == '2'){
		address = "../db/Eldars.txt";
	}else if(your_race == '3'){
		address = "../db/Orks.txt";
	}else{
		cout << "Invalid race!" << endl;
		return;
	}
	List *your_list = ReadRace(address);
	cout << "\nYour deck: " << endl;
	your_list->PrintList();
	cout << "\n\033[96mChoose the enemy race!\033[0m" << endl;
	cout << "(1) SpaceMarines" << endl;
	cout << "(2) Eldars" << endl;
	cout << "(3) Orks" << endl;
	cin >> enemy_race;
	if(enemy_race == '1'){
		address = "../db/SpaceMarines.txt";
	}else if(enemy_race == '2'){
		address = "../db/Eldars.txt";
	}else if(enemy_race == '3'){
		address = "../db/Orks.txt";
	}else{
		cout << "Invalid race!" << endl;
		return;
	}
		
	List *enemy_list = ReadRace(address);
	cout << "\nEnemy deck: " << endl;
	enemy_list->PrintList();
	char start;
	cout << "\nPress some button to start!" << endl;
	cin >> start;
	Playing(your_list, enemy_list);
}

List* ReadRace(string address){
	List *race = new List();
	ifstream database(address);
	
	if(!database){
		cout << "File can't open!" << endl;
	}
	string line;
	vector<string> v;
	int count = 0;
	if(database.is_open()){
		while(getline(database, line)){
			part(line, ' ', v);
			race->Insert(v[0+count*6], v[1+count*6], stoi(v[2+count*6]), stoi(v[3+count*6]), stoi(v[4+count*6]), stoi(v[4+count*6]));
			count++;
		}
		database.close();
	}
	return race;
}

/**
  *@brief Separe string on substrings
  */
void part(string& str, char delim, vector<string>& pieces){
    
    string::size_type i = 0;
    string::size_type j = str.find(delim);
    while (j != string::npos){
        pieces.push_back(str.substr(i, j - i));
        i = ++j;
        j = str.find(delim, j);

        if (j == string::npos)
            pieces.push_back(str.substr(i, str.length()));
    }
}

void Playing(List* your_list, List* enemy_list){
	
	srand (time(NULL));
	int you_count_field=0, enemy_count_field=0;
	char the_play;
	int int_play;
	int you_can_put_boss = 3; //when this is 0, you can put boss, this decrease when you lost a card
	int enemy_can_put_boss = 3; // /\ for enemy
	List* your_cards_on_field = new List();
	List* enemy_cards_on_field = new List();
	while(1){
		system("clear");
		if((your_list->getQuantity() == 0 && your_cards_on_field == 0)|| (enemy_list->getQuantity() == 0 && enemy_cards_on_field == 0)){
			break;
		}

		//Enemy play
		if(enemy_list->getQuantity() !=0){ // Inimigo coloca carta aleatoria
			int random = (rand() % enemy_list->getQuantity()) + 1;
			Card* put_card = enemy_list->SearchCard(random);
			if(put_card->getType() == "Boss" && enemy_can_put_boss > 0){ // if the enemy try put a boss without lost 3 cards
				continue;
			}
			//Reduce cds
			your_cards_on_field->ReduceCds();
			enemy_cards_on_field->ReduceCds();
			//end --cds
			
			//you range passive damage
			int enemy_range_damage = your_cards_on_field->RangerPassive();
			bool if_died_by_rangers = false;
			if(enemy_range_damage != 0){
				put_card->setLife(put_card->getLife() - enemy_range_damage);
				cout << "the card that the enemy placed, took \033[91m" << enemy_range_damage << "\033[0m damage, because have rangers(s) on you side" << endl;
				if(put_card->getLife() <= 0){
					cout << "\033[1;93;91mTHE \033[1;93;13m" << put_card->getName() << "\033[1;93;91m WAS SLAIN BY \033[1;93;13mRANGERS\033[0;0;0m"<< endl;
					if_died_by_rangers = true;
				}
			}
			//end of range passive
			if(!if_died_by_rangers){
				enemy_cards_on_field->Insert(put_card);
				enemy_count_field++;
				string enemy_type = put_card->getType();
				string enemy_name = put_card->getName();
				enemy_list->RemoveCard(random);
				cout << "The \033[91menemy\033[0m put ";
				PrintColor(enemy_type);
				cout << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;			
			}
		}
		//End of enemy play
		cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
		cin >> the_play;
		int medic_cure = your_cards_on_field->MedicPassive();
		int mage_passive = your_cards_on_field->MagePassive();
		your_cards_on_field->MedicSunshine(medic_cure);
		your_cards_on_field->MageSpell(mage_passive);
		if(medic_cure != 0){
			cout << "\033[96mYour cards received +" << medic_cure << " of your medic!\033[0m" << endl;
		}
		if(mage_passive != 0){
			cout << "\033[91mYour cards received -" << mage_passive << " of the enemy(s) Mage(s)!\033[0m" << endl;
		}
		GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
		//Your play
		bool puted = false; //var to verif if puted
		string invalid = "invalid";
		if(you_count_field == 0){ //If dont have cards on field and and have cards on hand
			cout << "Please, \033[34mselect a card\033[0m to put" << endl;
			cin >> int_play;
			Card* put_card = your_list->SearchCard(int_play);
			if(put_card != nullptr){
				if(you_can_put_boss > 0 && put_card->getType() == "Boss"){ // if you to want put the boss without lost 3 cards
					cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
					cout << "Press a button to restore your intelligence" << endl;
					cin >> the_play;
					continue;
				}
				int range_damage = enemy_cards_on_field->RangerPassive();
				if(range_damage != 0){
					put_card->setLife(put_card->getLife() - range_damage);
					cout << "the card that you placed, took " << range_damage << " damage, because have rangers(s) on the enemy side" << endl;
				}
				your_cards_on_field = PutACardOnField(your_list, your_cards_on_field, put_card);
				you_count_field++;
				invalid = put_card->getName();
				your_list->RemoveCard(int_play);
				system("clear");
				GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);

			}else{
				cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
				cout << "Press a button to restore your intelligence" << endl;
				cin >> the_play;
			}
		}else{
			if(your_list->getQuantity() != 0){ //If have cards on field and cards on hand
				cout << "Please, \033[34mselect a card\033[0m to put" << endl;
				cin >> int_play;
				Card* put_card = your_list->SearchCard(int_play);
				if(put_card != nullptr){
					if(you_can_put_boss > 0 && put_card->getType() == "Boss"){ // if you to want put the boss without lost 3 cards
						cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
						cout << "Press a button to restore your intelligence" << endl;
						cin >> the_play;
						continue;
					}
					int range_damage = enemy_cards_on_field->RangerPassive();
					if(range_damage != 0){
						put_card->setLife(put_card->getLife() - range_damage);
						cout << "the card that you placed, took " << range_damage << " damage, because have rangers(s) on the enemy side" << endl;
					}
					your_cards_on_field = PutACardOnField(your_list, your_cards_on_field, put_card);
					puted = true;
					invalid = put_card->getName();
					your_list->RemoveCard(int_play);
					system("clear");
					GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
				}else{
					cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
					cout << "Press a button to restore your intelligence" << endl;
					cin >> the_play;
					continue;
				}
			}
			vector<string> used = {"hellor"};
			for(int cards_to_use = 0; cards_to_use < you_count_field; cards_to_use++){
				if(enemy_count_field == 0){
					cout << "Dont have more enemys :/" << endl;
					break;
				}
				if(enemy_count_field != 0){
					cout << "Please, \033[34mselect a card\033[0m to use" << endl;
					cin >> int_play;
					Card* select_card = your_cards_on_field->SearchCard(int_play);
	
					if(select_card->getName() == invalid){
						cout << "\033[91mYou placed this card, cant use now, lost the round, idiot!\033[0m" << endl;
						cout << "Press a button to restore your intelligence" << endl;
						cin >> the_play;
						continue;
					}
					if(int_play > you_count_field || int_play <= 0){
						cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
						cout << "Press a button to restore your intelligence" << endl;
						cin >> the_play;
						continue;
					}
					int use_card = 0;
					while(use_card <= used.size()){
						if(used[use_card] == select_card->getName()){
							cout << "\033[91mYou already used this card!\033[0m" << endl;
							cout << "Press a button to restore your intelligence" << endl;
							cin >> the_play;
							break;
						}
						use_card++;
					}
					if(used[use_card] == select_card->getName()){
						continue;
					}
					cout << "You selected the ";
					PrintColor(select_card->getType());
					cout << select_card->getType() << " " << select_card->getName() << "\033[0m" << endl;
					used.push_back(select_card->getName());
					if(select_card->getCooldown() <= 0){
						cout << "(1) Use the Special Hability" << endl;
						cout << "(2) Attack a enemy" << endl;
						cin >> int_play;
						if(int_play == 1){
							if(select_card->getType() == "Boss"){
								cout << "Tremmor(3 rounds): attack all enemys with her (Fury * 10% Strength)." << endl;
								Boss* boss = (Boss*)select_card;
								int decreasemage = enemy_cards_on_field->MagePassive();//if have mage on the enemy field, this active her passive
								int tremmor_damage = (boss->getFury() * boss->getStrength()/10) - decreasemage;
								
								enemy_cards_on_field->BossTremmor(tremmor_damage); // enemy received damage
								select_card->setCooldown(3);
							}else if(select_card->getType() == "Infantary"){
								cout << "Battleon(2 rounds): attack 2 times." << endl;
								Infantary* infantary = (Infantary*)select_card;
								for(int i=0; i<2; i++){
									cout << "Select a \033[91menemy\033[0m to attack" << endl;
									cin >> int_play;
									int decreasemage = enemy_cards_on_field->MagePassive();
									int increaseboss = your_cards_on_field->BossPassive();
									int infantarypassive = infantary->getDetermination() * (infantary->getStrength()/10);
									Card* enemy_select_card = enemy_cards_on_field->SearchCard(int_play);
									
									cout << "You selected the ";
									PrintColor(enemy_select_card->getType());
									cout << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
	
									int infantary_damage = select_card->getStrength() - decreasemage + increaseboss + infantarypassive;
	
									int enemy_to_eleminate = enemy_cards_on_field->Attack(int_play, infantary_damage);
									if(enemy_to_eleminate != -1){
										enemy_cards_on_field->RemoveCard(int_play);
										cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m WAS SLAIN BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
										cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
										enemy_count_field--;
										enemy_can_put_boss++;
										cin >> the_play;
										system("clear");
										GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
									}else{
										cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m TOOK \033[1;93;13m"<< infantary_damage <<  "\033[1;93;91m DAMAGE  BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
										cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
										cin >> the_play;
										system("clear");
										GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
									}
	
								}
								select_card->setCooldown(2);
							}else if(select_card->getType() == "Mage"){
								cout << "SpellWave(3 rounds): manipulate a enemy, depending of sanity of the enemy(10*Sanity - 60%)" << endl;
								cout << "Select a \033[91menemy\033[0m to manipulate" << endl;
								cin >> int_play;
								Card* select_card_to_manipulate = enemy_cards_on_field->SearchCard(int_play);
								int rand_mani = (rand() % 100) + 1;
								if(rand_mani <= 60-10*select_card_to_manipulate->getSanity()){
									your_cards_on_field = PutACardOnField(enemy_cards_on_field, your_cards_on_field, select_card_to_manipulate);
									enemy_count_field--;
									you_count_field++;
									enemy_can_put_boss++;
									enemy_cards_on_field->RemoveCard(int_play);
									cout << "You're the mage!" << endl;
								}else{
									cout << "you should to study more :/" << endl;
								}
								cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
								cin >> the_play;
								select_card->setCooldown(3);
							}else if(select_card->getType() == "Tech"){
								cout << "Hacker(3 rounds): manipulate a enemy, depending of her (Hability * 5%)" << endl;
								cout << "Select a \033[91menemy\033[0m to H4CK" << endl;
								cin >> int_play;
								Card* select_card_to_hack = enemy_cards_on_field->SearchCard(int_play);
								int rand_hack = (rand() % 100) + 1;
								Tech* tech = (Tech*)select_card;
								if(rand_hack <= tech->getHability() * 5){
									your_cards_on_field = PutACardOnField(enemy_cards_on_field, your_cards_on_field, select_card_to_hack);
									enemy_count_field--;
									enemy_can_put_boss++;
									you_count_field++;
									enemy_cards_on_field->RemoveCard(int_play);
									cout << "H4CK3D!" << endl;
								}else{
									cout << "Hack FAIL :/" << endl;
								}
								cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
								cin >> the_play;
								select_card->setCooldown(3);
							}else if(select_card->getType() == "Tank"){
								cout << "Mountain(2 rounds): Select a ally to block your next damage" << endl;
								cout << "Select a ally to TANK!" << endl;
								cin >> int_play;
								Card* select_card_to_tank = your_cards_on_field->SearchCard(int_play);
								select_card_to_tank->setTanked(true);
								cout << "You're tanking your ally " << select_card_to_tank->getName() << endl;
								cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
								cin >> the_play;
								select_card->setCooldown(2);
							}else if(select_card->getType() == "Medic"){
								cout << "Sunshine(2 round): Heal and give +500 HP for a ally." << endl;
								cout << "Select a ally to heal!" << endl;
								cin >> int_play;
								Card* select_card_to_heal = your_cards_on_field->SearchCard(int_play);
								select_card_to_heal->setLife(select_card_to_heal->getLife()+500);
								cout << "The life of the " << select_card_to_heal->getName() << " is now " << select_card_to_heal->getLife() << endl;
								select_card->setCooldown(2);
								cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
								cin >> the_play;
							}else if(select_card->getType() == "Ranger"){
								cout << "Ragnarok(2 rounds): Select a enemy to give a critic shot(200% damage(25% chance))." << endl;
								cout << "Select a \033[91menemy\033[0m to attack" << endl;
								cin >> int_play;
								bool advantage = false;
								Card* enemy_select_card = enemy_cards_on_field->SearchCard(int_play);
								if(enemy_select_card == nullptr){
									cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
									cout << "Press a button to restore your intelligence" << endl;
									cin >> the_play;
									continue;
								}
								if(enemy_select_card->getType() == "Boss"){
									cout << "You selected the \033[95m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
								}else if(enemy_select_card->getType() == "Infantary"){
									cout << "You selected the \033[93m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() == "Boss" || select_card->getType() == "Mage" || select_card->getType() == "Ranger"){
										advantage = true;
									}
								}else if(enemy_select_card->getType() == "Mage"){
									cout << "You selected the \033[34m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() == "Boss" || select_card->getType() == "Tank" || select_card->getType() == "Ranger"){
										advantage = true;
									}
								}else if(enemy_select_card->getType() == "Tech"){
									cout << "You selected the \033[91m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() == "Boss" || select_card->getType() == "Infantary" || select_card->getType() == "Mage"){
										advantage = true;
									}
								}else if(enemy_select_card->getType() == "Tank"){
									cout << "You selected the \033[37m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() == "Boss" || select_card->getType() == "Tech"){
										advantage = true;
									}
								}else if(enemy_select_card->getType() == "Medic"){
									cout << "You selected the \033[96m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() != "Tank" || select_card->getType() != "Medic"){
										advantage = true;
									}
								}else if(enemy_select_card->getType() == "Ranger"){
									cout << "You selected the \033[92m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
									if(select_card->getType() != "Medic" || select_card->getType() != "Ranger"){
										advantage = true;
									}
								}
								int decreasemage = enemy_cards_on_field->MagePassive();
								int increaseboss = your_cards_on_field->BossPassive();
								int you_damage = select_card->getStrength() - decreasemage + increaseboss;
								if(advantage){
									you_damage *= 1.5;
								}
								int critic_shot = (rand() % 12) + 1;
								if(critic_shot <= 4){
									you_damage *=2;
								}
								int enemy_to_eleminate = enemy_cards_on_field->Attack(int_play, you_damage);
								if(enemy_to_eleminate != -1){
									enemy_cards_on_field->RemoveCard(int_play);
									cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m WAS SLAIN BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
									cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
									enemy_count_field--;
									enemy_can_put_boss++;
									cin >> the_play;
									system("clear");
									GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
								}else{
									cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m TOOK \033[1;93;13m"<< you_damage <<  "\033[1;93;91m DAMAGE  BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
									cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
									cin >> the_play;
									system("clear");
									GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
								}
								select_card->setCooldown(2);
							}
						cout << "Please, \033[34mselect a card\033[0m to use" << endl;
						cin >> int_play;
						}
						else if(int_play == 2){
							cout << "Select a \033[91menemy\033[0m to attack" << endl;
						}else{
							cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
							cout << "Press a button to restore your intelligence" << endl;
							cin >> the_play;
							continue;
						}
					}else{
						cout << "Select a \033[91menemy\033[0m to attack" << endl;
					}
					cin >> int_play;
					bool advantage = false;
					Card* enemy_select_card = enemy_cards_on_field->SearchCard(int_play);
					if(enemy_select_card == nullptr){
						cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
						cout << "Press a button to restore your intelligence" << endl;
						cin >> the_play;
						continue;
					}
					if(enemy_select_card->getTanked() == true){
						cout << "You broken the enemy block!" << endl;
						enemy_select_card->setTanked(false);
						continue;
					}
					if(enemy_select_card->getType() == "Boss"){
						cout << "You selected the \033[95m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
					}else if(enemy_select_card->getType() == "Infantary"){
						cout << "You selected the \033[93m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() == "Boss" || select_card->getType() == "Mage" || select_card->getType() == "Ranger"){
							advantage = true;
						}
					}else if(enemy_select_card->getType() == "Mage"){
						cout << "You selected the \033[34m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() == "Boss" || select_card->getType() == "Tank" || select_card->getType() == "Ranger"){
							advantage = true;
						}
					}else if(enemy_select_card->getType() == "Tech"){
						cout << "You selected the \033[91m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() == "Boss" || select_card->getType() == "Infantary" || select_card->getType() == "Mage"){
							advantage = true;
						}
					}else if(enemy_select_card->getType() == "Tank"){
						cout << "You selected the \033[37m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() == "Boss" || select_card->getType() == "Tech"){
							advantage = true;
						}
					}else if(enemy_select_card->getType() == "Medic"){
						cout << "You selected the \033[96m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() != "Tank" || select_card->getType() != "Medic"){
							advantage = true;
						}
					}else if(enemy_select_card->getType() == "Ranger"){
						cout << "You selected the \033[92m" << enemy_select_card->getType() << " " << enemy_select_card->getName() << "\033[0m" << endl;
						if(select_card->getType() != "Medic" || select_card->getType() != "Ranger"){
							advantage = true;
						}
					}
					int decreasemage = enemy_cards_on_field->MagePassive();
					int increaseboss = your_cards_on_field->BossPassive();
					int you_damage = select_card->getStrength() - decreasemage + increaseboss;
					if(advantage){
						you_damage *= 1.5;
					}
					int enemy_to_eleminate = enemy_cards_on_field->Attack(int_play, you_damage);
					if(enemy_to_eleminate != -1){
						enemy_cards_on_field->RemoveCard(int_play);
						cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m WAS SLAIN BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
						cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
						enemy_count_field--;
						enemy_can_put_boss++;
						cin >> the_play;
						system("clear");
						GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
					}else{
						cout << "\033[1;93;91mTHE \033[1;93;13m" << enemy_select_card->getName() << "\033[1;93;91m TOOK \033[1;93;13m"<< you_damage <<  "\033[1;93;91m DAMAGE  BY \033[1;93;13m" << select_card->getName() << "\033[0;0;0m"<< endl;
						cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
						cin >> the_play;
						system("clear");
						GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
					}
				}//end of if verification enemy count
			}//end of for 
			if(puted){
				you_count_field++;
			}
		}//end of else
	cout << "\nPress some \033[34mbutton\033[0m to continue" << endl;
	cin >> the_play;
	}
	GameInterface(your_list, your_cards_on_field, enemy_cards_on_field);
	if(your_list->getQuantity() == 0){
		for(int i = 0; i<=200; i++){
			cout << "\033[" << i%8+30 <<"mYOU LOOSE, NOOOOB, TRASH!!!!! HAHAHAHA" << endl;
		}
		cout << "\033[0m";
		cout << endl;
	}
	if(enemy_list->getQuantity() == 0){
		cout << "NOT BAD :|" << endl;
	}
}

void GameInterface(List* your_list, List* your_cards_on_field, List* enemy_cards_on_field){
	//system("clear");
	cout << "Your Deck:" << endl;
	if(your_list->getQuantity() != 0){
		your_list->PrintList();
	}
	cout << "\n----------------------------------------" << endl;
	cout << "Your Cards on the field:" << endl;
	your_cards_on_field->PrintList();
	cout << "\n----------------------------------------" << endl;
	cout << "Enemy Cards on the field:" << endl;
	enemy_cards_on_field->PrintList();
	cout << "\n----------------------------------------" << endl;


}

List* PutACardOnField(List* your_list, List* your_cards_on_field, Card* put_card){
	
	your_cards_on_field->Insert(put_card);
	cout << "You put the ";
	PrintColor(put_card->getType());
	cout << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	
	return your_cards_on_field;
}

void PrintColor(string classe){
	if(classe == "Boss"){
		cout << "\033[95m";
	}else if(classe == "Infantary"){
		cout << "\033[93m";
	}else if(classe == "Mage"){
		cout << "\033[34m";
	}else if(classe == "Tech"){
		cout << "\033[91m";
	}else if(classe == "Tank"){
		cout << "\033[37m";
	}else if(classe == "Medic"){
		cout << "\033[96m";
	}else if(classe == "Ranger"){
		cout << "\033[92m";
	}
}

void Tutorial(){
	
	system("clear");
	cout << "\033[91m-=-=-=-=-=-=-=-= Hello player, welcome to the Tutorial! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "\033[96m1-This game is very simple: Win the game who defeat all the enemys." << endl;
	cout << "\033[91m2-Classes have advantage about others.\033[93m*" << endl;
	cout << "\033[96m3-Classes have active(have cooldowns, and count when the card enter on the field) and passive skills.\033[93m*" << endl;
	cout << "\033[91m4-A card have: Life, Strength, Sanity, and a Special Skill.\033[93m*" << endl;
	cout << "\033[96m5-The player can use 2 of this moves in the game: down a card on the field, attack a enemy, or use a active skill." << endl;
	cout << "\033[91m6-The player can play with does 3 races: SpaceMarines, Eldars and Orks, each race have quantity and diferent classes.\033[93m**" << endl;
	cout << "\033[96m7-The player can't put the Boss until he loses 3 cards." << endl;
	cout << "\033[91m8-Enjoy \033[96m:)\033[93m." << endl;
	cout << "*see about this on 'ClassTable' option." << endl;
	cout << "**see about this on 'About Races' option.\033[0m" << endl;
}

void ClassTable(){
	
	system("clear");
	cout << "\033[96m-=-=-=-=-=-=-=-= Hello player, welcome to the ClassTable! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "This is the ClassTable, the color represts if a class have advantage over another, \033[42mGreen = yes\033[0m, \033[101mRed = no\033[0m" << endl;
	cout << "If a class have advantage over another, the damage is increased by 1/2" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "|           |   \033[95mBoss\033[0m   | \033[93mInfantary\033[0m |   \033[34mMage\033[0m    |   \033[91mTech\033[0m    |   \033[37mTank\033[0m    |   \033[96mMedic\033[0m   |  \033[92mRanger\033[0m   |" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "| \033[95mBoss\033[0m      |\033[100m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[93mInfantary\033[0m |\033[101m          \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[34mMage\033[0m      |\033[101m          \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[91mTech\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[37mTank\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[96mMedic\033[0m     |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|" << endl;
	cout << "| \033[92mRanger\033[0m    |\033[101m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;

	cout << "\n-=-=-=-=-=-=-=-= Special Skills: =-=-=-=-=-=-=-=-" << endl;
	cout << "\n\033[1mPassives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : increase all allys attack + (Fury * 5% Strength)" << endl;
	cout << "\033[93mInfantary\033[0m: increase her attack + (Determination * 10% Strength)" << endl;
	cout << "\033[34mMage\033[0m     : all enemys take the when the round's player started(Intelligence * 10), increase defense of all allys (Intelligence * 10)." << endl;
	cout << "\033[91mTech\033[0m     : the player can play again." << endl;
	cout << "\033[37mTank\033[0m     : block the first attack." << endl;
	cout << "\033[96mMedic\033[0m    : cure all allys in (Cure * 20) when the round's player started." << endl;
	cout << "\033[92mRanger\033[0m   : when a enemy enter on the field, he's attacked with (Accuracy * 10% Strength)." << endl;
	cout << "\n\033[1mActives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : Tremmor(3 rounds): attack all enemys with her (Fury * 10% Strength)." << endl;
	cout << "\033[93mInfantary\033[0m: Battleon(2 rounds): attack 2 times." << endl;
	cout << "\033[34mMage\033[0m     : SpellWave(3 rounds): manipulate a enemy, depending of sanity of the enemy(10*Sanity - 60%)" << endl;
	cout << "\033[91mTech\033[0m     : Hacker(3 rounds): manipulate a enemy, depending of her (Hability * 5%)" << endl;
	cout << "\033[37mTank\033[0m     : Mountain(2 rounds): Select a ally to block your next damage" << endl;
	cout << "\033[96mMedic\033[0m    : Sunshine(2 round): Heal and give +500 HP for a ally." << endl;
	cout << "\033[92mRanger\033[0m   : Ragnarok(2 rounds): Select a enemy to give a critic shot(200% damage(25% chance))." << endl;
}

void AboutRaces(){

	system("clear");
	cout << "\033[96m-=-=-=-=-=-=-=-= Hello player, welcome to the AboutRaces! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "\033[1mSpaceMarines:\033[0m" << endl;
	cout << "\t The Space Marines or Adeptus Astartes are foremost amongst the defenders of humanity," << endl;
	cout << "\tthe greatest of the Emperor of Mankind's warriors. They are barely human at all, but superhuman;" << endl;
	cout << "\thaving been made superior in all respects to a normal man by a harsh regime of genetic modification," << endl;
	cout << "\tpsycho-conditioning and rigorous training." << endl;
	cout << "\033[1mEldars:\033[0m" << endl;
	cout << "\tThe Eldar or Aeldari as they were known in the Eldar Lexicon before the fall of their lost realm, " << endl;
	cout << "\tare an ancient humanoid alien race whose vast empire once extended the width and breadth of the known galaxy." << endl;
	cout << "\tTheir empire was without equal, and they counted themselves masters of the stars. The Eldar race has a" << endl;
	cout << "\tlong and complex spacefaring history, so long in fact that little is known for certain about the course of" << endl;
	cout << "\ttheir physical evolution and early planet-bound existence." << endl;
	cout << "\033[1mOrks:\033[0m" << endl;
	cout << "\tThe Orks, also called Greenskins, are a savage, warlike, green-skinned race of humanoids who are spread all" << endl;
 	cout << "\tacross the Milky Way Galaxy. They share many features with Warhammer Fantasy Orcs. They are seen by their " << endl;
 	cout << "\tenemies (pretty much everyone else in the universe) as savage, warlike, and crude, but they are the most " << endl;
 	cout << "\tsuccessful species in the whole galaxy, outnumbering possibly every other intelligent race, even Mankind." << endl;

 }