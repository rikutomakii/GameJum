#pragma once
class Geezi:public IGameObject
{
public:
	Geezi();
	~Geezi();
	bool Start();
	void Update();

	CVector3 scale = CVector3::One;
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSpriteRender* m_spriteRender2 = nullptr;
	float limit = 0.0f;

};

