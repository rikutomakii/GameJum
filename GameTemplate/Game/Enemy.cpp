#include "stdafx.h"
#include "Enemy.h"
#include"Effect.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
	//DeleteGO(effect2);
	//DeleteGO(m_CSoundSource);

}

bool Enemy::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/Enemy2.cmo");//��ŋA�郂�f���f�[�^
	m_SkinModelRender->SetScale({ 3.0f,3.0f,3.0f });
	//m_SkinModelRender->SetPosition({ -10.0f,-10.0f,0.0f });

	
	m_game = FindGO<Game>("Game");
	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();
	if (m_game->m_timer >= 0.0f)
	{
		DeleteGO(this);
	}
}

void Enemy::enemyMove()
{
	enemyPos.z += 3;//�������ɗ��鑬�x
	enemyPos.x = 200;
	enemyPos.y = -120;
	
	m_SkinModelRender->SetPosition(enemyPos);

}

void Enemy::Shoumetsu()
{
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	scale.x = 5.0f;
	scale.y = 5.0f;
	scale.z = 5.0f;
	CVector3 emitPos = enemyPos;
	
	efPos.x = 40;
	effect->SetPosition(effectPos);//�Z�b�g�|�W�V����

	effect->SetPosition(efPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB

	

	effect->SetScale(scale);
	//�^�C�~���O�悭�������Ƃ�
	Geezi* g = FindGO<Geezi>("geezi");
	Game* gm = FindGO<Game>("Game");

	if (Pad(0).IsTrigger(enButtonA)&&
		enemyPos.z >=-50.0&&
		enemyPos.z <= 50.0 
		){
		DeleteGO(this);//�G�l�~�[�X�L���̔j��
		
		ss = NewGO<prefab::CSoundSource>(0);

		ss->Init(L"sound/����Ԃ��E���݂��鉹 (online-audio-converter.com).wav");
		ss->Play(false);

		g->scale.y += 0.9;
		gm->count2 += 1;

			//m_point += 1;
		//�G�t�F�N�g���Đ�
		effect->Play(L"effect/blood.efk");
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Great�����B
		//DeleteGO(font);

		//DeleteGO(this);

	}
	//Door* dr = FindGO<Door>("door");
	
	/*if (Pad(0).IsTrigger(enButtonA) &&
		enemyPos.z <= -50.0 &&
		enemyPos.z >= 50.0 &&
		dr->DownFlag == true
		) {
		g->scale.y -= 0.9;
		gm->count2 -= 1;
	}*/

	Door* dr = FindGO<Door>("door");
	if (dr->DownFlag == true) {
		g->scale.y -= 0.9;
		gm->count2 -= 1;
	}

	//�ʂ�߂�����
	if (enemyPos.z >= 100){//false�̎��̏��� z = 50���炢
		DeleteGO(this);
		ef->effectoo();
			
			
			//�Ԃɍ��������ɂȂ��e�L�X�g����
			//text.x = enemyPos.x;
			//text.y = enemyPos.z-100;
			//font->SetPosition(text);
			//font->SetText(L"false");//false�����B
			//DeleteGO(font);
			//DeleteGO(this);
			
			
	}

	//������������������
	//�g�����ǂ����͂킩��Ȃ��B�g�������Ȃ��Ǝv���Ă���
	//if (Pad(0).IsTrigger(enButtonA) &&
	//	enemyPos.z > -30000.0f&&
	//	enemyPos.z < -30.0f) {
	//	DeleteGO(this);


	//	//font->SetText(L"false");//false�����B
	//	/*DeleteGO(font);
	//	DeleteGO(this);*/
	//}
}