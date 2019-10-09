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
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//スキンモデルレンダー
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//後で帰るモデルデータ
	font = NewGO<prefab::CFontRender>(0);//文字出すやつ
	m_CSoundSource = NewGO<prefab::CSoundSource>(0);//音出すやつ
	

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
		//エフェクトの座標
		CVector3 emitPos;
		//エネミーのポジションを代入。
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//エフェクトはエネミーのポジションで。
		enemyPos.z -= 50.0f;
		m_SkinModelRender->SetPosition(enemyPos);
	}

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsPressAnyKey()){//ドアで挟まれたときってやつに変える
		DeleteGO(this);
		effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生。
		effect->Play(L"effect/LossOfBlood.efk");
		//エフェクトの座標
		CVector3 emitPos;
		//エネミーのポジションを代入。
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//エフェクトはエネミーのポジションで。
	
		font->SetText(L"Great");//Greatだぜ。これをenemyの場所でやりたい
	}
	if (Pad(0).IsTrigger(enButtonB)){//falseの時の処理
		DeleteGO(this);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//falseエフェクトの再生
			effect->Play(L"");//ポイの見つけて張り付ける
			
			font->SetText(L"false");//falseだぜ。これをenemyの場所でやりたい

			//死亡音,後で追加する
			//m_CSoundSource->Init(L"消える感じがする音");
	}


}