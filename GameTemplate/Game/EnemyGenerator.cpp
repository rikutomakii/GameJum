#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"
#include "Enemy2.h"
EnemyGenerator::~EnemyGenerator()
{
}



void EnemyGenerator::enemyGenerator()
{
	count++;
	startFlag++;
	if (startFlag > 70 &&
		count >= r) {

		Enemy* enemy = NewGO<Enemy>(0);
		startFlag = 0;
		r = rand() % 400;
		count = 0;
	}

}
