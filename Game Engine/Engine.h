#pragma once

#include "Window.h"
#include <SFML/Window.hpp>

class Engine;

Engine* GetEngine();

class Engine
{
private:
	bool bEngineRunning;
	// Used to check if the Init function has already been called
	bool bHasBeenPreviouslyInitialized;
	// Starts a clock to track the time the engine has been running
	sf::Clock engineClock;

	Window* window;

public:
	Engine();
	~Engine();

	// Call this to start the engine.  Calling this more than once does nothing.
	virtual void Init();

	// Call this to quit the engine
	virtual void Exit();

	// Returns the total time the engine has beein running, in seconds.
	float getTotalElapsedTime();

protected:
	// Called once per frame
	virtual void Tick(float elapsedTime);

};

