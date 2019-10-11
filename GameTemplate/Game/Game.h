#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Geezi.h"
#include"GameClear.h"

class EnemyGenerator;

class Enemy2;
class result;
class GameClear;
class Enemy;
class Door;
class BackGround;
class result;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void PostRender(CRenderContext& rc)override;
	
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	BackGround* m_backG = nullptr;
	Door* m_door = nullptr;
	Geezi* m_geezi = nullptr;
	result* m_rs = nullptr;
	GameClear* m_gc = nullptr;
	Enemy* m_ey = nullptr;
	Enemy2* m_ey2 = nullptr;
	EnemyGenerator* m_eyG = nullptr;


	int r = rand() % 200;
	int startFlag = 0;
	int count = 0;
	CFont m_fontTest;	
	float m_posintFontScale = 1.5f;
	float m_timer = 10.0f;
	int count2 = 0;



	bool StartFlag = false;
	bool OwariFlag = false;
	bool ClearFlag = false;
};

