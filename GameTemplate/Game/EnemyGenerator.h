#pragma once
#include "Enemy.h"
#include "Enemy2.h"
#include "Game.h"
class EnemyGenerator : public IGameObject
{
public:
	~EnemyGenerator();
	void enemyGenerator();
	int startFlag = 0;
	int count = 0;
	float m_timer = 19.0f;
	int r = rand() %400;
	
};

