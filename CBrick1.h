#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#define MARIO_WIDTH 14

class CBrick1 : public CGameObject {
public:
	CBrick1(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};