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
	if (Pad(0).IsTrigger(enButtonA)){//ドアで挟まれたときってやつに変える
		DeleteGO(this);

		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生。
		effect->Play(L"effect/MagicShield.efk");
		//エフェクトの座標
		CVector3 emitPos = effectPos;
		emitPos.y += 10.0f;//後で調整
		effect->SetPosition(emitPos);
		//サイズが小さければ後で変更

	}

}

