#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Game.h"
EnemyGenerator::~EnemyGenerator()
{
	Enemy enemy;
	DeleteGO(enemy.m_SkinModelRender);

}



void EnemyGenerator::enemyGenerator()
{
	Enemy2 enemy2;//////////�ɂႠ������������������������������������������������������(�L�E�ցE�M)
	Game game ;///////////////////�ɂ�[��(�L�E�ցE�M)
	Enemy enemy;//�ɂ�[��(�L�E�ցE�M)

	count++;
	startFlag++;//�ɂ�[��(�L�E�ցE�M)q
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
	
	if (game.count2 == 10) {
		DeleteGO(enemy.m_SkinModelRender);
		DeleteGO(enemy2.m_SkinModelRender);
		DeleteGO(this);
	}
}