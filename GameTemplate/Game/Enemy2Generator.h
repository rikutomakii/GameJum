#pragma once
class Enemy2Generator : public IGameObject
{
public:
	Enemy2Generator();
	~Enemy2Generator();
	bool Start();
	void Update();
	int count = 0;

};

