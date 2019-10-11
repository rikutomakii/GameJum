#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "result.h"
#include "Titlescene.h"
#include "EnemyGenerator.h"
Game::Game()
{
//m_backG = NewGO<BackGround>(0, "backG");
	m_door = NewGO<Door>(0, "door");
	m_geezi = NewGO<Geezi>(0, "geezi");
	m_eyG = NewGO<EnemyGenerator>(0, "enemyG");	//m_ey = NewGO<Enemy>(0, "enemy");
	//m_rs = NewGO<result>(0, "result");
	
	//m_ey2 = NewGO<Enemy2>(0, "enemy2");
	//->SetTime(m_timer)
}


Game::~Game()
{
	//DeleteGO(m_backG);
	DeleteGO(m_door);
	DeleteGO(m_geezi);
	DeleteGO(m_rs);
	DeleteGOs("enemy");
	//DeleteGO(m_ey2);
	
}
bool Game::Start()
{

	m_backG = NewGO<BackGround>(0, "backG");
	m_door = NewGO<Door>(0, "door");
	m_geezi = NewGO<Geezi>(0, "geezi");
	m_eyG = NewGO<EnemyGenerator>(0, "enemyG");

	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ -80.0f, 150.0f, 150.0f });

	

	StartFlag = true;

	return true;
}

void Game::Update()
{
	/*if (Pad(0).IsPress(enButtonY)) {
		GameSceneのインスタンスを生成
		NewGO<result>(0, "result");
		シーンが切り替わるのでTitlsSceneのインスタンスを削除
		DeleteGO(this);
	}*/
	
	m_eyG->enemyGenerator();

	//条件を満たしたときタイトルシーン
	if (count2 == 10 && m_gc == nullptr)
	{
		m_gc = NewGO<GameClear>(0,"gameC");
		if (Pad(0).IsPress(enButtonB)) {
			NewGO<Titlescene>(0, "title");
			DeleteGO(this);
		}
	}
	//Bボタンを押したときにタイトルに戻る
	if (Pad(0).IsTrigger(enButtonB) && OwariFlag == true) {

		NewGO<Titlescene>(0, "title");
		DeleteGO(this);
	}
	//タイマーがゼロになったとき、リザルトNewGO
	if (m_timer == 0 &&m_rs ==nullptr) {
		OwariFlag = true;
		//DeleteGO(this);
		m_rs = NewGO<result>(0, "result");
		m_timer = -1;
		
	}
	

	MainCamera().Update();



	//count++;
	//startFlag++;
	//if (startFlag > 70 &&
	//	count >= r
	//	/*&& OwariFlag == false*/) {
	//	startFlag = 0;
	//	m_ey = NewGO<Enemy>(0, "enemy");
	//	r = rand() % 200;
	//	count = 0;
	//}
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

	swprintf_s(text, L"%02d/30", count2);
	m_fontTest.Draw(
		text,
		{ 450.0f ,350.0f },
		{ 1.0f,.0f,0.0f,1.0f },
		0.0f,
		m_posintFontScale,
		{ 0.0f,1.0f }
	);

	m_fontTest.End(rc);
}