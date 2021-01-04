#include "Renderer.h"
#include "Engine.h"
#include <string>

Renderer::Renderer()
{
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	renderer.create(sf::VideoMode(DEFAULT_RESOLUTION), DEFAULT_WINDOW_TITLE, sf::Style::Default, context_settings);
}

void Renderer::Tick(float elapsedTime)
{
	// Set the window title to display the fps
	renderer.setTitle(std::to_string(1.f / elapsedTime));

	// check all the window's events that were triggered since the last tick
	sf::Event event;
	while (renderer.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			renderer.close();
			GetEngine()->Exit();
		}
	}

	// Set the background
	renderer.clear(sf::Color(0, 20, 50, 255));

	// Draw the scene

	renderer.display();
	
	
}