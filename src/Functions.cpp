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
	List* your_cards_on_field = new List();
	List* enemy_cards_on_field = new List();
	while(1){
		system("clear");
		if((your_list->getQuantity() == 0 && your_cards_on_field == 0)|| (enemy_list->getQuantity() == 0 && enemy_cards_on_field == 0)){
			break;
		}
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
		if(you_count_field == 0){
			cout << "Please..." << endl;
			cout << "(1)Pull a card" << endl;
		}else if(your_list->getQuantity() != 0){
			cout << "What do you want to do?" << endl;
			cout << "(1)Pull a card" << endl;
			cout << "(2)Select a card" << endl;
		}else{
			cout << "Please..." << endl;
			cout << "(1)Select a card" << endl;
		}
		cin >> the_play;
		if(you_count_field == 0){
			if(the_play == '1'){
				cout << "Select a card" << endl;
				cin >> int_play;
				Card* put_card = your_list->SearchCard(int_play);
				if(put_card == nullptr){
					cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
					cout << "Press a button to restore your intelligence" << endl;
					cin >> the_play;
					continue;
				}
				your_cards_on_field->Insert(put_card);
				you_count_field++;

				if(put_card->getType() == "Boss"){
					cout << "You inserted the \033[95m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Infantary"){
					cout << "You inserted the \033[93m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Mage"){
					cout << "You inserted the \033[34m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Tech"){
					cout << "You inserted the \033[91m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Tank"){
					cout << "You inserted the \033[37m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Medic"){
					cout << "You inserted the \033[96m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Ranger"){
					cout << "You inserted the \033[92m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}
				your_list->RemoveCard(int_play);
			}else{
				cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
				cout << "Press a button to restore your intelligence" << endl;
				cin >> the_play;
				continue;
			}
		}else if(your_list->getQuantity() != 0){
			if(the_play == '1'){
				cout << "Select a card" << endl;
				cin >> int_play;
				Card* put_card = your_list->SearchCard(int_play);
				if(put_card == nullptr){
					cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
					cout << "Press a button to restore your intelligence" << endl;
					cin >> the_play;
					continue;
				}
				your_cards_on_field->Insert(put_card);
				you_count_field++;

				if(put_card->getType() == "Boss"){
					cout << "You inserted the \033[95m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Infantary"){
					cout << "You inserted the \033[93m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Mage"){
					cout << "You inserted the \033[34m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Tech"){
					cout << "You inserted the \033[91m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Tank"){
					cout << "You inserted the \033[37m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Medic"){
					cout << "You inserted the \033[96m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}else if(put_card->getType() == "Ranger"){
					cout << "You inserted the \033[92m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
				}
				your_list->RemoveCard(int_play);
			}else if(the_play == '2'){


			}else{
				cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
				cout << "Press a button to restore your intelligence" << endl;
				cin >> the_play;
				continue;
			}
		}else{
			if(the_play == '1'){
				cout << "Select a card" << endl;
				cin >> int_play;
			}else{
				cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
				cout << "Press a button to restore your intelligence" << endl;
				cin >> the_play;
				continue;
			}
		}




		if(enemy_list->getQuantity() !=0){ // Inimigo coloca carta aleatoria
			int random = (rand() % enemy_list->getQuantity()) + 1;
			Card* put_card = enemy_list->SearchCard(random);
			enemy_cards_on_field->Insert(put_card);
			enemy_count_field++;
			enemy_list->RemoveCard(random);
		}

	

	}
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

void Tutorial(){
	
	system("clear");
	cout << "\033[96m-=-=-=-=-=-=-=-= Hello player, welcome to the Tutorial! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "\033[2;4;3m1-This game is very simple: Win the game who defeat all the enemys" << endl;
	cout << "2-Classes have advantage about others, you can see this on 'ClassTable' option" << endl;
	cout << "3-Classes have active and passive skills, you can see this on 'ClassTable' option" << endl;
	cout << "4-A card have: Life, Strength, Sanity, and a Special Skill, that you can see on 'ClassTable' option" << endl;
	cout << "5-The player can use 2 of this moves in the game: down a card on the field, attack a enemy, or use a active skill" << endl;
	cout << "6-The player can play with does 3 races: SpaceMarines, Eldars and Orks, each race have quantity" << endl;
	cout << "and diferent classes, you can see about this on 'About Races' option" << endl;
	cout << "\033[96m7-Enjoy\033[0;91m :)\033[0;0;0m" << endl;
}

void ClassTable(){
	
	system("clear");
	cout << "\033[96m-=-=-=-=-=-=-=-= Hello player, welcome to the ClassTable! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "This is the ClassTable, the color represts if a class have advantage over another, \033[42mGreen = yes\033[0m, \033[101mRed = no\033[0m" << endl;

	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "|           |   \033[95mBoss\033[0m   | \033[93mInfantary\033[0m |   \033[34mMage\033[0m    |   \033[91mTech\033[0m    |   \033[37mTank\033[0m    |   \033[96mMedic\033[0m   |  \033[92mRanger\033[0m   |" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "| \033[95mBoss\033[0m      |\033[100m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[93mInfantary\033[0m |\033[101m          \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[34mMage\033[0m      |\033[101m          \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[91mTech\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[37mTank\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[96mMedic\033[0m     |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|" << endl;
	cout << "| \033[92mRanger\033[0m    |\033[101m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;

	cout << "\n-=-=-=-=-=-=-=-= Special Skills: =-=-=-=-=-=-=-=-" << endl;
	cout << "Passives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : increase all allys attack + (Fury * 5% Strength)" << endl;
	cout << "\033[93mInfantary\033[0m: increase her attack + (Determination * 10% Strength)" << endl;
	cout << "\033[34mMage\033[0m     : all enemys take the Mage intelligence * 10 damage, increase defense of all allys Mage intelligence * 10." << endl;
	cout << "\033[91mTech\033[0m     : play one more time." << endl;
	cout << "\033[37mTank\033[0m     : block the all the first attack." << endl;
	cout << "\033[96mMedic\033[0m    : cure all allys in Medic Cure * 20." << endl;
	cout << "\033[92mRanger\033[0m   : when a enemy enter on the field, he's attacked with Ranger Accuracy * 10% damage." << endl;
	cout << "Actives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : Tremmor: attack all enemys with her Fury * 10% Strength." << endl;
	cout << "\033[93mInfantary\033[0m: Battleon: attack 2 times." << endl;
	cout << "\033[34mMage\033[0m     : SpellWave: manipulate a enemy, depending of his sanity." << endl;
	cout << "\033[91mTech\033[0m     : Hacker: manipulate a enemy, depending of his special hability" << endl;
	cout << "\033[37mTank\033[0m     : Mountain: Select a ally to block your next damage" << endl;
	cout << "\033[96mMedic\033[0m    : Sunshine: heal fully a ally." << endl;
	cout << "\033[92mRanger\033[0m   : Ragnarok: attack again." << endl;
}

void AboutRaces(){

	system("clear");
	cout << "\033[96m-=-=-=-=-=-=-=-= Hello player, welcome to the AboutRaces! =-=-=-=-=-=-=-=-\033[0m\n" << endl;
	cout << "SpaceMarines:" << endl;
	cout << "\t The Space Marines or Adeptus Astartes are foremost amongst the defenders of humanity," << endl;
	cout << "the greatest of the Emperor of Mankind's warriors. They are barely human at all, but superhuman;" << endl;
	cout << "having been made superior in all respects to a normal man by a harsh regime of genetic modification," << endl;
	cout << "psycho-conditioning and rigorous training." << endl;
	cout << "Eldars:" << endl;

	cout << "Orks:" << endl;
}