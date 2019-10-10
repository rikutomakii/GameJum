#include "stdafx.h"
#include "Enemy2.h"

Enemy2::~Enemy2()
{
	DeleteGO(m_SkinModelRender);
}


bool Enemy2::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//スキンモデルレンダー
	m_SkinModelRender->Init(L"modelData/lastEnemy.cmo");//後で帰るモデルデータ
	//font = NewGO<prefab::CFontRender>(0);//文字出すやつ
	//m_CSoundSource = NewGO<prefab::CSoundSource>(0);//音出すやつ
	effect = NewGO<prefab::CEffect>(0);//こっからエフェクト
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
	enemy2Pos.z += 10;
}

void Enemy2::enemyShoumetsu()
{

	//タイミングよく消せたとき
	if (Pad(0).IsPress(enButtonA) &&
		enemy2Pos.z >= -15.0 &&
		enemy2Pos.z <= 15.0) {
		DeleteGO(this);//エネミースキンの破棄

		//エフェクトを再生。
		effect->Play(L"effect/blood.efk");
		//エフェクトの座標
		CVector3 emitPos;
		//エフェクトにエネミーのポジションを代入。
		emitPos = enemy2Pos;

		effect->SetPosition(emitPos);//エフェクトはエネミーのポジションで。

		//font->SetPosition(text);
		//font->SetText(L"Great");
		//DeleteGO(font);



		//速くたたきすぎた時

		if (Pad(0).IsPress(enButtonA) &&
			enemy2Pos.z > 15.0f &&
			enemy2Pos.z < 25.0f) {
			DeleteGO(this);
		}
	}
}


