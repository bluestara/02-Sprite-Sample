#pragma once

#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"


#define ID_ANI_BRICK 10000
#define BRICK_WIDTH 16
#define GROUND_Y 130.0f
class CBrick : public CGameObject {
public:
	CBrick(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
};
