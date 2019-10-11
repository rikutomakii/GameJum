#include "stdafx.h"
#include "Enemy.h"
#include"Effect.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
	//DeleteGO(effect2);
	//DeleteGO(m_CSoundSource);

}

bool Enemy::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//スキンモデルレンダー
	m_SkinModelRender->Init(L"modelData/Enemy2.cmo");//後で帰るモデルデータ
	m_SkinModelRender->SetScale({ 3.0f,3.0f,3.0f });
	//m_SkinModelRender->SetPosition({ -10.0f,-10.0f,0.0f });

	
	m_game = FindGO<Game>("Game");
	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();
	if (m_game->m_timer >= 0.0f)
	{
		DeleteGO(this);
	}
}

void Enemy::enemyMove()
{
	enemyPos.z += 3;//こっちに来る速度
	enemyPos.x = 200;
	enemyPos.y = -120;
	
	m_SkinModelRender->SetPosition(enemyPos);

}

void Enemy::Shoumetsu()
{
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	scale.x = 5.0f;
	scale.y = 5.0f;
	scale.z = 5.0f;
	CVector3 emitPos = enemyPos;
	
	efPos.x = 40;
	effect->SetPosition(effectPos);//セットポジション

	effect->SetPosition(efPos);//エフェクトはエネミーのポジションで。

	

	effect->SetScale(scale);
	//タイミングよく消せたとき
	Geezi* g = FindGO<Geezi>("geezi");
	Game* gm = FindGO<Game>("Game");

	if (Pad(0).IsTrigger(enButtonA)&&
		enemyPos.z >=-50.0&&
		enemyPos.z <= 50.0 
		){
		DeleteGO(this);//エネミースキンの破棄
		
		ss = NewGO<prefab::CSoundSource>(0);

		ss->Init(L"sound/握りつぶす・踏みつける音 (online-audio-converter.com).wav");
		ss->Play(false);

		g->scale.y += 0.9;
		gm->count2 += 1;

			//m_point += 1;
		//エフェクトを再生
		effect->Play(L"effect/blood.efk");
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Greatだぜ。
		//DeleteGO(font);

		//DeleteGO(this);

	}
	//Door* dr = FindGO<Door>("door");
	
	/*if (Pad(0).IsTrigger(enButtonA) &&
		enemyPos.z <= -50.0 &&
		enemyPos.z >= 50.0 &&
		dr->DownFlag == true
		) {
		g->scale.y -= 0.9;
		gm->count2 -= 1;
	}*/

	Door* dr = FindGO<Door>("door");
	if (dr->DownFlag == true) {
		g->scale.y -= 0.9;
		gm->count2 -= 1;
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