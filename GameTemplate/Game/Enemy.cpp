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
	//enemyPatarn = rand() %  1;
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
	enemyPos.z += 3;
	
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

		
		effect->Play(L"effect/blood.efk");
		/*effect->SetPosition(effectPos);*/
		
		/*scale.x = 1.0f;
		scale.y = 1.0f;
		scale.z = 1.0f;*/
		
		//�G�t�F�N�g���Đ��B
		
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Great�����B
		//DeleteGO(font);

		//DeleteGO(this);

	}

	//�ʂ�߂�����
	if (enemyPos.z >= 110){//false�̎��̏��� z = 50���炢
		DeleteGO(this);
		
			//false�G�t�F�N�g�̍Đ�
			
			
			


			
			effect->Play(L"effect/blood.efk");//�|�C�̌����Ē���t����
			
			//text.x = enemyPos.x;
			//text.y = enemyPos.z-100;
			//font->SetPosition(text);
			//font->SetText(L"false");//false�����B
			//DeleteGO(font);
			//DeleteGO(this);
			
			//���S��,��Œǉ�����
			m_CSoundSource->Init(L"sound/coinGet.wav");
			
	}

	//������������������

	//if (Pad(0).IsTrigger(enButtonA) &&
	//	enemyPos.z > -30000.0f&&
	//	enemyPos.z < -30.0f) {
	//	DeleteGO(this);


	//	//font->SetText(L"false");//false�����B
	//	/*DeleteGO(font);
	//	DeleteGO(this);*/
	//}
}