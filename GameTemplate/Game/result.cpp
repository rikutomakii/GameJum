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
	m_spriteRender->Init(L"sprite/GameOver.dds",		//読み込むファイルのファイルパス。
		1280.0f,					//スプライトの幅。
		720.0f						//スプライトの高さ。
	);
	m_spriteRender->SetActiveFlag(false);
	


	return true;


}

void result::Update()
{
	Game* gm = FindGO<Game>("Game");
	
	if (gm->m_timer == 0) {
		m_spriteRender->SetActiveFlag(true);
	}
}