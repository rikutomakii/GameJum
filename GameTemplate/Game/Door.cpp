#include "stdafx.h"
#include "Door.h"
#include "Titlescene.h"

Door::Door()
{
	
}

Door::~Door()
{
}

bool Door::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modeldata/Door2.cmo");

	m_skinModelRender2 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender2->Init(L"modeldata/Door2.cmo");

	/*m_position3 = { 70.0f,0.0f,0.0f };
	m_position4 = { -70.0f,0.0f,0.0f };*/
	

	/*m_skinModelRender->SetActiveFlag(false);
	m_skinModelRender2->SetActiveFlag(false);*/

	m_skinModelRender->SetPosition({ 70.0f,0.0f,0.0f });
	m_skinModelRender2->SetPosition({ -70.0f,0.0f,0.0f });
	

	
	return true;
}

void Door::Update()
{
	

	/*if (DoorFlag == false) {*/
	
	/*if (m_position.x = 0.0f >= 70.0f) {*/
		
	

		
	//}



	//}
		/*if (m_position.x >= 70 && m_position2.x >= -70) {

	}*/

	
	//Titlescene* m_title = FindGO<Titlescene>("title");
	
	if (Pad(0).IsPressAnyKey()) {
		m_position.x = 16.0f;
		m_position2.x = -16.0f;
		m_skinModelRender->SetPosition(m_position);
		m_skinModelRender2->SetPosition(m_position2);
		DoorFlag = true;
	}
	
	if (DoorFlag == true) {
		m_position.x += 2.0f;
		m_position2.x -= 2.0f;
		m_skinModelRender->SetPosition(m_position);
		m_skinModelRender2->SetPosition(m_position2);
		if (m_position.x == 70) {
			DoorFlag = false;
		}
	}
	
}
