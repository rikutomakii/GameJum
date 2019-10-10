#pragma once
class Effect;
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;//スキンモデルレンダー
	CQuaternion enemyKaiten = CQuaternion::Identity;//回転
	CVector3 enemyPos = {50.0f,0.0f,-1000.0f};//エネミーの初期位置
	CVector3 effectPos = CVector3::Zero;//エフェクトのポジション
	void Shoumetsu();//消えるときのヤツ
	void enemyMove();//エネミーが動くやつ
	prefab::CSoundSource* m_CSoundSource = nullptr;
	Effect* ef;
	
	prefab::CEffect* effect2 = NewGO<prefab::CEffect>(0);

	CVector2 text = CVector2::Zero;//テキストのポジション
	int enemyPatarn = 0;
	CVector3 scale = CVector3::One;//スキンサイズ
	


};

