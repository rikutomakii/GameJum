#include "stdafx.h"
#include "Titlescene.h"
#include "Game.h"


Titlescene::Titlescene()
{
}


Titlescene::~Titlescene()
{

	DeleteGO(m_spriteRender);
	DeleteGO(R_spriteRender);
	DeleteGO(L_spriteRender);
	DeleteGO(m_spriteRender);
	DeleteGO(m_bgmSoundSource);
	DeleteGO(m_cfontrender);
}

bool Titlescene::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	R_spriteRender = NewGO<prefab::CSpriteRender>(0);
	L_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画面をロード
	m_spriteRender->Init(L"sprite/famima ao tobira waku.dds", 1000.0f, 720.0f);
	//ドアの右左の画像をロード
	R_spriteRender->Init(L"sprite/famima ao tobira migi.dds", 300.0f, 350.0f);
	L_spriteRender->Init(L"sprite/famima ao tobira hidari.dds", 300.0f, 350.0f);

	//右側のドア
	R_position.x = 150;
	R_position.y = -185;
	//左側のドア
	L_position.x = -150;
	L_position.y = -185;
	

	m_cfontrender = NewGO<prefab::CFontRender>(0);
	m_cfontrender->SetText(L"PressAnyKey");
//	m_cfontrender->SetColor({ 1,0,0 });


	return true;
}
void Titlescene::Update()
{


	m_cfontrender->SetColor(fontColor);
	if (ColorCheng==false) {
		fontColor.y -= 0.005, fontColor.z -= 0.005;				//色の値を下げる
		
	};
	if (ColorCheng==true) {
		fontColor.y += 0.005, fontColor.z += 0.005;				//色の値を上げる

	};

	if (/*fontColor.x == 1.0f && */fontColor.y >= 1.0f && fontColor.z >= 1.0f)
	{
		ColorCheng = false;
	}
	if (/*fontColor.x == 0.0f && */fontColor.y <= 0.0f && fontColor.z <= 0.0f) {
		ColorCheng = true;
	}
	

	//もしもAボタンが押されたら
	if (Pad(0).IsPress(enButtonA)) {

		//ドアが開いているかの判定
		IsOpendoor = true;
		
	}
	//ドアが開いているときに移動する
	if (IsOpendoor == true) {
		R_position.x += 15;
		L_position.x -= 15;
	}

	//ドアが止まる判定
	if (R_position.x > 300 && L_position.x < -300) {
		//GameSceneのインスタンスを生成
		NewGO<Game>(0, "Game");

		//GameSceneのインスタンスを生成
		ss = NewGO<prefab::CSoundSource>(0);

		ss->Init(L"sound/famima2.wav");
		ss->Play(false);

		//シーンが切り替わるのでTitlsSceneのインスタンスを削除
		DeleteGO(this);
		IsOpendoor = false;
	}

	//ドアのポジション
	R_spriteRender->SetPosition(R_position);
	L_spriteRender->SetPosition(L_position);

}