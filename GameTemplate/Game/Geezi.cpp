#include "stdafx.h"
#include "Geezi.h"

Geezi::Geezi()
{

}
Geezi::~Geezi()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender2);

}

bool Geezi::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/geezi1.dds", 70.0f, 280.0f);
	m_spriteRender->SetPivot({ 0.35f,0.0f });
	m_spriteRender->SetPosition({ 580.0f,-350.0f,0.0f });

	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"sprite/geezi2.dds", 70.0f, 10.0f);
	m_spriteRender2->SetPivot({ 0.35f,0.0f });
	m_spriteRender2->SetPosition({ 580.0f,-350.0f,0.0f });

	return true;
}

void Geezi::Update()
{
	m_spriteRender2->SetScale(scale);
}
