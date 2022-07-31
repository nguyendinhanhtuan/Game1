#include "PlayGame4.h"
#include "SpriteAnimation.h"

PlayGame4::PlayGame4(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("PlayGame4.tga");
	PlayGame4Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.2f);
	PlayGame4Sprite->SetSize(sizeX, sizeY);
	PlayGame4Sprite->SetRotation(Vector3(0, PI, 0));
	PlayGame4Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

PlayGame4::~PlayGame4()
{
}

void PlayGame4::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void PlayGame4::Move(int dir) {

	switch (dir)
	{
	case 0:
		PlayGame4Sprite->SetCurrentAction(0);
		break;
	case 1:
		//move left
		PlayGame4Sprite->SetCurrentAction(1);
		XX_Val = -1.0f;
		posX += XX_Val;

		if (posX < 50 || posX + 10 > 1280)
		{
			posX -= XX_Val;
			dir = 0;
		}

		else if (isFaceRight) {
			isFaceRight = false;
			PlayGame4Sprite->SetRotation(Vector3(0, 0, 0));
		}

		break;
	case 2:
		//move dow
		PlayGame4Sprite->SetCurrentAction(1);
		YY_Val = 1.0f;
		posY += YY_Val;
		if (posY < 100 || posY + 10 > 720)
		{
			posY -= YY_Val;

		}
		break;

	case 3:
		//move up
		PlayGame4Sprite->SetCurrentAction(1);
		YY_Val = -1.0f;
		posY += YY_Val;
		if (posY < 100 || posY + 10 > 720)
		{
			posY -= YY_Val;
		}

		break;
	case 4:
		//move right
		PlayGame4Sprite->SetCurrentAction(1);
		XX_Val = 1.0f;
		posX += XX_Val;
		if (posX < 50 || posX + 10 > 1280)
		{
			posX -= XX_Val;
		}
		else if (!isFaceRight) {
			isFaceRight = true;
			PlayGame4Sprite->SetRotation(Vector3(0, PI, 0));
		}
		break;
	case 5:
		PlayGame4Sprite->SetCurrentAction(0);
		posY += YY_Val;
		YY_Val = 500.0f;
		break;
	default:
		break;
	}
}


void PlayGame4::UpdatePlayGame4Pos(GLfloat deltaTime)
{
	PlayGame4Sprite->Set2DPosition(posX, posY);

}

void PlayGame4::PlayGame4Update(GLfloat deltaTime)
{

	PlayGame4Sprite->Update(deltaTime);
}
void PlayGame4::PlayGame4Draw()
{
	PlayGame4Sprite->Draw();

}