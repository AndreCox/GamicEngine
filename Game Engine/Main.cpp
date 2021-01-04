
#include "Engine.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <gl/GLU.h>
#include "spdlog/spdlog.h"
#include <SFML/Graphics/Sprite.hpp>


////////////////////////////////////////////////////////////
/// Entry point of application
////////////////////////////////////////////////////////////


static Engine* engine;

Engine* GetEngine()
{
	return engine;
}

int main()
{
	spdlog::info("TEST");

	if (engine == nullptr)
		engine = { new Engine };

	engine->Init();
	
	delete engine;
}

