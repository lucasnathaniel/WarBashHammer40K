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
		
		if(you_count_field == 0){ //If dont have cards on field and and have cards on hand
			cout << "Please, select a card to put" << endl;
			cin >> int_play;
			Card* put_card = your_list->SearchCard(int_play);
			if(put_card != nullptr){
				your_cards_on_field = PutACardOnField(your_list, your_cards_on_field, put_card);
				you_count_field++;
				your_list->RemoveCard(int_play);
			}else{
				cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
				cout << "Press a button to restore your intelligence" << endl;
				cin >> the_play;
			}
		}else{
			if(your_list->getQuantity() != 0){ //If have cards on field and cards on hand
				cout << "Please, select a card to put" << endl;
				cin >> int_play;
				Card* put_card = your_list->SearchCard(int_play);
				if(put_card != nullptr){
					your_cards_on_field = PutACardOnField(your_list, your_cards_on_field, put_card);
					you_count_field++;
					your_list->RemoveCard(int_play);
				}else{
					cout << "\033[91mYou idiot, lost the turn\033[0m" << endl;
					cout << "Press a button to restore your intelligence" << endl;
					cin >> the_play;
					continue;
				}
			}
			cout << "Please, select a card to use" << endl;
			cin >> int_play;
		}
			


		if(enemy_list->getQuantity() !=0){ // Inimigo coloca carta aleatoria
			int random = (rand() % enemy_list->getQuantity()) + 1;
			Card* put_card = enemy_list->SearchCard(random);
			enemy_cards_on_field->Insert(put_card);
			enemy_count_field++;
			string enemy_type = put_card->getType();
			string enemy_name = put_card->getName();
			enemy_list->RemoveCard(random);
			if(enemy_type == "Boss"){
				cout << "The enemy put \033[95m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Infantary"){
				cout << "The enemy put \033[93m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Mage"){
				cout << "The enemy put \033[34m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Tech"){
				cout << "The enemy put \033[91m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Tank"){
				cout << "The enemy put \033[37m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Medic"){
				cout << "The enemy put \033[96m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}else if(enemy_type == "Ranger"){
				cout << "The enemy put \033[92m" << enemy_type << " " << enemy_name << "\033[0m on the field" << endl;
			}
		}
		cout << "\nPress some button to continue" << endl;
		cin >> the_play;
	

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

List* PutACardOnField(List* your_list, List* your_cards_on_field, Card* put_card){
	
	your_cards_on_field->Insert(put_card);
	
	if(put_card->getType() == "Boss"){
		cout << "You put the \033[95m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Infantary"){
		cout << "You put the \033[93m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Mage"){
		cout << "You put the \033[34m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Tech"){
		cout << "You put the \033[91m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Tank"){
		cout << "You put the \033[37m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Medic"){
		cout << "You put the \033[96m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}else if(put_card->getType() == "Ranger"){
		cout << "You put the \033[92m" << put_card->getType() << " " << put_card->getName() << "\033[0m on the field" << endl;
	}
	return your_cards_on_field;
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
	cout << "| \033[91mTech\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[37mTank\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[96mMedic\033[0m     |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|" << endl;
	cout << "| \033[92mRanger\033[0m    |\033[101m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;

	cout << "\n-=-=-=-=-=-=-=-= Special Skills: =-=-=-=-=-=-=-=-" << endl;
	cout << "\n\033[1mPassives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : increase all allys attack + (Fury * 5% Strength)" << endl;
	cout << "\033[93mInfantary\033[0m: increase her attack + (Determination * 10% Strength)" << endl;
	cout << "\033[34mMage\033[0m     : all enemys take the (Intelligence * 10), increase defense of all allys (Intelligence * 10)." << endl;
	cout << "\033[91mTech\033[0m     : the player can play again." << endl;
	cout << "\033[37mTank\033[0m     : block the all the first attack." << endl;
	cout << "\033[96mMedic\033[0m    : cure all allys in (Cure * 20)." << endl;
	cout << "\033[92mRanger\033[0m   : when a enemy enter on the field, he's attacked with (Accuracy * 10% Strength)." << endl;
	cout << "\n\033[1mActives:\n" << endl;
	cout << "\033[95mBoss\033[0m     : Tremmor(3 rounds): attack all enemys with her (Fury * 10% Strength)." << endl;
	cout << "\033[93mInfantary\033[0m: Battleon(2 rounds): attack 2 times." << endl;
	cout << "\033[34mMage\033[0m     : SpellWave(3 rounds): manipulate a enemy, depending of sanity of the enemy(10*Sanity - 60%)" << endl;
	cout << "\033[91mTech\033[0m     : Hacker(3 rounds): manipulate a enemy, depending of her (Hability * 5%)" << endl;
	cout << "\033[37mTank\033[0m     : Mountain(2 rounds): Select a ally to block your next damage" << endl;
	cout << "\033[96mMedic\033[0m    : Sunshine(1 round): heal fully a ally." << endl;
	cout << "\033[92mRanger\033[0m   : Ragnarok(2 rounds): Select a enemy to give a explosed shot(Accuracy * 20% Strength)." << endl;
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