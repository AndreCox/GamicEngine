#include "MediaHandler.h"
#include <string>
#include "SFML/Graphics.hpp"
#include "spdlog/spdlog.h"

sf::Texture MediaHandler::loadtexture(std::string path)
{
	if (path.substr(path.find_last_of(".") + 1) == "png" || path.substr(path.find_last_of(".") + 1) == "tga") //checks if file is a image file!
	{
		spdlog::info("png or tga image detected");	//logs that it has detected the file
		sf::Texture texture;
		texture.loadFromFile(path);
		return(texture);
	}
	else
	{
		spdlog::warn("Could not load texture! From " + path + "!");
	}
}

sf::Font MediaHandler::loadfont(std::string path)
{
	if (path.substr(path.find_last_of(".") + 1) == "ttf" || path.substr(path.find_last_of(".") + 1) == "otf") //checks if file is a image file!
	{
		spdlog::info("ttf or otf font detected");	//logs that it has detected the file
		sf::Font font;
		font.loadFromFile(path);
		return(font);
	}
	else
	{
		spdlog::warn("Could not load font! From " + path + "!");
	}
}
/*
sf::SoundBuffer MediaHandler::loadsound(std::string path)
{
	if (path.substr(path.find_last_of(".") + 1) == "wav" || path.substr(path.find_last_of(".") + 1) == "ogg") //checks if file is a image file!
	{
		spdlog::info("png or tga image detected");	//logs that it has detected the file
		sf::SoundBuffer sound;
		sound.loadFromFile(path);
		return(sound);
	}
	else
	{
		spdlog::warn("Could not load sound! From " + path + "!");
	}
}
*/

/*
file type number codes

0 = textures
1 = fonts
2 = sounds

*/

void MediaHandler::pulldata(std::string path, int type) //Function called to load in a specific media type using functions declared above.
{
	switch (type)
	{
	case 0:
		spdlog::info("Texure type detected.");
		loadtexture(path);	
		break;
	case 1:
		spdlog::info("Font type detected.");
		loadfont(path);
		break;
	case 2:
		spdlog::info("Sound type detected.");
		//loadsound(path);
		break;
	}
	
}

