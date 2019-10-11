#pragma once
class Titlescene :public IGameObject
{
public:
	Titlescene();
	~Titlescene();

	bool Start();

	void Update();

	prefab::CFontRender* m_cfontrender = nullptr;
	prefab::CSoundSource* ss;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
	//扉のスプライト
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSpriteRender* R_spriteRender = nullptr;
	prefab::CSpriteRender* L_spriteRender = nullptr;
	//扉の左側
	CVector3 L_position = CVector3::Zero;
	//扉の右側
	CVector3 R_position = CVector3::Zero;

	CVector3 fontColor = { 1.0f, 1.0f, 1.0f };
	bool ColorCheng = false;
	bool StartFlag = false;
	//扉が開いているかどうかの判定
	bool IsOpendoor = false;
};

