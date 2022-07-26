#include "Box.h"


Box::Box(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Box1.tga");
	BoxSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 1, 1, 0, 0.1f);
	BoxSprite->SetSize(sizeX, sizeY);
	BoxSprite->Set2DPosition(posX, posY);
	state = 0;
	timer = 1.0f;
}

Box::~Box()
{
}



void Box::Move(int dir)
{

	switch (dir)
	{
	case 0:
		posY += YY_Val;
		YY_Val = 500.0f;
		break;
	default:
		break;
	}

}

void Box::onDead()
{
}

void Box::BoxDraw()
{
	BoxSprite->Draw();
}

void Box::UpdateBoxPos(GLfloat deltaTime)
{
	BoxSprite->Set2DPosition(posX, posY);
	if (state == 1) timer -= deltaTime;
}

void Box::BoxUpdate(GLfloat deltaTime)
{
	if (timer > 0.0f) {
		BoxSprite->Update(deltaTime);
	}
}