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

	while(1){
		system("clear");
		cout << "\033[96mChoose your race!\033[0m" << endl;
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
		cout << "Your deck: " << endl;
		your_list->PrintList();
		
		cout << "\033[96mChoose the enemy race!\033[0m" << endl;
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
		cout << "Enemy deck: " << endl;
		enemy_list->PrintList();
	}

}

List *ReadRace(string address){
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

void Tutorial(){

}

void ClassTable(){
	
	cout << "This is the ClassTable, the line represts if a class have advantage over another, \033[42mGreen = yes\033[0m, \033[101mRed = no\033[0m" << endl;

	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "|           |   \033[95mBoss\033[0m   | \033[93mInfantary\033[0m |   \033[34mMage\033[0m    |   \033[91mTech\033[0m    |   \033[37mTank\033[0m    |   \033[96mMedic\033[0m   |  \033[92mRanger\033[0m   |" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;
	cout << "| \033[95mBoss\033[0m      |\033[100m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[93mInfantary\033[0m |\033[101m          \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[34mMage\033[0m      |\033[101m          \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[91mTech\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[37mTank\033[0m      |\033[101m          \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|" << endl;
	cout << "| \033[96mMedic\033[0m     |\033[101m          \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[100m           \033[0m|\033[101m           \033[0m|" << endl;
	cout << "| \033[92mRanger\033[0m    |\033[101m          \033[0m|\033[42m           \033[0m|\033[42m           \033[0m|\033[101m           \033[0m|\033[101m           \033[0m|\033[42m           \033[0m|\033[100m           \033[0m|" << endl;
	cout << "+-----------+----------+-----------+-----------+-----------+-----------+-----------+-----------+" << endl;

	cout << "\nSpecial Skills:\n" << endl;
	cout << "\033[95mBoss\033[0m     : attack all the enemeys." << endl;
	cout << "\033[93mInfantary\033[0m: attack 2 times" << endl;
	cout << "\033[34mMage\033[0m     : manipulate someone enemy, depending of you sanity" << endl;
	cout << "\033[91mTech\033[0m     : play one more time" << endl;
	cout << "\033[37mTank\033[0m     : block the first attack" << endl;
	cout << "\033[96mMedic\033[0m    : heal fully a ally" << endl;
	cout << "\033[92mRanger\033[0m   : when a enemy enter on the field, he's attacked with 50% damage" << endl;
	
}

void AboutRaces(){


}