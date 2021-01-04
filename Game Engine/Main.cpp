
#include "Engine.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <gl/GLU.h>
#include "spdlog/spdlog.h"

////////////////////////////////////////////////////////////
/// Entry point of application
////////////////////////////////////////////////////////////


static Engine* myEngine;

Engine* GetEngine()
{
	return myEngine;
}

int main()
{
	spdlog::info("TEST");

	if (myEngine == nullptr)
		myEngine = { new Engine };

	myEngine->Init();
	
	delete myEngine;
}

