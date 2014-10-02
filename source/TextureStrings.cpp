#include "TextureStrings.h"

TextureStrings::TextureStrings(void) {
	for(int i=0; i<27; ++i) {
		std::stringstream temp;
		temp << "./images/kenneyRoad/roadTile" << (i+1) << ".png";
		road.push_back(temp.str());
	}
	for(int i=0; i<6; ++i) {
		std::stringstream temp;
		temp << "./images/kenneyRoad/terrainTile" << (i+1) << ".png";
		terrain.push_back(temp.str());
	}
	for(int i=0; i<46; ++i) {
		std::stringstream temp;
		temp << "./images/kenneyRoad/waterTile" << (i+1) << ".png";
		water.push_back(temp.str());
	}

}

TextureStrings::~TextureStrings(void) {


}
