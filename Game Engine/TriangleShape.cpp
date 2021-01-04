#include "TriangleShape.h"

TriangleShape::TriangleShape()
{
	setPointCount(3);
}

TriangleShape::TriangleShape(sf::Vector2f &point1, sf::Vector2f &point2, sf::Vector2f &point3)
{
	setPointCount(3);
	setPoint(0, point1);
	setPoint(1, point2);
	setPoint(2, point3);
}
