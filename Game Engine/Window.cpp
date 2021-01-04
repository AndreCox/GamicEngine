#include "Window.h"

Window::Window()
{
	window.create(sf::VideoMode(DEFAULT_RESOLUTION), DEFAULT_WINDOW_TITLE, sf::Style::Default);
}

void Window::Tick(float elapsedTime)
{
	// check all the window's events that were triggered since the last tick
	sf::Event event;
	while (window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			window.close();
	}
}