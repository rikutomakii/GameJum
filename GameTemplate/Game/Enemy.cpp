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
	m_SkinModelRender->Init(L"modelData/suisei/suisei.cmo");
	font = NewGO<prefab::CFontRender>(0);
	return true;
}

void Enemy::Update()
{
	
	enemyMove();


}

void Enemy::enemyMove()
{
	enemyPos.z -= 1;
	m_SkinModelRender->SetPosition(enemyPos);

	font->SetText(L"Great");

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsTrigger(enButtonA)){//�h�A�ŋ��܂ꂽ�Ƃ����Ă�ɕς���
		DeleteGO(this);

		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/MagicShield.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos = effectPos;
		emitPos.y += 10.0f;//��Œ���
		effect->SetPosition(emitPos);
		//�T�C�Y����������Ό�ŕύX

	}

}

