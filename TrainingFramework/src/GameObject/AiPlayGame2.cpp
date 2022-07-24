#include "AiPlayGame2.h"
#include "SpriteAnimation.h"

AiPlayGame2::AiPlayGame2(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("animation3.tga");
	AiPlayGame2Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 4, 2, 0, 0.2f);
	AiPlayGame2Sprite->SetSize(500, 400);
	AiPlayGame2Sprite->Set2DPosition(posX, posY);

}

AiPlayGame2::~AiPlayGame2()
{
}

void AiPlayGame2::MovePoiter(int dir)
{
	switch (dir)
	{
	case 0:
		XX_Val = -0.2f;
		posX += XX_Val;
		if (posX < 850 || posX + 10 > 1280)
		{
			posX -= XX_Val;
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMAWIN);
			ResourceManagers::GetInstance()->StopSound(name);
		}
		break;
	case 1:
		XX_Val = +0.2f;
		posX += XX_Val;
		if (posX < 500 || posX + 10 > 1280)
		{
			posX -= XX_Val;
		}
		break;
	default:
		break;
	}
}
	void AiPlayGame2::Move(int dir) 
	{
	switch (dir)
	{
	case 0:
		AiPlayGame2Sprite->SetCurrentAction(1);
		AiPlayGame2Sprite->Set2DPosition(posX, 442);
		break;
	case 1:
		AiPlayGame2Sprite->SetCurrentAction(0);
		AiPlayGame2Sprite->Set2DPosition(posX, 442);
		break;
	case 4:
		AiPlayGame2Sprite->SetCurrentAction(0);
		AiPlayGame2Sprite->Set2DPosition(posX, 442);
		break;
	default:
		break;
	}
}


void AiPlayGame2::UpdateAiPlayGame2Pos(GLfloat deltaTime)
{
	AiPlayGame2Sprite->Set2DPosition(posX, posY);

}

void AiPlayGame2::AiPlayGame2Update(GLfloat deltaTime)
{

	AiPlayGame2Sprite->Update(deltaTime);
}
void AiPlayGame2::AiPlayGame2Draw()
{
	AiPlayGame2Sprite->Draw();

}