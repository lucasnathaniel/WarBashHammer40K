/**
  *@title WarBashHammer40K
  *@file main.cpp
  *@version 1.0
  *@date 30/05/2017
  *@author Lucas Nathaniel
  *@brief principal funcao do programa
  *@section LICENSE
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the GNU General Public License as
  * published by the Free Software Foundation; either version 2 of
  * the License, or (at your option) any later version.
  * 
  * This program is distributed in the hope that it will be useful, but
  * WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  * General Public License for more details at
  * http://www.gnu.org/copyleft/gpl.html
  *
  */

#include "main.h"

using namespace std;
/**
  *@brief principal função do programa
  */
int main(){

	string start;
	char option;
	char button;
	while(1){
		system("clear");
		Interface();
   		cout << endl;
   		cin >> start;
   		if(start != "start"){
   			continue;
   		}
   		cout << "Choose someone option: " << endl;
   		cout << "(1) Start Game" << endl;
		cout << "(2) Tutorial" << endl;
		cout << "(3) Class Table" << endl;
		cout << "(4) About Races" << endl;
		cout << "(5) Exit" << endl;
		cin >> option;
		switch(option){
			case '1':
				StartGame();
				cout << "Press someone button" << endl;
				cin >> button;
				break;
			case '2':
				Tutorial();
				cout << "Press someone button" << endl;
				cin >> button;
				break;
			case '3':
				ClassTable();
				cout << "Press someone button" << endl;
				cin >> button;
				break;
			case '4':
				AboutRaces();
				cout << "Press someone button" << endl;
				cin >> button;
				break;
			case '5':
				cout << "Come back often! :)" << endl;
				return 0;
				break;
			default:
				cout << "Incorrect digit!" << endl;
				cout << "Press someone button" << endl;
				cin >> button;
				break;
		}
	}

	return 0;
}