#pragma once
class Door : public IGameObject
{
public:
	Door();
	~Door();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSkinModelRender* m_skinModelRender2 = nullptr;

	CVector3 m_position = CVector3::Zero;
	CVector3 m_position2 = CVector3::Zero;
	float m_timer = 0.0f;
	bool DoorFlag = false;
	bool DoorFlag2 = false;
	
};

