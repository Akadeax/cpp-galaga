#include "pch.h"
#include "Game.h"
#include "bezier.h"
#include <iostream>
using std::cout;
using std::endl;

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	std::vector<Point2f> array = std::vector<Point2f>(101);
}

void Draw(float deltaTime)
{
	const int SQUARESIZE{ 50 };
	ClearBackground();
	SetColor(1, 0, 0, 1);
	FlightPath flightPath2{};
	Point2f smootheTransition{};
	flightPath2.windowWidth = g_WindowWidth;
	flightPath2.windowHeight = g_WindowHeight;
	flightPath2.pathWidth = 7.5f;
	flightPath2.pathHeight = 10;
	flightPath2.usedPaths = 5;
	flightPath2.xScaling = flightPath2.windowWidth / flightPath2.pathWidth;
	flightPath2.yScaling = flightPath2.windowHeight / flightPath2.pathHeight;

	flightPath2.paths.push_back(CalculateBezier(Point2f{ 0*flightPath2.xScaling,1*flightPath2.yScaling }, Point2f{ 2*flightPath2.xScaling,1.5f*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,3*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,5*flightPath2.yScaling }));

	flightPath2.paths.push_back(CalculateBezier(Point2f{ 6 * flightPath2.xScaling,5 * flightPath2.yScaling }, Point2f{ 6 * flightPath2.xScaling,8 * flightPath2.yScaling }, Point2f{ 6 * flightPath2.xScaling,8 * flightPath2.yScaling }, Point2f{ 5.25f * flightPath2.xScaling,8 * flightPath2.yScaling }));

	flightPath2.paths.push_back(CalculateBezier(Point2f{ 5.25f * flightPath2.xScaling,8 * flightPath2.yScaling }, Point2f{ 4.5f * flightPath2.xScaling,8 * flightPath2.yScaling }, Point2f{ 4.5f * flightPath2.xScaling,8 * flightPath2.yScaling }, Point2f{ 4.5f * flightPath2.xScaling,6.5f * flightPath2.yScaling }));

	flightPath2.paths.push_back(CalculateBezier(Point2f{ 4.5f * flightPath2.xScaling,6.5f * flightPath2.yScaling }, Point2f{ 4.5f * flightPath2.xScaling,5 * flightPath2.yScaling }, Point2f{ 4.5f * flightPath2.xScaling,5 * flightPath2.yScaling }, Point2f{ 5.25f * flightPath2.xScaling,5 * flightPath2.yScaling }));

	flightPath2.paths.push_back(CalculateBezier(Point2f{ 5.25f * flightPath2.xScaling,5 * flightPath2.yScaling }, Point2f{ 6 * flightPath2.xScaling,5 * flightPath2.yScaling }, Point2f{ 7 * flightPath2.xScaling,6 * flightPath2.yScaling }, Point2f{ 7.5f * flightPath2.xScaling,8 * flightPath2.yScaling }));

	for (int i{ 0 }; i < flightPath2.paths.size(); ++i)
	{
		DrawBezier(flightPath2.paths[i], 1);
	}

	std::vector<Point2f> combinedPaths = std::vector<Point2f>();

	for (int i{ 0 }; i < flightPath2.paths.size(); ++i)
	{
		const std::vector<Point2f>& current = flightPath2.paths[i].curvePoints;
		combinedPaths.insert(combinedPaths.end(), current.begin(), current.end());
	}
	
	if (g_Offset != combinedPaths.size()) {
		float distanceBetweenPoints = (sqrt(powf(combinedPaths[int(g_Offset + 1) ].x - combinedPaths[int(g_Offset) ].x,2) +
											  powf(combinedPaths[int(g_Offset + 1) ].y - combinedPaths[int(g_Offset) ].y,2)));
		g_Speed = g_BaseSpeed / distanceBetweenPoints;
	}
	//cout << g_Speed << " current speed" << endl;
	g_Offset = (g_Offset + (g_Speed*5) * deltaTime);
	if (g_Offset >=  504)
	{
		g_Offset = 0.f;
	}
	//cout << int(g_Offset) << " current startpoint" << endl;
	smootheTransition = Lerp(combinedPaths[int(g_Offset)], combinedPaths[int(g_Offset+1)], (float(int(g_Offset*100)%100)/100));

	smootheTransition.x -= (SQUARESIZE / 2);
	smootheTransition.y -= (SQUARESIZE / 2);
	FillRect(smootheTransition,SQUARESIZE, SQUARESIZE);
}

void Update(float deltaTime)
{
	//std::cout << (1 / deltaTime) << std::endl; // shows framerate
	
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