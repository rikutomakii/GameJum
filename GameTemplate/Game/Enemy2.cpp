#include "stdafx.h"
#include "Enemy2.h"

Enemy2::Enemy2()
{
}

Enemy2::~Enemy2()
{
	DeleteGO(m_SkinModelRender);
	//DeleteGO(m_CSoundSource);
}


bool Enemy2::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/bomEnemy.cmo");//��ŋA�郂�f���f�[�^
	//font = NewGO<prefab::CFontRender>(0);//�����o�����
	//m_CSoundSource = NewGO<prefab::CSoundSource>(0);//���o�����
	effect = NewGO<prefab::CEffect>(0);//��������G�t�F�N�g 14:27��y�ɉ�����
	return true;
}

void Enemy2::Update()
{

	EnemyMove();
	enemyShoumetsu();
	
	m_SkinModelRender->SetPosition(enemy2Pos);
}

void Enemy2::EnemyMove()
{
	enemy2Pos.z += 5;
}

void Enemy2::enemyShoumetsu()
{

	//�^�C�~���O�悭�������Ƃ�
	if (Pad(0).IsPress(enButtonA) &&
		enemy2Pos.z >= -30.0 &&
		enemy2Pos.z <= 30.0) {
		DeleteGO(this);//�G�l�~�[�X�L���̔j��

		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/bom.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos;
		//�G�t�F�N�g�ɃG�l�~�[�̃|�W�V���������B
		emitPos = enemy2Pos;

		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB

		//font->SetPosition(text);
		//font->SetText(L"Great");
		//DeleteGO(font);

	}
}


