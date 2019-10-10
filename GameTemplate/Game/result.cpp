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
	m_spriteRender->SetActiveFlag(false);
	


	return true;


}

void result::Update()
{
	Game* gm = FindGO<Game>("Game");
	
	if (gm->m_timer == 0) {
		m_spriteRender->SetActiveFlag(true);
	}
}