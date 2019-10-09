#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

bool BackGround::Start()
{
	m_backGround = NewGO<prefab::CSkinModelRender>(0);
	m_backGround->Init(L"modelData/hospital.cmo");

	return true;
}
