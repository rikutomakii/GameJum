#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Game.h"
#include "BackGround.h"
EnemyGenerator::~EnemyGenerator()
{
	Enemy enemy;
	DeleteGO(enemy.m_SkinModelRender);

}



void EnemyGenerator::enemyGenerator()
{
	count++;
	startFlag++;//‚É‚á[‚ñ(LEƒÖEM)q
	if (startFlag > 70 &&
		count >= r) {

		NewGO<Enemy>(0);

		if (startFlag % 2 == 0) {
			NewGO<Enemy2>(0);
		}
		startFlag = 0;
		r = rand() % 400;
		count = 0;
	}
	
}