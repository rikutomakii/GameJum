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
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 fontColor = { 1.0f, 1.0f, 1.0f };
	bool ColorCheng = false;
	bool StartFlag = false;
};

