#pragma once
#include <string>
#include "SFML/Graphics.hpp"
class MediaHandler
{
public:
	std::string location; //location of file
	std::string filename; //file name of file
	sf::Texture loadtexture(); //function called to load the media.
private:
	std::string path;
	


};

