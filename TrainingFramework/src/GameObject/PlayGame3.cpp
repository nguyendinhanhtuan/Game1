#include "PlayGame3.h"
#include "SpriteAnimation.h"

PlayGame3::PlayGame3(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("PlayGame3.tga");
	PlayGame3Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.2f);
	PlayGame3Sprite->SetSize(sizeX, sizeY);
	PlayGame3Sprite->Set2DPosition(posX, posY);

}

PlayGame3::~PlayGame3()
{
}

void PlayGame3::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void PlayGame3::Move(int dir) {

	switch (dir)
	{
	case 0:
			PlayGame3Sprite->SetCurrentAction(0);
		break;
	case 1:
		//move left
		PlayGame3Sprite->SetCurrentAction(1);
		XX_Val = -1.0f;
		posX += XX_Val;

		if (posX < 50   )
		{
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_WINGAME3);
			posX -= XX_Val;
			dir = 0;
		}
		
		break;
	case 2:
		//move dow
		PlayGame3Sprite->SetCurrentAction(1);
		YY_Val = 1.0f;
		posY += YY_Val;
		if (posY < 340 || posY + 180 > 720)
		{
			posY -= YY_Val ;

		}
		break;

	case 3:
		//move up
		PlayGame3Sprite->SetCurrentAction(1);
		YY_Val = -1.0f;
		posY += YY_Val;
		if (posY < 340 || posY + 180 > 720)
		{
			posY -= YY_Val ;
		}

		break;
	case 4:
		//move right
		PlayGame3Sprite->SetCurrentAction(1);
		XX_Val = -1.0f;
		posX += XX_Val;
		if (posX < 50 )
		{
			posX -= XX_Val;
		}
		break;
	case 5 :
		PlayGame3Sprite->SetCurrentAction(0);
		posY += YY_Val;
		YY_Val = 500.0f;
		break;
	default:
		break;
	}
}


void PlayGame3::UpdatePlayGame3Pos(GLfloat deltaTime)
{
	PlayGame3Sprite->Set2DPosition(posX, posY);

}

void PlayGame3::PlayGame3Update(GLfloat deltaTime)
{

	PlayGame3Sprite->Update(deltaTime);
}
void PlayGame3::PlayGame3Draw()
{
	PlayGame3Sprite->Draw();

}