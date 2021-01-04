#pragma once

#include "Window.h"
#include <SFML/Window.hpp>

class Engine;

Engine* GetEngine();

class Engine
{
private:
	bool bEngineRunning;
	sf::Clock engineClock;
	sf::Time totalElapsedTimeLastFrame;

	Window* window;

public:
	Engine();
	~Engine();

	// Call this to start the engine
	virtual void Init();

	// Call this to quit the engine
	virtual void Exit();

protected:
	// Called once per frame
	virtual void Tick(float elapsedTime);

};

