#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	//m_backG = NewGO<BackGround>(0, "backG");
	m_door = NewGO<Door>(0, "door");
}


Game::~Game()
{
}
bool Game::Start(){
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ -80.0f, 80.0f, 150.0f });

	
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
		count = 0;
	}}