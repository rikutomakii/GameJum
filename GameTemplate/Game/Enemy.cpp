#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);
	DeleteGO(font);
}

bool Enemy::Start()
{
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//��ŋA�郂�f���f�[�^
	font = NewGO<prefab::CFontRender>(0);//�����o�����
	m_CSoundSource = NewGO<prefab::CSoundSource>(0);//���o�����
	

	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();

	
}

void Enemy::enemyMove()
{
	enemyPos.z += 1;
	m_SkinModelRender->SetPosition(enemyPos);


	

}

void Enemy::Shoumetsu()
{
	if (Pad(0).IsPressAnyKey()){//�h�A�ŋ��܂ꂽ�Ƃ����Ă�ɕς���
		DeleteGO(m_SkinModelRender);
		effect = NewGO<prefab::CEffect>(0);
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/blood.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos;
		//�G�l�~�[�̃|�W�V���������B
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB
		
		
		text.x = enemyPos.x;
		text.y = enemyPos.z;
		font->SetPosition(text);
		font->SetText(L"Great");//Great�����B�����enemy�̏ꏊ�ł�肽��
		
		DeleteGO(font);
		
		
	}
	if (enemyPos.z == 50){//false�̎��̏��� z = 50���炢
		DeleteGO(m_SkinModelRender);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//false�G�t�F�N�g�̍Đ�

			effectPos = enemyPos;
			effect->SetPosition(effectPos);
			effect->Play(L"effect/kieru.efk");//�|�C�̌����Ē���t����
			
			text.x = enemyPos.x;
			text.y = enemyPos.z-100;
			font->SetPosition(text);
			font->SetText(L"false");//false�����B�����enemy�̏ꏊ�ł�肽��
			DeleteGO(font);
			
			//���S��,��Œǉ�����
			//m_CSoundSource->Init(L"�����銴�������鉹");
	}


}

void Enemy::enemyTelepo()
{
	//�e���|�����邾��
	CVector3 enemyTerepo = CVector3::Zero;
	
}