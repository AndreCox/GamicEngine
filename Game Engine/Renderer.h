#pragma once

//#include <SFML/Window.hpp>
#include "SFML/Graphics.hpp"

#define DEFAULT_RESOLUTION 600, 600
#define DEFAULT_WINDOW_TITLE "Window"

class Renderer
{
private:
	sf::RenderWindow renderer;

public: 
	Renderer();

	virtual void Tick(float elapsedTime);
};

