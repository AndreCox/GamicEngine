#include "Engine.h"
#include <SFML/Window.hpp>
#include <Windows.h>




Engine::Engine()
{
	// Sets default values
	renderer = nullptr;
	bHasBeenPreviouslyInitialized = false;
}

Engine::~Engine()
{
	delete renderer;
}

void Engine::Init()
{
	// Check if this is a duplicate call to Init().  If it is, don't call the function (it can only be called once)
	if (bHasBeenPreviouslyInitialized == true)
		return;

	// Start the clock to track the time the engine has been running
	engineClock.restart();

	// Hide the default console window
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	// Instantiate a Window class
	if (renderer == nullptr)
		renderer = new Renderer{};


	// Start the engine 
	bEngineRunning = true;
	float previousTotalElapsedTime{ 0 };
	while (bEngineRunning)
	{
		// Call the tick function, and pass the elapsed time since last frame
		float totalElapsedTime = engineClock.getElapsedTime().asSeconds();
		Tick(totalElapsedTime - previousTotalElapsedTime);

		// Set this so that wthe next frame can reference this frame's elapsed time
		previousTotalElapsedTime = totalElapsedTime;
	}
}

void Engine::Tick(float elapsedTime)
{
	// Call tick on the window subframework
	renderer->Tick(elapsedTime);
}

void Engine::Exit()
{
	bEngineRunning = false;
}

float Engine::getTotalElapsedTime()
{
	return engineClock.getElapsedTime().asSeconds();
}
