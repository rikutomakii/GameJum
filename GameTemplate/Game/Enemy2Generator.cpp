#include "stdafx.h"
#include "Enemy2Generator.h"
#include "enemy2.h"

Enemy2Generator::~Enemy2Generator()
{
}

bool Enemy2Generator::Start()
{
	NewGO<Enemy2>(0);
	return true;
}

void Enemy2Generator::Update()
{
	//if (/*何かしらの条件文*/) {
	//	//にゃーん
	//}
}
