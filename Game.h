#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 1080 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_BaseSpeed{100};
float g_Offset{};
float g_Speed{ 10 };
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float deltaTime);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
