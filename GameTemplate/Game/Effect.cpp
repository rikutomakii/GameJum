#include "stdafx.h"
#include "Effect.h"
#include "Enemy.h"

bool Effect::Start()
{
	
	return true;
}
void Effect::effectoo()
{
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	CVector3 scale = CVector3::Zero;
	scale.x = 10.0f;
	scale.y = 10.0f;
	scale.z = 10.0f;
	effect->SetScale(scale);

	CVector3 Pos = CVector3::Zero;
	Pos.z = 90.0f;
	Pos.x = 50.0f;
	effect->SetPosition(Pos);

	effect->Play(L"effect/kieru.efk");
}