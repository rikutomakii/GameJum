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
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//スキンモデルレンダー
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//後で帰るモデルデータ
	font = NewGO<prefab::CFontRender>(0);//文字出すやつ
	m_CSoundSource = NewGO<prefab::CSoundSource>(0);//音出すやつ
	
	
	
	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();
}

void Enemy::enemyMove()
{
	enemyPos.z += 3;
	
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

		
		effect->Play(L"effect/blood.efk");
		/*effect->SetPosition(effectPos);*/
		
		/*scale.x = 1.0f;
		scale.y = 1.0f;
		scale.z = 1.0f;*/
		
		//エフェクトを再生。
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Greatだぜ。
		//DeleteGO(font);

		//DeleteGO(this);

	}

	//通り過ぎた時
	if (enemyPos.z >= 110){//falseの時の処理 z = 50ぐらい
		DeleteGO(this);
		
			//falseエフェクトの再生
			
			
			


			
			effect->Play(L"effect/blood.efk");//ポイの見つけて張り付ける
			
			//text.x = enemyPos.x;
			//text.y = enemyPos.z-100;
			//font->SetPosition(text);
			//font->SetText(L"false");//falseだぜ。
			//DeleteGO(font);
			//DeleteGO(this);
			
			//死亡音,後で追加する
			m_CSoundSource->Init(L"sound/coinGet.wav");
			
	}

	//速くたたきすぎた時

	//if (Pad(0).IsTrigger(enButtonA) &&
	//	enemyPos.z > -30000.0f&&
	//	enemyPos.z < -30.0f) {
	//	DeleteGO(this);


	//	//font->SetText(L"false");//falseだぜ。
	//	/*DeleteGO(font);
	//	DeleteGO(this);*/
	//}
}