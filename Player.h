#pragma once
class Texture;

class Player
{
public:
	Player();
	void UpdatePlayer(float deltaTime);
	void DrawPlayer();
private:
	Texture* m_pTexture;
	float m_Speed{ 20.f };
};
