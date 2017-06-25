#include "Jokenpo.h"

namespace Jokenpo{
	int PlayJokenpo(){
		srand (time(NULL));
		cout << "Choose a option" << endl;
		cout << "(1)Paper" << endl;
		cout << "(2)Rock" << endl;
		cout << "(3)scissor" << endl;
		int deathlord = (rand() % 3) + 1;
		int you;
		cin >> you;
		if(you != 1 && you != 2 && you != 3){
			cout << "U really idiot" << endl;
			return -1;
		}
		if(you == deathlord){
			cout << "draw, play again" << endl;
			return 0;
		}else if((you == 3 && deathlord == 1) || (you < deathlord)){
			cout << "U win, not bad :|" << endl;
			return 1;
		}else{
			cout << "U loose, u newbie lucker" << endl;
			return -1;
		}
	}
}