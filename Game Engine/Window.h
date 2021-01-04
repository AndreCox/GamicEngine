#pragma once

#include "Engine.h"
#include <SFML/Window.hpp>

#define DEFAULT_RESOLUTION 600, 600
#define DEFAULT_WINDOW_TITLE "Window"

class Window
{
private:
	sf::Window window;

	

public: 
	Window();

	virtual void Tick(float elapsedTime);
};

