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
int main(){

	string start;
	while(1){
		system("clear");
		Interface();
   		cout << endl;
   		cin >> start;
   		if(start != "start"){
   			continue;
   		}
	}

	return 0;
}