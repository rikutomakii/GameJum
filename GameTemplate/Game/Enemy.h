#pragma once
class Effect;
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;//�X�L�����f�������_�[
	CQuaternion enemyKaiten = CQuaternion::Identity;//��]
	CVector3 enemyPos = {50.0f,0.0f,-1000.0f};//�G�l�~�[�̏����ʒu
	CVector3 effectPos = CVector3::Zero;//�G�t�F�N�g�̃|�W�V����
	void Shoumetsu();//������Ƃ��̃��c
	void enemyMove();//�G�l�~�[���������
	prefab::CSoundSource* m_CSoundSource = nullptr;
	Effect* ef;
	
	prefab::CEffect* effect2 = NewGO<prefab::CEffect>(0);

	CVector2 text = CVector2::Zero;//�e�L�X�g�̃|�W�V����
	int enemyPatarn = 0;
	CVector3 scale = CVector3::One;//�X�L���T�C�Y
	


};

