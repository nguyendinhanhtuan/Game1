#include "ButtonRight.h"
#include "SpriteAnimation.h"

ButtonRight::ButtonRight(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ButtonRight.tga");
	ButtonRightSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 2, 0, 0.2f);
	ButtonRightSprite->SetSize(300, 710);
	ButtonRightSprite->Set2DPosition(posX, posY);

}

ButtonRight::~ButtonRight()
{
}


void ButtonRight::Move(int dir) {

	switch (dir)
	{
	case 0:
		ButtonRightSprite->SetCurrentAction(1);
		ButtonRightSprite->Set2DPosition(posX, 177);
		break;
	case 1:
		ButtonRightSprite->SetCurrentAction(1);
		ButtonRightSprite->Set2DPosition(posX, 177);
		break;
	case 4:
		ButtonRightSprite->SetCurrentAction(0);
		ButtonRightSprite->Set2DPosition(posX, 319);
		break;
	default:
		break;
	}
}


void ButtonRight::UpdateButtonRightPos(GLfloat deltaTime)
{
	ButtonRightSprite->Set2DPosition(posX, posY);

}

void ButtonRight :: ButtonRightUpdate(GLfloat deltaTime)
{

	ButtonRightSprite->Update(deltaTime);
}
void ButtonRight::ButtonRightDraw()
{
	ButtonRightSprite->Draw();

}