#include <iostream>
#include <conio.h>
//#include "gameheaders.h"
#include "map.h"
//#include "numinput.h"
using namespace std;

#define w_key 119
#define a_key 97
#define s_key 115
#define d_key 100
#define q_key 113

void beep();
int main()
{
	int currentmaprow=1;
	int currentmapcol=1;
	int newmaprow=1;
	int newmapcol=1;
	int inch;
	bool done=false;
	game::map newmap;
	newmap.debuginitialize();
	newmap.display(newmaprow,newmapcol);
	do {
		inch = _getch();
		switch(inch) {
			case w_key:
				//cout << "w"<<endl;
				if(currentmaprow>0) {newmaprow--;}
				else {beep();}
				break;
			case a_key:
				//cout<<'a'<<endl;
				if(currentmapcol>0) {newmapcol--;}
				else {beep();}
				break;
			case s_key:
				//cout<<'s'<<endl;
				if(currentmaprow<2) {newmaprow++;}
				else {beep();}
				break;
			case d_key:
				//cout<<'d'<<endl;
				if(currentmapcol<2) {newmapcol++;}
				else {beep();}
			case q_key:
				//cout<<'q'<<endl;
				done=true;
				break;
			default:
				beep();
				break;
		}
		if(newmapcol!=currentmapcol||newmaprow!=currentmaprow) {
			newmap.display(newmaprow,newmapcol);
			currentmapcol = newmapcol;
			currentmaprow = newmaprow;
		}
	} while(!done);
	return 0;
}
void beep()
{
	cout << '\a';
}
