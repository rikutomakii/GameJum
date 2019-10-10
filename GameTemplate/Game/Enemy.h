#pragma once
class Enemy:public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_SkinModelRender = nullptr;//スキンモデルレンダー
	CQuaternion enemyKaiten = CQuaternion::Identity;//回転
	CVector3 enemyPos = {0.0f,0.0f,1000.0f};//エネミーの初期位置
	CVector3 effectPos = CVector3::Zero;//エフェクトのポジション
	prefab::CFontRender* font = nullptr;
	void Shoumetsu();//消えるときのヤツ
	void enemyMove();//エネミーが動くやつ
	prefab::CSoundSource* m_CSoundSource = nullptr;
	prefab::CEffect* effect;//エフェクト
	CVector2 text = CVector2::Zero;//テキストのポジション
	void enemyTelepo();
	
};

