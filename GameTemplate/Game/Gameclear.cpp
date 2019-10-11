#include "stdafx.h"
#include "GameClear.h"

GameClear::GameClear()
{
}

GameClear::~GameClear()
{
	DeleteGO(m_spriteRender);
}

bool GameClear::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/gameClear.dds", 1280.0f, 720.0f);
	return true;
}

void GameClear::Update()
{
}
