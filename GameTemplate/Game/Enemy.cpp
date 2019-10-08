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
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");
	font = NewGO<prefab::CFontRender>(0);

	return true;
}

void Enemy::Update()
{
	


}

void Enemy::enemyMove()
{
	enemyPos.z -= 1;
	m_SkinModelRender->SetPosition(enemyPos);

	

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsTrigger(enButtonA)){//�h�A�ŋ��܂ꂽ�Ƃ����Ă�ɕς���
		DeleteGO(this);
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);//�G�t�F�N�g�̔���
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/MagicShield.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos = effectPos;
		emitPos.y += 10.0f;//��Œ���
		effect->SetPosition(emitPos);
		//�T�C�Y����������Ό�ŕύX


		font->SetText(L"Great");//Great�����B
	}
	if (Pad(0).IsTrigger(enButtonB)){//false�̎��̏���
		DeleteGO(this);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//false�G�t�F�N�g�̍Đ�
			effect->Play(L"/*�Ȃ񂩂����݂̂��Ē���t����*/");
			font->SetText(L"false");
	}

}