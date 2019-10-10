#include "stdafx.h"
#include "Enemy.h"
#include"Effect.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
	DeleteGO(m_SkinModelRender);

}

bool Enemy::Start()
{
	//enemyPatarn = rand() %  1;
	m_SkinModelRender = NewGO<prefab::CSkinModelRender>(0);//�X�L�����f�������_�[
	m_SkinModelRender->Init(L"modelData/Enemy.cmo");//��ŋA�郂�f���f�[�^
	
	
	return true;
}

void Enemy::Update()
{
	enemyMove();
	Shoumetsu();
}

void Enemy::enemyMove()
{
	enemyPos.z += 3;//�������ɗ��鑬�x
	
	m_SkinModelRender->SetPosition(enemyPos);

}

void Enemy::Shoumetsu()
{
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	scale.x = 5.0f;
	scale.y = 5.0f;
	scale.z = 5.0f;
	CVector3 emitPos = enemyPos;
	effect->SetPosition(effectPos);//�Z�b�g�|�W�V����

	effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB


	effect->SetScale(scale);
	//�^�C�~���O�悭�������Ƃ�
	if (Pad(0).IsTrigger(enButtonA)&&
		enemyPos.z >=-30.0&&
		enemyPos.z <= 30.0 ){
		DeleteGO(this);//�G�l�~�[�X�L���̔j��

		//�G�t�F�N�g���Đ�
		effect->Play(L"effect/blood.efk");
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Great�����B
		//DeleteGO(font);

		//DeleteGO(this);

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