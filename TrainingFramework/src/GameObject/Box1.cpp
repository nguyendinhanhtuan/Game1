#include "Box1.h"


Box1::Box1(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	isDie = false;
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Box2.tga");
	Box1Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.2f);
	Box1Sprite->SetSize(sizeX, sizeY);
	Box1Sprite->Set2DPosition(posX, posY);
	state = 0;
	timer = 1.0f;
}

Box1::~Box1()
{
}

void Box1 ::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
	}
	else if (die == 0 )
	{
		isDie = true;
	}
}


void Box1::Move(int dir)
{

	switch (dir)
	{
	case 0:
		Box1Sprite->Set2DPosition(posX, 1000);
		break;
	case 1:
		if (isDie == false) 
		{
		//move tren xuong
		Box1Sprite->SetCurrentAction(1);
		if (countTime < 10.0f) {
			YY_Val = 1.3f;
		}
		else if (countTime >= 10.0f && countTime < 20.0f) {
			YY_Val = 1.5f;
		}
		else if (countTime >= 20.0f && countTime < 30.0f) {
			YY_Val = 1.7f;
		}
		posY += YY_Val;
		if (posY > 1360)
		{
			posY = -100;
		}
		}
		if (isDie == true) 
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 2:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				YY_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = 1.7f;
			}
			posY += YY_Val;
			if (posY > 1360)
			{
				posY = -100;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 3:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				YY_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = 1.7f;
			}
			posY += YY_Val;
			if (posY > 1360)
			{
				posY = -100;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 4:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				YY_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = 1.7f;
			}
			posY += YY_Val;
			if (posY > 1360)
			{
				posY = -100;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 5:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				YY_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = 1.7f;
			}
			posY += YY_Val;
			if (posY > 1360)
			{
				posY = -100;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 6:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				YY_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = -1.7f;
			}
			posY += YY_Val;
			if (posY < -350)
			{
				posY = 1200;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 7:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				YY_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = -1.7f;
			}
			posY += YY_Val;
			if (posY < -350)
			{
				posY = 1200;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 8:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				YY_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = -1.7f;
			}
			posY += YY_Val;
			if (posY < -350)
			{
				posY = 1200;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 9:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				YY_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = -1.7f;
			}
			posY += YY_Val;
			if (posY < -350)
			{
				posY = 1200;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	case 10:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				YY_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				YY_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				YY_Val = -1.7f;
			}
			posY += YY_Val;
			if (posY < -350)
			{
				posY = 1200;
			}
		}
		if (isDie == true)
		{
			posY += YY_Val;
			YY_Val = 1000.0f;
		}
		break;
	/// //////////////////////////////////////////////////////////////////////////////////////
	case 11:
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				XX_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = 1.7f;
			}
			posX += XX_Val;
			if (posX > 1360)
			{
				posX = -300;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 12:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				XX_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = 1.7f;
			}
			posX += XX_Val;
			if (posX > 1360)
			{
				posX = -200;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 13:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				XX_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = 1.7f;
			}
			posX += XX_Val;
			if (posX > 1360)
			{
				posX = -400;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 14:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				XX_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = 1.7f;
			}
			posX += XX_Val;
			if (posX > 1360)
			{
				posX = -600;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 15:
		//move tren xuong
		if (isDie == false)
		{
			//move tren xuong
			Box1Sprite->SetCurrentAction(1);
			if (countTime < 10.0f) {
				XX_Val = 1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = 1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = 1.7f;
			}
			posX += XX_Val;
			if (posX > 1360)
			{
				posX = -500;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
		////////////////////////////////////////////////
	case 16:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				XX_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = -1.7f;
			}
			posX += XX_Val;
			if (posX < -350)
			{
				posX = 1300;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 17:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				XX_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = -1.7f;
			}
			posX += XX_Val;
			if (posX < -350)
			{
				posX = 1400;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 18:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				XX_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = -1.7f;
			}
			posX += XX_Val;
			if (posX < -350)
			{
				posX = 1450;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 19:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				XX_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = -1.7f;
			}
			posX += XX_Val;
			if (posX < -350)
			{
				posX = 1380;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	case 20:
		if (isDie == false)
		{
			Box1Sprite->SetCurrentAction(1);
			//move duoi len
			if (countTime < 10.0f) {
				XX_Val = -1.3f;
			}
			else if (countTime >= 10.0f && countTime < 20.0f) {
				XX_Val = -1.5f;
			}
			else if (countTime >= 20.0f && countTime < 30.0f) {
				XX_Val = -1.7f;
			}
			posX += XX_Val;
			if (posX < -350)
			{
				posX = 1330;
			}
		}
		if (isDie == true)
		{
			posX += XX_Val;
			XX_Val = 1000.0f;
		}
		break;
	default:
		break;
	}
}

void Box1::onDead()
{
}

void Box1::Box4Draw()
{
	if (isDie == false)
	{
		Box1Sprite->Draw();
	}
}

void Box1::UpdateBox4Pos(GLfloat deltaTime)
{
	if(isDie == false)
	{
	Box1Sprite->Set2DPosition(posX, posY);
	}
	if (state == 1) timer -= deltaTime;
}

void Box1::Box4Update(GLfloat deltaTime)
{
	countTime += deltaTime;
	if (timer > 0.0f) {
		Box1Sprite->Update(deltaTime);
	}
}