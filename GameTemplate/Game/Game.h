#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "BackGround.h"
#include "Door.h"
#include "Enemy.h"
#include "Geezi.h"
class Enemy;
class Door;
class BackGround;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	BackGround* m_backG = nullptr;
	Door* m_door = nullptr;
	Geezi* m_geezi = nullptr;

	int r = rand()%800;
	int startFlag = 0;
	int count = 0;

	bool StartFlag = false;
};

