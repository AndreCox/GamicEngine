#pragma once

//#include <SFML/Window.hpp>
#include "SFML/Graphics.hpp"

#define DEFAULT_RESOLUTION 600, 600
#define DEFAULT_WINDOW_TITLE "Window"

class Window
{
private:
	sf::RenderWindow window;

public: 
	Window();

	virtual void Tick(float elapsedTime);
};

