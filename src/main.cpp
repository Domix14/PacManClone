#include "PacManGame.h"
#include "Engine.h"

int main()
{
	PacManGame game;
	Engine engine(&game);
	engine.start();
	
	return 0;
}