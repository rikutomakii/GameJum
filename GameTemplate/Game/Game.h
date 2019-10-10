#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "BackGround.h"
#include "Door.h"
#include "Enemy.h"
#include "Geezi.h"
#include "result.h"
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

	int r = rand()%200;
	CFont m_fontTest;	
	int startFlag = 0;
	int count = 0;
	float m_timer = 19.0f;

	bool StartFlag = false;
};

