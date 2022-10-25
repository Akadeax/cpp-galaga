#include "pch.h"
#include "Game.h"
#include "bezier.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	std::vector<Point2f> array = std::vector<Point2f>(101);
}

void Draw()
{
	const int SQUARESIZE{ 50 };
	ClearBackground();
	Bezier urMom{};
	SetColor(1, 0, 0, 1);
	urMom = CalculateBezier(Point2f{ 500,500 }, Point2f{ 50,76 },
							Point2f{ 900,300 }, Point2f{ -200,4 });
	SetColor(1, 0, 0, 1);
	DrawBezier(urMom, 1);

	Point2f smootheBitches = Lerp(urMom.curvePoints[int(g_Offset)], urMom.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
	smootheBitches.x -= (SQUARESIZE / 2);
	smootheBitches.y -= (SQUARESIZE / 2);
	FillRect(smootheBitches,SQUARESIZE, SQUARESIZE);
	
	

}

void Update(float deltaTime)
{
	std::cout << (1 / deltaTime) << std::endl;
	g_Offset = (g_Offset + g_Speed * deltaTime);
	if (g_Offset >= BEZIER_STEPS_AMOUNT-1)
	{
		g_Offset = 0.f;
	}
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions