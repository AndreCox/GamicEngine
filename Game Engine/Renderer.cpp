#include "Renderer.h"
#include "Engine.h"
#include <string>
#include <algorithm>


Renderer::Renderer()
{
	// Sets default values
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;

	// Create a window
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

// Draws a sprite to the render target
void Renderer::drawSprite(sf::Sprite* sprite)
{

	renderer.draw(*sprite);
}

void Renderer::drawWorld(std::vector<AdvSprite*> sprites)
{	
	//std::sort(sprites.begin(), sprites.end(), spriteIsDeeper);

	int steps{ 0 };

	for (int Index{ 0 }; Index < static_cast<int>(sprites.size());)
	{
		if (sprites[Index]->depth > sprites[Index + 1]->depth)
		{
			std::swap(sprites[Index], sprites[Index + 1]);
			--Index;
		}
		else
			++Index;
		++steps;
	}

	for (int ii{ 0 }; ii < static_cast<int>(sprites.size()); ++ii)
	{
		drawSprite(sprites.at(ii));
	}
	
}

bool Renderer::spriteIsDeeper(AdvSprite* sprite1, AdvSprite* sprite2)
{
	return sprite1->depth > sprite2->depth;
}