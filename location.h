#ifndef LOCATION_H
#define LOCATION_H

namespace game
{
	enum elevationkey {low,medium,high};
	class location
	{
		public:
			elevationkey elevation;
			float mapcompx;		//SHOULD ALWAYS BE IN THE FORM OF
			float mapcompy;		//integer mapscreen.submap (for example 3.4 is the third big map screen, 4 is the fourth pixel in that map)

		private:
			int mapnumbr
	}
}
