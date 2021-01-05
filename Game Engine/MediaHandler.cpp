#include "MediaHandler.h"
#include <string>
#include "SFML/Graphics.hpp"
#include "spdlog/spdlog.h"

sf::Texture MediaHandler::loadtexture()
{
	path = location + filename;
	if (path.substr(path.find_last_of(".") + 1) == "png" || path.substr(path.find_last_of(".") + 1) == "tga") //checks if file is a image file!
	{
		spdlog::info("png or tga image detected");	//logs that it has detected the file
		sf::Texture texture;
		texture.loadFromFile(path);
		return(texture);
	}
	else
	{
		spdlog::warn("Could not load texture! " + filename + " from " + path + "!");
	}
}
