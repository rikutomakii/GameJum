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
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//��ŋA�郂�f���f�[�^
	font = NewGO<prefab::CFontRender>(0);//�����o�����
	m_CSoundSource = NewGO<prefab::CSoundSource>(0);//���o�����
	
	effect = NewGO<prefab::CEffect>(0);//��������G�t�F�N�g
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

	//�^�C�~���O�悭�������Ƃ�
	if (Pad(0).IsTrigger(enButtonA)//�h�A�ŋ��܂ꂽ�Ƃ����Ă�ɕς���
		&&5>=enemyPos.z >=-5){     //5  -5�̊ԂŔ��� 
		DeleteGO(this);//�G�l�~�[�X�L���̔j��
		
		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/blood.efk");
		//�G�t�F�N�g�̍��W
		CVector3 emitPos;
		//�G�t�F�N�g�ɃG�l�~�[�̃|�W�V���������B
		emitPos = enemyPos;

		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB
		
		font->SetPosition(text);
		font->SetText(L"Great");//Great�����B�����enemy�̏ꏊ�ł�肽��
		DeleteGO(font);

		DeleteGO(this);
		
	}

	//�ʂ�߂�����
	if (enemyPos.z >= 50){//false�̎��̏��� z = 50���炢
		DeleteGO(this);
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
			DeleteGO(this);
			
			//���S��,��Œǉ�����
			m_CSoundSource->Init(L"sound/coinGet.wav");
	}


}

void Enemy::enemyTelepo()
{
	//�e���|�����邾��
	CVector3 enemyTerepo = CVector3::Zero;
	
}