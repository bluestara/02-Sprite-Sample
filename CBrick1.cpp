#include "Game.h"
#include "Mario.h"
#include "CBrick1.h"
void CBrick1::Render() {

	LPANIMATION ani = CAnimations::GetInstance()->Get(510);

	ani->Render(x, y);

}