#pragma once
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;
	CQuaternion enemyKaiten = CQuaternion::Identity;
	CVector3 enemyPos = {0.0f,0.0f,-100.0f};
	CVector3 effectPos = CVector3::Zero;
	prefab::CFontRender* font = nullptr;
	void Shoumetsu();//������Ƃ��̃��c
	void enemyMove();//�G�l�~�[���������
	prefab::CSoundSource* m_CSoundSource = nullptr;
	prefab::CEffect* effect;//�G�t�F�N�g
	
	

};

