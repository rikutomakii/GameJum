#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Game.h"
EnemyGenerator::~EnemyGenerator()
{
	Enemy* enemy;
	DeleteGO(enemy->m_SkinModelRender);
}



void EnemyGenerator::enemyGenerator()
{
	count++;
	startFlag++;
	if (startFlag > 70 &&
		count >= r) {

		Enemy* enemy = NewGO<Enemy>(0);

		if (startFlag % 2 == 0) {
			Enemy2* enemy2 = NewGO<Enemy2>(0);
		}
		startFlag = 0;
		r = rand() % 400;
		count = 0;
	}
	Game* game;
	if (game->count2 == 10) {
		DeleteGO(this);
	}

}
