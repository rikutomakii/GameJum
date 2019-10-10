#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
	DeleteGO(m_backGround);
}

bool BackGround::Start()
{
	m_backGround = NewGO<prefab::CSkinModelRender>(0);
	m_backGround->Init(L"modelData/hospital.cmo");

	m_backGround->SetScale({ 3.0f,3.0f,3.0f });

	m_backGround = NewGO<prefab::CSkinModelRender>(0);
	m_backGround->Init(L"modelData/haikei.cmo");


	return true;
}
