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

void Draw()
{
	const int SQUARESIZE{ 50 };
	ClearBackground();

	//Bezier urMom{};

	//SetColor(1, 0, 0, 1);
	//SetColor(1, 0, 0, 1);
	//urMom = CalculateBezier(Point2f{ 500,500 }, Point2f{ 50,76 },
	//						Point2f{ 900,300 }, Point2f{ -200,4 });
	SetColor(1, 0, 0, 1);
	/*DrawBezier(urMom, 1);*/
	FlightPath flightPath2{};
	Point2f smootheTransition{};
	flightPath2.windowWidth = g_WindowWidth;
	flightPath2.windowHeight = g_WindowHeight;
	flightPath2.pathWidth = 7.5f;
	flightPath2.pathHeight = 10;
	flightPath2.usedPaths = 5;
	flightPath2.xScaling = flightPath2.windowWidth / flightPath2.pathWidth;
	flightPath2.yScaling = flightPath2.windowHeight / flightPath2.pathHeight;

	flightPath2.path1 = CalculateBezier(Point2f{ 0*flightPath2.xScaling,1*flightPath2.yScaling }, Point2f{ 2*flightPath2.xScaling,1.5f*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,3*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,5*flightPath2.yScaling });
	flightPath2.path2 = CalculateBezier(Point2f{ 6*flightPath2.xScaling,5*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,8*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,8*flightPath2.yScaling }, Point2f{ 5.25f*flightPath2.xScaling,8*flightPath2.yScaling });
	flightPath2.path3 = CalculateBezier(Point2f{ 5.25f*flightPath2.xScaling,8*flightPath2.yScaling }, Point2f{ 4.5f*flightPath2.xScaling,8*flightPath2.yScaling }, Point2f{ 4.5f*flightPath2.xScaling,8*flightPath2.yScaling }, Point2f{ 4.5f*flightPath2.xScaling,6.5f*flightPath2.yScaling });
	flightPath2.path4 = CalculateBezier(Point2f{ 4.5f*flightPath2.xScaling,6.5f*flightPath2.yScaling }, Point2f{ 4.5f*flightPath2.xScaling,5*flightPath2.yScaling }, Point2f{ 4.5f*flightPath2.xScaling,5*flightPath2.yScaling }, Point2f{ 5.25f*flightPath2.xScaling,5*flightPath2.yScaling });
	flightPath2.path5 = CalculateBezier(Point2f{ 5.25f*flightPath2.xScaling,5*flightPath2.yScaling }, Point2f{ 6*flightPath2.xScaling,5*flightPath2.yScaling }, Point2f{ 7*flightPath2.xScaling,6*flightPath2.yScaling }, Point2f{ 7.5f*flightPath2.xScaling,8*flightPath2.yScaling });
	DrawBezier(flightPath2.path1, 1);
	DrawBezier(flightPath2.path2, 1);
	DrawBezier(flightPath2.path3, 1);
	DrawBezier(flightPath2.path4, 1);
	DrawBezier(flightPath2.path5, 1);

	switch(g_EnemyFlightpath2)
	{
	case(EnemyPathAnimationState::path1):
		smootheTransition = Lerp(flightPath2.path1.curvePoints[int(g_Offset)], flightPath2.path1.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
		break;
	case(EnemyPathAnimationState::path2):
		smootheTransition = Lerp(flightPath2.path2.curvePoints[int(g_Offset)], flightPath2.path2.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
		break;
	case(EnemyPathAnimationState::path3):
		smootheTransition = Lerp(flightPath2.path3.curvePoints[int(g_Offset)], flightPath2.path3.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
		break;
	case(EnemyPathAnimationState::path4):
		smootheTransition = Lerp(flightPath2.path4.curvePoints[int(g_Offset)], flightPath2.path4.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
		break;
	case(EnemyPathAnimationState::path5):
		smootheTransition = Lerp(flightPath2.path5.curvePoints[int(g_Offset)], flightPath2.path5.curvePoints[int(g_Offset) + 1], g_Offset - int(g_Offset));
		break;
	}
	smootheTransition.x -= (SQUARESIZE / 2);
	smootheTransition.y -= (SQUARESIZE / 2);
	FillRect(smootheTransition,SQUARESIZE, SQUARESIZE);
	
	

}

void Update(float deltaTime)
{
	//std::cout << (1 / deltaTime) << std::endl; // shows framerate
	g_Offset = (g_Offset + g_Speed * deltaTime);
	if (g_Offset >= BEZIER_STEPS_AMOUNT-1)
	{
		switch (g_EnemyFlightpath2)
		{
		case(EnemyPathAnimationState::path1):
			g_EnemyFlightpath2 = EnemyPathAnimationState::path2;
			break;
		case(EnemyPathAnimationState::path2):
			g_EnemyFlightpath2 = EnemyPathAnimationState::path3;
			break;
		case(EnemyPathAnimationState::path3):
			g_EnemyFlightpath2 = EnemyPathAnimationState::path4;
			break;
		case(EnemyPathAnimationState::path4):
			g_EnemyFlightpath2 = EnemyPathAnimationState::path5;
			break;
		case(EnemyPathAnimationState::path5):
			g_EnemyFlightpath2 = EnemyPathAnimationState::path1;
			break;
		}
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