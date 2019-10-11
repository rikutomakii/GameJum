#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"
EnemyGenerator::~EnemyGenerator()
{
}

bool EnemyGenerator::Start()
{

	NewGO<Enemy>(0);
	return true;
}

void EnemyGenerator::Update()
{
	count++;
	startFlag++;
	if (startFlag > 70 &&
		count >= r) {

		NewGO<Enemy>(0);
		startFlag = 0;
		r = rand() % 200;
		count = 0;
	}

}
