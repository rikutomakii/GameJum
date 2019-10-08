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
	if (Pad(0).IsTrigger(enButtonA)){//ドアで挟まれたときってやつに変える
		DeleteGO(this);
		prefab::CEffect* effect = NewGO<prefab::CEffect>(0);//エフェクトの発生
		//エフェクトを再生。
		effect->Play(L"effect/MagicShield.efk");
		//エフェクトの座標
		CVector3 emitPos = effectPos;
		emitPos.y += 10.0f;//後で調整
		effect->SetPosition(emitPos);
		//サイズが小さければ後で変更


		font->SetText(L"Great");//Greatだぜ。
	}
	if (Pad(0).IsTrigger(enButtonB)){//falseの時の処理
		DeleteGO(this);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//falseエフェクトの再生
			effect->Play(L"/*なんかいいのみつけて張り付ける*/");
			font->SetText(L"false");
	}

}