#include "stdafx.h"
#include "Titlescene.h"
#include "Game.h"


Titlescene::Titlescene()
{
}


Titlescene::~Titlescene()
{

	DeleteGO(m_spriteRender);
	DeleteGO(m_bgmSoundSource);
	DeleteGO(m_cfontrender);
}

bool Titlescene::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画面をロード
	m_spriteRender->Init(L"sprite/famima.dds", 1280.0f, 720.0f);
	

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
	if (Pad(0).IsPressAnyKey()) {
		//GameSceneのインスタンスを生成
		NewGO<Game>(0, "Game");
		
		//GameSceneのインスタンスを生成
		ss = NewGO<prefab::CSoundSource>(0);

		ss->Init(L"sound/famima2.wav");
		ss->Play(false);

		//シーンが切り替わるのでTitlsSceneのインスタンスを削除
		DeleteGO(this);
		
	}

}