#pragma once

#include <SFML/Graphics/Sprite.hpp>

// A tile is a sprite with position data

class AdvSprite : public sf::Sprite
{
public:
	int depth;
};

