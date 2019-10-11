#pragma once
#include "Game.h"
class Game;
class result:public IGameObject
{
public:
	result();
	~result();

	bool Start();

	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr;


};
