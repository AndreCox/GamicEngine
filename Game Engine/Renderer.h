#pragma once

#include "SFML/Graphics.hpp"
#include "AdvSprite.h"
#include <vector>

// These define the default values for a viewport.
#define DEFAULT_RESOLUTION 600, 600
#define DEFAULT_WINDOW_TITLE "Window"

class Renderer
{
private:
	// This stores the window so that we can reference it fo rthings like draw calls
	sf::RenderWindow renderer;

	// Checks if a sprite is behind another sprite (is the depth of sprite1 greater than the depth of sprite2)
	// This is used for rendering order.
	bool spriteIsDeeper(AdvSprite* sprite1, AdvSprite* sprite2);

public: 
	// Default constructor
	Renderer();

	// Called every frame
	virtual void Tick(float elapsedTime);

	// Draws a sprite to the renderer
	void drawSprite(sf::Sprite* sprite);

	// Draws an array of advanced sprites
	void drawWorld(std::vector<AdvSprite*> sprites);
};

