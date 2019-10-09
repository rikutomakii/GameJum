#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
	DeleteGO(font);
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
	enemyMove();
	Shoumetsu();

	
}

void Enemy::enemyMove()
{
	enemyPos.z += 1;
	m_SkinModelRender->SetPosition(enemyPos);


	

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsPressAnyKey()){//ドアで挟まれたときってやつに変える
		DeleteGO(m_SkinModelRender);
		effect = NewGO<prefab::CEffect>(0);
		//エフェクトを再生。
		effect->Play(L"effect/blood.efk");
		//エフェクトの座標
		CVector3 emitPos;
		//エネミーのポジションを代入。
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//エフェクトはエネミーのポジションで。
		
		
		text.x = enemyPos.x;
		text.y = enemyPos.z;
		font->SetPosition(text);
		font->SetText(L"Great");//Greatだぜ。これをenemyの場所でやりたい
		
		DeleteGO(font);
		
		
	}
	if (enemyPos.z == 50){//falseの時の処理 z = 50ぐらい
		DeleteGO(m_SkinModelRender);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//falseエフェクトの再生

			effectPos = enemyPos;
			effect->SetPosition(effectPos);
			effect->Play(L"effect/kieru.efk");//ポイの見つけて張り付ける
			
			text.x = enemyPos.x;
			text.y = enemyPos.z-100;
			font->SetPosition(text);
			font->SetText(L"false");//falseだぜ。これをenemyの場所でやりたい
			DeleteGO(font);
			
			//死亡音,後で追加する
			//m_CSoundSource->Init(L"消える感じがする音");
	}


}

void Enemy::enemyTelepo()
{
	//テレポさせるだけ
	CVector3 enemyTerepo = CVector3::Zero;
	
}