#include "stdafx.h"
#include "Enemy.h"
#include"Effect.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);

}

bool Enemy::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//スキンモデルレンダー
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//後で帰るモデルデータ
	
	
	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();
}

void Enemy::enemyMove()
{
	enemyPos.z += 3;//こっちに来る速度
	
	m_SkinModelRender->SetPosition(enemyPos);

}

void Enemy::Shoumetsu()
{
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	scale.x = 5.0f;
	scale.y = 5.0f;
	scale.z = 5.0f;
	CVector3 emitPos = enemyPos;
	effect->SetPosition(effectPos);//セットポジション

	effect->SetPosition(emitPos);//エフェクトはエネミーのポジションで。


	effect->SetScale(scale);
	//タイミングよく消せたとき
	if (Pad(0).IsTrigger(enButtonA)&&
		enemyPos.z >=-30.0&&
		enemyPos.z <= 30.0 ){
		DeleteGO(this);//エネミースキンの破棄

		//エフェクトを再生
		effect->Play(L"effect/blood.efk");
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Greatだぜ。
		//DeleteGO(font);

		//DeleteGO(this);

	}

	//通り過ぎた時
	if (enemyPos.z >= 100){//falseの時の処理 z = 50ぐらい
		DeleteGO(this);
		ef->effectoo();
			
			
			//間に合いそうにないテキストたち
			//text.x = enemyPos.x;
			//text.y = enemyPos.z-100;
			//font->SetPosition(text);
			//font->SetText(L"false");//falseだぜ。
			//DeleteGO(font);
			//DeleteGO(this);
			
			
	}

	//速くたたきすぎた時
	//使うかどうかはわからない。使いたいなぁと思っている
	//if (Pad(0).IsTrigger(enButtonA) &&
	//	enemyPos.z > -30000.0f&&
	//	enemyPos.z < -30.0f) {
	//	DeleteGO(this);


	//	//font->SetText(L"false");//falseだぜ。
	//	/*DeleteGO(font);
	//	DeleteGO(this);*/
	//}
}