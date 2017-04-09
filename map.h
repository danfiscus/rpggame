#ifndef MAP_H
#define MAP_H

namespace game
{

	class map
	{
	public:
		//PUBLIC VARIABLES
		char currentscreen[120][30][3][3];	//MAIN MAP ONSCREEN -- [screencol][screenrow][maprow][mapcol]
		//PUBLIC FUNCTIONS
		void debuginitialize();	//Initialize grid while outputting current col number
		void debugdisplay();	//Display grid with each character on a new line, and also display the value of each dimension
		void initialize();
		void display(int,int);
	private:
		//PRIVATE VARIABLES
		const char highground = 176;	//░
		const char mediumground = 177;	//▒
		const char lowground = 178;		//▓
		const char dot = 250;			//·
		const char tlcorn = 201;		//╔
		const char trcorn = 187;		//╗
		const char blcorn = 200;		//╚
		const char brcorn = 188;		//╝
		const char vertline = 186;		//║
		const char horizline = 205;		//═
		//PRIVATE FUNCTIONS
		void generate();
	};
	void map::debuginitialize()
	{
		for(int maprow=0; maprow<3; maprow++) {
			char cmaprow = maprow+48;
			
			for(int mapcol=0; mapcol<3; mapcol++) {
				char cmapcol=mapcol+48;
				
				for(int screenrow=0; screenrow<30; screenrow++) {
					for(int screencol=0; screencol<120; screencol++) {
						//std::cout<<"screencol_set="<<screencol<<std::endl;		fuck this line.
						if(screenrow==0) {														//TOP ROW
							if(screencol==0) {													//FIRST COLUMN
								currentscreen[screencol][screenrow][maprow][mapcol]=tlcorn;		//TOP LEFT CORNER
							} else if(screencol==119) {											//LAST COLUMN
								currentscreen[screencol][screenrow][maprow][mapcol]=trcorn;		//TOP RIGHT CORNER
							}
							else{currentscreen[screencol][screenrow][maprow][mapcol]=horizline;}
						} else if(screenrow==29) {												//BOTTOM ROW
							if(screencol==0) {													//FIRST COLUMN
								currentscreen[screencol][screenrow][maprow][mapcol]=blcorn;		//BOTTOM LEFT CORNER
							} else if(screencol==119) {											//LAST COLUMN
								currentscreen[screencol][screenrow][maprow][mapcol]=brcorn;		//BOTTOM RIGHT CORNER
							}
							else{currentscreen[screencol][screenrow][maprow][mapcol]=horizline;}
						} else if(screencol==119||screencol==0) {currentscreen[screencol][screenrow][maprow][mapcol]=vertline;}
						else if(screenrow==15&&screencol==56) {currentscreen[screencol][screenrow][maprow][mapcol]='m';}
						else if(screenrow==15&&screencol==57) {currentscreen[screencol][screenrow][maprow][mapcol]='a';}
						else if(screenrow==15&&screencol==58) {currentscreen[screencol][screenrow][maprow][mapcol]='p';}
						else if(screenrow==15&&screencol==59) {currentscreen[screencol][screenrow][maprow][mapcol]='(';}
						else if(screenrow==15&&screencol==60) {currentscreen[screencol][screenrow][maprow][mapcol]=cmaprow;}
						else if(screenrow==15&&screencol==61) {currentscreen[screencol][screenrow][maprow][mapcol]=',';}
						else if(screenrow==15&&screencol==62) {currentscreen[screencol][screenrow][maprow][mapcol]=cmapcol;}
						else if(screenrow==15&&screencol==63) {currentscreen[screencol][screenrow][maprow][mapcol]=')';}
						else {currentscreen[screencol][screenrow][maprow][mapcol]=dot;}
					}
				}
			}
		}
	}
	void map::initialize()
	{
		for(int maprow=0; maprow<3; maprow++) {
			for(int mapcol=0; mapcol<3; mapcol++) {
				for(int screenrow=0; screenrow<30; screenrow++) {
					for(int screencol=0; screencol<120; screencol++) {
						if(screencol==0) {currentscreen[screencol][screenrow][maprow][mapcol]='B';}
						else if(screencol==119) {currentscreen[screencol][screenrow][maprow][mapcol]='E';}
						else {currentscreen[screencol][screenrow][maprow][mapcol]='A';}
					}
				}
			}
		}
	}
	void map::debugdisplay()
	{
		int selectedmaprow=0;
		int selectedmapcol=0;
		std::cout << "Pick the row of screens you want to display.\nRow (0-2): ";
		std::cin >> selectedmaprow;
		std::cout << "Pick the col within that row.\ncol (0-2): ";
		std::cin >> selectedmapcol;
		
		for(int screenrow=0; screenrow<30; screenrow++) {
			for(int screencol=0; screencol<120; screencol++) {
			
				std::cout << "maprow="<<selectedmaprow<<std::endl;
				std::cout << "mapcol="<<selectedmapcol<<std::endl;
				std::cout << "screenrow="<<screenrow<<std::endl;
				std::cout << "screencol="<<screencol<<std::endl;
				std::cout << "char value="<<currentscreen[screencol][screenrow][selectedmapcol][selectedmaprow]<<std::endl;
			}
		}
	}
	void map::display(int showmaprow,int showmapcol)
	{
		for(int screenrow=0; screenrow<30; screenrow++) {
			for(int screencol=0; screencol<120; screencol++) {
				std::cout << currentscreen[screencol][screenrow][showmapcol][showmaprow];
			}
		}
	}
}
#endif // MAP_H
