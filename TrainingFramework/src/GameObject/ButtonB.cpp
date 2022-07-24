#include "ButtonB.h"
#include "SpriteAnimation.h"

ButtonB::ButtonB(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ButtonD.tga");
	ButtonBSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 2, 0, 0.2f);
	ButtonBSprite->SetSize(300, 710);
	ButtonBSprite->Set2DPosition(posX, posY);

}

ButtonB::~ButtonB()
{
}


void ButtonB::Move(int dir) {

	switch (dir)
	{
	case 0:
		ButtonBSprite->SetCurrentAction(1);
		ButtonBSprite->Set2DPosition(posX, 175);
		break;
	case 1:
		ButtonBSprite->SetCurrentAction(1);
		ButtonBSprite->Set2DPosition(posX, 175);
		break;
	case 4:
		ButtonBSprite->SetCurrentAction(0);
		ButtonBSprite->Set2DPosition(posX, 317);
		break;
	default:
		break;
	}
}


void ButtonB::UpdateButtonBPos(GLfloat deltaTime)
{
	ButtonBSprite->Set2DPosition(posX, posY);

}

void ButtonB::ButtonBUpdate(GLfloat deltaTime)
{

	ButtonBSprite->Update(deltaTime);
}
void ButtonB::ButtonBDraw()
{
	ButtonBSprite->Draw();

}