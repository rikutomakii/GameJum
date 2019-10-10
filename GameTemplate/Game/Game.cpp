#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_backG = NewGO<BackGround>(0, "backG");
	m_door = NewGO<Door>(0, "door");
	m_geezi = NewGO<Geezi>(0, "geezi");
	m_rs = NewGO<result>(0, "result");
	//->SetTime(m_timer)
}


Game::~Game()
{
}
bool Game::Start(){
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ -80.0f, 150.0f, 150.0f });

	NewGO<Enemy>(0);

	StartFlag = true;

	return true;
}

void Game::Update()
{
	MainCamera().Update();
count++;
	startFlag++;
	if (startFlag > 70 &&
		count >= r) {
		
		NewGO<Enemy>(0);
		startFlag = 0;
		r = rand() % 200;
		count = 0;
	}
}

void Game::PostRender(CRenderContext& rc)
{
	if (StartFlag == true) {
		m_timer = max(0.0f, m_timer - GameTime().GetFrameDeltaTime());
	}
	
	wchar_t text[256];
	int minute = (int)m_timer / 60;
	int sec = (int)m_timer % 60;
	swprintf_s(text, L"%02d:%02d", minute, sec);
	m_fontTest.Begin(rc);
	m_fontTest.Draw(
		text,
		{ -140.0f, 340.0f },
		{ 1.0f, 0.0f, 1.0f, 1.0f },
		0.0f,
		1.5f,
		{ 0.0f, 1.0f }
	);
	m_fontTest.End(rc);
}