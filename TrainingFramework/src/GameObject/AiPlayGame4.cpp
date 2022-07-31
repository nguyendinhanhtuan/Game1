#include "AiPlayGame4.h"
#include "SpriteAnimation.h"

AiPlayGame4::AiPlayGame4(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("PlayGame41.tga");
	AiPlayGame4Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.2f);
	AiPlayGame4Sprite->SetSize(sizeX, sizeY);
	AiPlayGame4Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiPlayGame4::~AiPlayGame4()
{
}

void AiPlayGame4::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void AiPlayGame4::Move(int dir) {

	switch (dir)
	{
	case 0:
		AiPlayGame4Sprite->SetCurrentAction(0);
		AiPlayGame4Sprite->Set2DPosition(posX, posY);
		break;
	case 1:
		//move left
		AiPlayGame4Sprite->SetCurrentAction(1);
		XX_Val = -1.0f;
		posX += XX_Val;

		if (posX < 50 || posX + 10 > 1280)
		{
			posX -= XX_Val;
			dir = 0;
		}

		else if (isFaceRight) {
			isFaceRight = false;
			AiPlayGame4Sprite->SetRotation(Vector3(0, 0, 0));
		}

		break;
	case 2:
		//move dow
		AiPlayGame4Sprite->SetCurrentAction(1);
		YY_Val = 1.0f;
		posY += YY_Val;
		if (posY < 100 || posY + 10 > 720)
		{
			posY -= YY_Val;

		}
		break;

	case 3:
		//move up
		AiPlayGame4Sprite->SetCurrentAction(1);
		YY_Val = -1.0f;
		posY += YY_Val;
		if (posY < 100 || posY + 100 > 720)
		{
			posY -= YY_Val;
		}

		break;
	case 4:
		//move right
		AiPlayGame4Sprite->SetCurrentAction(1);
		XX_Val = +1.0f;
		posX += XX_Val;
		if (posX < 50 || posX + 10 > 1280)
		{
			posX -= XX_Val;
		}
		else if (!isFaceRight) {
			isFaceRight = true;
			AiPlayGame4Sprite->SetRotation(Vector3(0, PI, 0));
		}
		break;
	case 5:
		AiPlayGame4Sprite->SetCurrentAction(0);
		posY += YY_Val;
		YY_Val = 500.0f;
		break;
	default:
		break;
	}
}


void AiPlayGame4::UpdateAiPlayGame4Pos(GLfloat deltaTime)
{
	AiPlayGame4Sprite->Set2DPosition(posX, posY);

}

void AiPlayGame4::AiPlayGame4Update(GLfloat deltaTime)
{

	AiPlayGame4Sprite->Update(deltaTime);
}
void AiPlayGame4::AiPlayGame4Draw()
{
	AiPlayGame4Sprite->Draw();

}