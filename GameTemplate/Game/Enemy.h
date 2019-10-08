#pragma once
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;
	//CQuaternion enemyKaiten = CQuaternion::Identity;
	CVector3 enemyPos = CVector3::Zero;

};

