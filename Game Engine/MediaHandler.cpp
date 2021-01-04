#include "MediaHandler.h"
#include <string>
#include "SFML/Graphics.hpp"
#include "spdlog/spdlog.h"

void MediaHandler::loadmedia()
{
	path = location + filename;
	if (path.substr(path.find_last_of(".") + 1) == "png" || path.substr(path.find_last_of(".") + 1) == "tga") //checks if file is a image file!
	{
		spdlog::info("png or tga image detected");	//logs that it has detected the file
		sf::Image image;
		image.loadFromFile(path);
	}
	else
	{
		spdlog::warn("Could not load file! " + filename + " from " + path + "!");
	}
}
