#include "ButtonA.h"
#include "SpriteAnimation.h"

ButtonA::ButtonA(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ButtonA.tga");
	ButtonASprite = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 2, 0, 0.2f);
	ButtonASprite->SetSize(300, 710);
	ButtonASprite->Set2DPosition(posX, posY);

}

ButtonA::~ButtonA()
{
}


void ButtonA::Move(int dir) {

	switch (dir)
	{
	case 0:
		ButtonASprite->SetCurrentAction(1);
		ButtonASprite->Set2DPosition(posX, 175);
		break;
	case 1:
		ButtonASprite->SetCurrentAction(0);
		ButtonASprite->Set2DPosition(posX, 317);
		break;
	case 4:
		ButtonASprite->SetCurrentAction(1);
		ButtonASprite->Set2DPosition(posX, 175);
		break;
	default:
		break;
	}
}


void ButtonA::UpdateButtonAPos(GLfloat deltaTime)
{
	ButtonASprite->Set2DPosition(posX, posY);

}

void ButtonA::ButtonAUpdate(GLfloat deltaTime)
{

	ButtonASprite->Update(deltaTime);
}
void ButtonA::ButtonADraw()
{
	ButtonASprite->Draw();

}