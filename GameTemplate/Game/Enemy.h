#pragma once
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;//�X�L�����f�������_�[
	CQuaternion enemyKaiten = CQuaternion::Identity;//��]
	CVector3 enemyPos = {0.0f,0.0f,1000.0f};//�G�l�~�[�̏����ʒu
	CVector3 effectPos = CVector3::Zero;//�G�t�F�N�g�̃|�W�V����
	prefab::CFontRender* font = nullptr;
	void Shoumetsu();//������Ƃ��̃��c
	void enemyMove();//�G�l�~�[���������
	prefab::CSoundSource* m_CSoundSource = nullptr;
	prefab::CEffect* effect;//�G�t�F�N�g
	CVector2 text = CVector2::Zero;//�e�L�X�g�̃|�W�V����
	void enemyTelepo();
	
};

