#pragma once

class result:public IGameObject
{
public:
	result();
	~result();

	bool Start();

	void Update();

	prefab::CSpriteRender* m_spriteRender = nullptr;

};
