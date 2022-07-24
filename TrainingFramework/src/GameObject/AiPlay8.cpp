#include "AiPlay8.h"
#include "SpriteAnimation.h"

AiPlay8::AiPlay8(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiPlay8.tga");
	AiPlay8Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 3, 0, 0.2f);
	AiPlay8Sprite->SetSize(200, 500);
	AiPlay8Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlay8::~AiPlay8()
{
}

void AiPlay8::Dead(int die)
{
	if (die == 1)
	{
		isDie = true;
	}
}
void AiPlay8::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			AiPlay8Sprite->SetCurrentAction(0);
			AiPlay8Sprite->Set2DPosition(posX, 610);
		}
		else if (isDie == true)
		{
			AiPlay8Sprite->SetCurrentAction(2);
			AiPlay8Sprite->Set2DPosition(posX, 460);
		}
		break;
	case 1:
		//move left
		AiPlay8Sprite->SetCurrentAction(1);
		X_Val = -0.5f; //-0.5f; 
		posX += X_Val;
		if (posX < 100 || posX + 10 > 1280 && !isFaceRight)
		{
			isFaceRight = true;
			AiPlay8Sprite->SetRotation(Vector3(0, PI, 0));
			posX -= X_Val;
			AiPlay8Sprite->SetCurrentAction(0);
			AiPlay8Sprite->Set2DPosition(posX, 610);
		}
		break;
	default:
		break;
	}
}


void AiPlay8::UpdateAiPlay8Pos(GLfloat deltaTime)
{
	AiPlay8Sprite->Set2DPosition(posX, posY);

}

void AiPlay8::AiPlay8Update(GLfloat deltaTime)
{
	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiPlay8Sprite->Update(deltaTime);
}
void AiPlay8::AiPlay8Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiPlay8Sprite->Draw();
	}
}