#pragma once
class EnemyGenerator : public IGameObject
{
	EnemyGenerator();
	~EnemyGenerator();
	bool Start();
	void Update();
	int startFlag = 0;
	int count = 0;
	float m_timer = 19.0f;
	int r = rand() % 200;
};

