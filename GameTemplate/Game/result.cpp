#include "stdafx.h"
#include "result.h"


result::result()
{
	
}


result::~result()
{
	//�X�v���C�g�����_���[���폜�B
	DeleteGO(m_spriteRender);
}

bool result::Start()
{
	

	//CSpriteRender�̃C���X�^���X�𐶐�
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GameOver.dds",		//�ǂݍ��ރt�@�C���̃t�@�C���p�X�B
		1280.0f,					//�X�v���C�g�̕��B
		720.0f						//�X�v���C�g�̍����B
	);
	


	return true;


}

void result::Update()
{
	
	
}