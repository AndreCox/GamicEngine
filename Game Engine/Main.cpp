
#include "TriangleShape.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
	// Hides the console window from popping up
	::ShowWindow(::GetConsoleWindow(), 0);

	// Enables anti-aliasing for smoother geometry
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Creates the graphics window
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!", sf::Style::Default, settings);

	// First parameter is radius, the second is the number of sides in the circle
	sf::CircleShape shape(300.f, 100);

	shape.setFillColor(sf::Color::Blue);


	// Triangle shape
	TriangleShape triangle;

	triangle.setPoint(0, sf::Vector2f(100.f, 50.f));
	triangle.setPoint(1, sf::Vector2f(50.f, 150.f));
	triangle.setPoint(2, sf::Vector2f(150.f, 150.f));

	sf::Color clearColor(0, 20, 50, 255);

	while (window.isOpen())
	{
		//window.setTitle(("mystring %));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear(clearColor);
		window.draw(triangle);
		window.display();
	}

	return 0;
}