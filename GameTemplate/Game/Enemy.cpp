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
	enemyPos.z += 10;
	
	m_SkinModelRender->SetPosition(enemyPos);

}

void Enemy::Shoumetsu()
{

	//�^�C�~���O�悭�������Ƃ�
	if (Pad(0).IsTrigger(enButtonA)&&
		enemyPos.z >=-30.0&& 
		enemyPos.z <= 30.0 ){     
		DeleteGO(this);//�G�l�~�[�X�L���̔j��
		scale *= 20.0f;
		effect->SetScale(scale);
		
		CVector3 emitPos;
		emitPos = enemyPos;
		
		effectPos = enemyPos;
		effect->SetPosition(effectPos);
		effect->SetPosition(emitPos);//�G�t�F�N�g�̓G�l�~�[�̃|�W�V�����ŁB

		//�G�t�F�N�g���Đ��B
		effect->Play(L"effect/blood.efk");
		//�G�t�F�N�g�̍��W
		
		//�G�t�F�N�g�ɃG�l�~�[�̃|�W�V���������B
		
		
		//font->SetPosition(text);
		//font->SetText(L"Great");//Great�����B�����enemy�̏ꏊ�ł�肽��
		//DeleteGO(font);

		//DeleteGO(this);

	}

	//�ʂ�߂�����
	if (enemyPos.z >= 110){//false�̎��̏��� z = 50���炢
		DeleteGO(this);
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//false�G�t�F�N�g�̍Đ�
			scale *= 20.0f;
			effect->SetScale(scale);
			effectPos = enemyPos;
			effect->SetPosition(effectPos);
			
			effect->Play(L"effect/kieru.efk");//�|�C�̌����Ē���t����
			
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

	if (Pad(0).IsTrigger(enButtonA) &&
		enemyPos.z > 30.0f&&
		enemyPos.z < -30.0f) {
		DeleteGO(this);
		CVector3 scale2 = CVector3::One;//�X�L���T�C�Y
		scale2 *= 20.0f;
		effect->SetScale(scale2);
		//font->SetText(L"false");//false�����B
		/*DeleteGO(font);
		DeleteGO(this);*/
	}
}