#include "stdafx.h"
#include "Game.h"
#include "Enemy.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "result.h"
Game::Game()
{
	//m_backG = NewGO<BackGround>(0, "backG");
	m_door = NewGO<Door>(0, "door");
}


Game::~Game()
{
}
bool Game::Start(){
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetPosition({ -80.0f, 80.0f, 150.0f });

	////�X�L�����f�������_���[���쐬�B
	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/unityChan.cmo");
	//m_skinModelRender->SetPosition({ 0.0f,0.0f,1.0f });	
	return true;
}

void Game::Update()
{
	if (Pad(0).IsPress(enButtonY)) {
		//GameScene�̃C���X�^���X�𐶐�
		NewGO<result>(0, "result");
		//�V�[�����؂�ւ��̂�TitlsScene�̃C���X�^���X���폜
		DeleteGO(this);
	}


	MainCamera().Update();
}