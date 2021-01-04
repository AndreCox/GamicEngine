#include "Window.h"
#include "Engine.h"
#include <string>

Window::Window()
{
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(DEFAULT_RESOLUTION), DEFAULT_WINDOW_TITLE, sf::Style::Default, context_settings);
}

void Window::Tick(float elapsedTime)
{
	// check all the window's events that were triggered since the last tick
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window.close();
			GetEngine()->Exit();
		}
	}

	window.clear(sf::Color(0, 20, 50, 255));

	window.display();
	
	// Set the window title to display the fps
	window.setTitle(std::to_string(1.f / elapsedTime));
}