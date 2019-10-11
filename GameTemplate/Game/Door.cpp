#include "stdafx.h"
#include "Door.h"
#include "Titlescene.h"

#include "tkEngine/light/tkDirectionLight.h"
Door::Door()
{
	
}

Door::~Door()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_skinModelRender2);
	DeleteGO(m_skinModelRender3);
	DeleteGO(m_directionLig);
	//DeleteGO(ss);
}

bool Door::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modeldata/Door2.cmo");

	m_skinModelRender2 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender2->Init(L"modeldata/Door2.cmo");

	m_skinModelRender3 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender3->Init(L"modeldata/sirusi.cmo");

	/*m_position3 = { 70.0f,0.0f,0.0f };
	m_position4 = { -70.0f,0.0f,0.0f };*/
	

	/*m_skinModelRender->SetActiveFlag(false);
	m_skinModelRender2->SetActiveFlag(false);*/

	m_skinModelRender->SetPosition({ 70.0f,0.0f,0.0f });
	m_skinModelRender2->SetPosition({ -70.0f,0.0f,0.0f });
	m_skinModelRender3->SetPosition({ 0.0f,-20.0f,10.0f });
	
	m_directionLig = NewGO<prefab::CDirectionLight>(0);
	
	m_directionLig->SetColor({ 2.5f, 2.5f, 2.5f, 1.0f });
	
	return true;
}

void Door::Update()
{
	

	/*Game* gm = FindGO<Game>("Game");*/
	m_timer++;
	if (Pad(0).IsPressAnyKey()/*&&gm->StartFlag == true*/) {
		
		m_position.x = 16.0f;
		m_position2.x = -16.0f;
		m_skinModelRender->SetPosition(m_position);
		m_skinModelRender2->SetPosition(m_position2);
		DownFlag = true;
		if (m_timer >= 300) {
			ss = NewGO<prefab::CSoundSource>(0);

			ss->Init(L"sound/famima2.wav");
			ss->Play(false);
			m_timer = 0;
		}
		DoorFlag = true;

		
		
	}
	
	if (DoorFlag == true) {
		m_position.x += 2.0f;
		m_position2.x -= 2.0f;
		m_skinModelRender->SetPosition(m_position);
		m_skinModelRender2->SetPosition(m_position2);
		
		if (m_position.x == 70) {
			DoorFlag = false;
			DownFlag = false;
			
		}
	}
	
}
