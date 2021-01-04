#pragma once

#include <SFML/Graphics.hpp>



class TriangleShape : public sf::ConvexShape
{
public:
	TriangleShape();
	TriangleShape(sf::Vector2f &point1, sf::Vector2f &point2, sf::Vector2f &point3);
};

