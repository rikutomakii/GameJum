#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
}

bool Enemy::Start()
{
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//��ŋA�郂�f���f�[�^
	font = NewGO<prefab::CFontRender>(0);//�����o�����
	m_CSoundSource = NewGO<prefab::CSoundSource>(0);//���o�����
	

	return true;
}

void Enemy::Update()
{
	


}

void Enemy::enemyMove()
{
	enemyPos.z += 1;
	m_SkinModelRender->SetPosition(enemyPos);

	if (Pad(0).IsPressAnyKey()) {
		effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g�̍��W
		CVector3 emitPos;
		//�G�l�~�[�̃|�W�V���������B
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB
		enemyPos.z -= 50.0f;
		m_SkinModelRender->SetPosition(enemyPos);
	}

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsPressAnyKey()){//�h�A�ŋ��܂ꂽ�Ƃ����Ă�ɕς���
		DeleteGO(this);
		effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/LossOfBlood.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos;
		//�G�l�~�[�̃|�W�V���������B
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB
	
		font->SetText(L"Great");//Great�����B�����enemy�̏ꏊ�ł�肽��
	}
	if (Pad(0).IsTrigger(enButtonB)){//false�̎��̏���
		DeleteGO(this);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//false�G�t�F�N�g�̍Đ�
			effect->Play(L"");//�|�C�̌����Ē���t����
			
			font->SetText(L"false");//false�����B�����enemy�̏ꏊ�ł�肽��

			//���S��,��Œǉ�����
			//m_CSoundSource->Init(L"�����銴�������鉹");
	}


}