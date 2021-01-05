#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class MediaHandler
{
public:
	sf::Texture loadtexture(std::string path); //function called to load textures.
	sf::Font loadfont(std::string path); //function called to load fonts
	sf::SoundBuffer loadsound(std::string path); //function called to load sound
	//void pulldata(std::string path);
};



