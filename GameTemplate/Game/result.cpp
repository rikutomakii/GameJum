#include "stdafx.h"
#include "result.h"


result::result()
{
}


result::~result()
{
	//スプライトレンダラーを削除。
	DeleteGO(m_spriteRender);
}

bool result::Start()
{
	//CSpriteRenderのインスタンスを生成
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/gameClear.dds",		//読み込むファイルのファイルパス。
		1280.0f,					//スプライトの幅。
		720.0f						//スプライトの高さ。
	);
	return true;
}

void result::Update()
{
	if (Pad(0).IsPress(enButtonY)) {
		//GameSceneのインスタンスを生成
		NewGO<result>(0, "result");
		//シーンが切り替わるのでTitlsSceneのインスタンスを削除
		DeleteGO(this);
	}
}