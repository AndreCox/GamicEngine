
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

// This is where we reference the instance of our Engine.  This is static so that it is only 
// accessible in this code file.  Use GetEngine() for other files.
static Engine* engine;

// Global function that gets the Engine instance.  All that is required to use this in any 
// code is to #include Engine.h
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
	
	// If there doesn't exist one already, create an instance of the Engine
	if (engine == nullptr)
		engine = { new Engine };
	
	// Initialize the Engine
	engine->Init();
	
	// Deallocates memory to Engine before we close down
	delete engine;
}

