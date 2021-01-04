
#include "Engine.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <gl/GLU.h>
#include "spdlog/spdlog.h"
#include "MediaHandler.h"
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
	spdlog::info("Starting!");
	
	MediaHandler testimg;
	testimg.location = "GameData/images/"; //set location of image files
	testimg.filename = "testimg.png";   //set the filename to load
	testimg.loadmedia(); //call the loadmedia to load the file

	if (engine == nullptr)
		engine = { new Engine };

	engine->Init();
	
	delete engine;
}

