#include "stdafx.h"
#include "Door.h"

Door::Door()
{
}

Door::~Door()
{
}

bool Door::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modeldata/Door1.cmo");

	m_skinModelRender2 = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender2->Init(L"modeldata/Door2.cmo");

	m_skinModelRender2->SetPosition({ 70.0f,0.0f,0.0f });

	return true;
}

void Door::Update()
{
	
	m_timer++;
	if (Pad(0).IsPressAnyKey()) {
		m_position.x += 5.0f;
		m_position2.x -= 5.0f;
	}
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender2->SetPosition(m_position2);
}
