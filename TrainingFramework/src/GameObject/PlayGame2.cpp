#include "PlayGame2.h"
#include "SpriteAnimation.h"

PlayGame2::PlayGame2(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("animation2.tga");
	PlayGame2Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 4, 2, 0, 0.2f);
	PlayGame2Sprite->SetSize(500, 400);
	PlayGame2Sprite->Set2DPosition(posX, posY);

}

PlayGame2::~PlayGame2()
{
}

void PlayGame2::MovePoiter(int dir) 
{
	switch (dir)
	{
		case 0:
			XX_Val = -0.2f;
			posX += XX_Val;
			if (posX < 0 || posX + 10 > 1280)
			{
				posX -= XX_Val;
			}
			break;
		case 1:
			XX_Val = 0.2f;
			posX += XX_Val;
			if (posX > 550 || posX + 10 > 1280)
			{
				posX -= XX_Val;
				GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMBWIN);
				ResourceManagers::GetInstance()->StopSound(name);

			}
			break;
	default:
		break;
	}
}
void PlayGame2::Move(int dir) {

	switch (dir)
	{
	case 0:
		PlayGame2Sprite->SetCurrentAction(1);
		PlayGame2Sprite->Set2DPosition(posX, 442);
		break;
	case 1:
		PlayGame2Sprite->SetCurrentAction(0);
		PlayGame2Sprite->Set2DPosition(posX, 510);
		break;
	case 4:
		PlayGame2Sprite->SetCurrentAction(0);
		PlayGame2Sprite->Set2DPosition(posX, 510);
		break;
	default:
		break;
	}
}


void PlayGame2::UpdatePlayGame2Pos(GLfloat deltaTime)
{
	PlayGame2Sprite->Set2DPosition(posX, posY);

}

void PlayGame2::PlayGame2Update(GLfloat deltaTime)
{

	PlayGame2Sprite->Update(deltaTime);
}
void PlayGame2::PlayGame2Draw()
{
		PlayGame2Sprite->Draw();

}