#pragma once
class Enemy2 : public IGameObject
{
	Enemy2();
	~Enemy2();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;
	CVector3 enemy2Pos = { 0.0f,0.0f,1000.0f };
	void EnemyMove();
	void enemyShoumetsu();
	prefab::CSoundSource* m_CSoundSource = nullptr;
	prefab::CFontRender* font = nullptr;
	prefab::CEffect* effect;//�G�t�F�N�g
	CVector2 text = CVector2::Zero;//�e�L�X�g�̃|�W�V����
	int enemyCount = 0;
};

