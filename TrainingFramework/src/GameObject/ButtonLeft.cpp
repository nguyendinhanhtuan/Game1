#include "ButtonLeft.h"
#include "SpriteAnimation.h"

ButtonLeft::ButtonLeft(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ButtonLeft.tga");
	ButtonLeftSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 2, 0, 0.2f);
	ButtonLeftSprite->SetSize(300, 710);
	ButtonLeftSprite->Set2DPosition(posX, posY);

}

ButtonLeft::~ButtonLeft()
{
}


void ButtonLeft::Move(int dir) {

	switch (dir)
	{
	case 0:
		ButtonLeftSprite->SetCurrentAction(1);
		ButtonLeftSprite->Set2DPosition(posX, 175);
		break;
	case 1:
		ButtonLeftSprite->SetCurrentAction(0);
		ButtonLeftSprite->Set2DPosition(posX, 317);
		break;
	case 4:
		ButtonLeftSprite->SetCurrentAction(1);
		ButtonLeftSprite->Set2DPosition(posX, 175);
		break;
	default:
		break;
	}
}


void ButtonLeft::UpdateButtonLeftPos(GLfloat deltaTime)
{
	ButtonLeftSprite->Set2DPosition(posX, posY);

}

void ButtonLeft::ButtonLeftUpdate(GLfloat deltaTime)
{

	ButtonLeftSprite->Update(deltaTime);
}
void ButtonLeft::ButtonLeftDraw()
{
	ButtonLeftSprite->Draw();

}