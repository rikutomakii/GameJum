#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
}

bool Enemy::Start()
{
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_SkinModelRender->Init(L"modelData/ojichan.cmo");
	return true;
}

void Enemy::Update()
{
	

}

