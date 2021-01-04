#include "MediaHandler.h"
#include <string>
#include "SFML/Graphics.hpp"
#include "spdlog/spdlog.h"

void MediaHandler::loadmedia()
{
	path = location + filename;
	if (path.substr(path.find_last_of(".") + 1) == "png" || "tga")
	{
		spdlog::info("png or tga image detected");
		sf::Image image;
		image.loadFromFile(path);
	}
	else
	{

	}
}
