#pragma once
#include "Titlescene.h"
#include "Game.h"
class Titlescene;
class Game;
class Door : public IGameObject
{
public:
	Door();
	~Door();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;
	prefab::CSkinModelRender* m_skinModelRender3 = nullptr;

	prefab::CSoundSource* ss;
	prefab::CDirectionLight* m_directionLig = nullptr;

	CVector3 m_position = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	CVector3 m_position3 = CVector3::Zero;
	CVector3 m_position4 = CVector3::Zero;
	CVector3 m_position5 = CVector3::Zero;

	

	float m_timer = 0.0f;
	bool DoorFlag = false;
	bool DoorFlag2 = false;
	bool DownFlag = false;



	//TitleScene*  m_title = nullptr;
	
};

