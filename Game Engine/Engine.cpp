#include "Engine.h"
#include <SFML/Window.hpp>
#include <Windows.h>


Engine::Engine()
{
	totalElapsedTimeLastFrame.Zero;
	window = nullptr;
}

Engine::~Engine()
{
	delete window;
}

void Engine::Init()
{
	// Start the clock to track the time the engine has been running
	engineClock.restart();

	// Hide the default console window
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	// Instantiate a Window class
	if (window == nullptr)
		window = new Window{};

	// Start the engine 
	bEngineRunning = true;
	while (bEngineRunning)
	{
		// Call the tick function, and pass the elapsed time since last frame
		Tick((engineClock.getElapsedTime() - totalElapsedTimeLastFrame).asSeconds());

		// Set this so that wthe next frame can reference this frame's elapsed time
		totalElapsedTimeLastFrame = engineClock.getElapsedTime();
	}
}

void Engine::Tick(float elapsedTime)
{
	// Call tick on the window subframework
	window->Tick(elapsedTime);
}

void Engine::Exit()
{
	bEngineRunning = false;
}
