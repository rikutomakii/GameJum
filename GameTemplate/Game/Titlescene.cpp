#include "stdafx.h"
#include "Titlescene.h"
#include "Game.h"


Titlescene::Titlescene()
{
}


Titlescene::~Titlescene()
{

	DeleteGO(m_spriteRender);
	DeleteGO(R_spriteRender);
	DeleteGO(L_spriteRender);
	DeleteGO(m_spriteRender);
	DeleteGO(m_bgmSoundSource);
	DeleteGO(m_cfontrender);
}

bool Titlescene::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	R_spriteRender = NewGO<prefab::CSpriteRender>(0);
	L_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g����ʂ����[�h
	m_spriteRender->Init(L"sprite/famima ao tobira waku.dds", 1000.0f, 720.0f);
	//�h�A�̉E���̉摜�����[�h
	R_spriteRender->Init(L"sprite/famima ao tobira migi.dds", 300.0f, 350.0f);
	L_spriteRender->Init(L"sprite/famima ao tobira hidari.dds", 300.0f, 350.0f);

	//�E���̃h�A
	R_position.x = 150;
	R_position.y = -185;
	//�����̃h�A
	L_position.x = -150;
	L_position.y = -185;
	

	m_cfontrender = NewGO<prefab::CFontRender>(0);
	m_cfontrender->SetText(L"PressAnyKey");
//	m_cfontrender->SetColor({ 1,0,0 });


	return true;
}
void Titlescene::Update()
{


	m_cfontrender->SetColor(fontColor);
	if (ColorCheng==false) {
		fontColor.y -= 0.005, fontColor.z -= 0.005;				//�F�̒l��������
		
	};
	if (ColorCheng==true) {
		fontColor.y += 0.005, fontColor.z += 0.005;				//�F�̒l���グ��

	};

	if (/*fontColor.x == 1.0f && */fontColor.y >= 1.0f && fontColor.z >= 1.0f)
	{
		ColorCheng = false;
	}
	if (/*fontColor.x == 0.0f && */fontColor.y <= 0.0f && fontColor.z <= 0.0f) {
		ColorCheng = true;
	}
	

	//������A�{�^���������ꂽ��
	if (Pad(0).IsPress(enButtonA)) {

		//�h�A���J���Ă��邩�̔���
		IsOpendoor = true;
		
	}
	//�h�A���J���Ă���Ƃ��Ɉړ�����
	if (IsOpendoor == true) {
		R_position.x += 15;
		L_position.x -= 15;
	}

	//�h�A���~�܂锻��
	if (R_position.x > 300 && L_position.x < -300) {
		//GameScene�̃C���X�^���X�𐶐�
		NewGO<Game>(0, "Game");

		//GameScene�̃C���X�^���X�𐶐�
		ss = NewGO<prefab::CSoundSource>(0);

		ss->Init(L"sound/famima2.wav");
		ss->Play(false);

		//�V�[�����؂�ւ��̂�TitlsScene�̃C���X�^���X���폜
		DeleteGO(this);
		IsOpendoor = false;
	}

	//�h�A�̃|�W�V����
	R_spriteRender->SetPosition(R_position);
	L_spriteRender->SetPosition(L_position);

}