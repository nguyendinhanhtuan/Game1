#include "GSPlay2.h"
#include <cstdlib>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "ActorACC.h"
#include "Slime.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"
#include "PlayGame3.h"
#include "Box.h"




GSPlay2::GSPlay2()
{
}


GSPlay2::~GSPlay2()
{
}


void GSPlay2::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_Game3.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 380, 45);
	button->SetSize(150, 50);
	button->SetOnClick([this]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// button Menu
	texture = ResourceManagers::GetInstance()->GetTexture("btn_menu.tga");
	std::shared_ptr<GameButton>  buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 650, 50);
	buttonMenu->SetSize(150, 50);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PushState(StateType::STATE_MENU);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonMenu.push_back(buttonMenu);

	// button reset
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  buttonPause = std::make_shared<GameButton>(model, shader, texture);
	buttonPause->Set2DPosition(Globals::screenWidth - 900, 50);
	buttonPause->SetSize(150, 50);
	buttonPause->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PushState(StateType::STATE_HELPGAME3);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButton1.push_back(buttonPause);

	// time
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time = std::make_shared< Text>(shader, font, "60", TextColor::BLACK, 1.5);
	m_time->Set2DPosition(Vector2(640, 147));
	// 00:00
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font1 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time1 = std::make_shared< Text>(shader, font1, "00:", TextColor::BLACK, 1.5);
	m_time1->Set2DPosition(Vector2(585, 147));

	// Bg Time
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("BgTime.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BgTime = std::make_shared<Sprite2D>(model, shader, texture);
	m_BgTime->SetSize(400, 400);
	m_BgTime->Set2DPosition(630, 135);

	//PlayerGame2
	std::shared_ptr<PlayGame3> Obj = std::make_shared<PlayGame3>(1270, 442, 150, 350); 
	pointerPlayGame3 = Obj;
	m_listPlayGame3Animation.push_back(Obj);
	m_KeyPress = 0;

	//box
	std::shared_ptr<Box> BoxObj = std::make_shared<Box>(1049, 495, 150, 100);
	pointerBox = BoxObj;
	m_listBoxAnimation.push_back(BoxObj);
		//1
		std::shared_ptr<Box> BoxObj1 = std::make_shared<Box>(1049, 370, 150, 100);
		pointerBox1 = BoxObj1;
		m_listBoxAnimation1.push_back(BoxObj1);
		//2
		std::shared_ptr<Box> BoxObj2 = std::make_shared<Box>(765, 370, 150, 100);
		pointerBox2 = BoxObj2;
		m_listBoxAnimation2.push_back(BoxObj2);
		//3
		std::shared_ptr<Box> BoxObj3 = std::make_shared<Box>(765, 495, 150, 100);
		pointerBox3 = BoxObj3;
		m_listBoxAnimation3.push_back(BoxObj3);
		//4
		std::shared_ptr<Box> BoxObj4 = std::make_shared<Box>(475, 370, 150, 100);
		pointerBox4 = BoxObj4;
		m_listBoxAnimation4.push_back(BoxObj4);
		//5
		std::shared_ptr<Box> BoxObj5 = std::make_shared<Box>(475, 495, 150, 100);
		pointerBox5 = BoxObj5;
		m_listBoxAnimation5.push_back(BoxObj5);
		//6
		std::shared_ptr<Box> BoxObj6 = std::make_shared<Box>(205, 370, 130, 100);
		pointerBox6 = BoxObj6;
		m_listBoxAnimation5.push_back(BoxObj6);
		//7
		std::shared_ptr<Box> BoxObj7 = std::make_shared<Box>(205, 495, 130, 100);
		pointerBox7 = BoxObj7;
		m_listBoxAnimation5.push_back(BoxObj7);
	//ResourceManagers::GetInstance()->PlaySound(name);


}
void GSPlay2::Exit()
{
}


void GSPlay2::Pause()
{
}

void GSPlay2::Resume()
{
}


void GSPlay2::HandleEvents()
{
}

void GSPlay2::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1 << 1;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1 << 3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}


void GSPlay2::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

	for (auto buttonPause : m_listButton1)
	{
		if (buttonPause->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay2::HandleMouseMoveEvents(int x, int y)
{

}

bool GSPlay2::checkCollision(std::shared_ptr< PlayGame3 > rect1, std::shared_ptr< Box >  rect2)
{
	int left_a = rect1->posX  ;
	int right_a = rect1->posX + rect1->sizeX -200  ;
	int top_a = rect1->posY+55  ;
	int bottom_a = rect1->posY + rect1->sizeY ;

	int left_b = rect2->posX;
	int right_b = rect2->posX + rect2->sizeX -80 ;
	int top_b = rect2->posY;
	int bottom_b = rect2->posY + rect2->sizeY  ;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}



void GSPlay2::Update(float deltaTime)
{
	if (countTime > 0) {
		countTime -= deltaTime;
		m_time->SetText(std::to_string(int(countTime)));

	}
	if (countTime <= 0.0f )
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIE);
		ResourceManagers::GetInstance()->StopSound(name);

	}
std ::  rand()%4 + 1 ;
	/*
	switch (x)
	{
	case 1 :
		if (checkCollision(pointerPlayGame3, pointerBox1) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox1->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox3) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox3->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox4) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox4->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox7) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox7->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		break;
	case 2 :
		if (checkCollision(pointerPlayGame3, pointerBox) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox3) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox3->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox5) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox5->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox7) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox7->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		break;
	case 3:
		if (checkCollision(pointerPlayGame3, pointerBox1) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox1->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox2) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox2->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox4) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox4->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox6) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox6->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		break;
	case 4:
		if (checkCollision(pointerPlayGame3, pointerBox) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox2) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox2->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox5) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox5->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		if (checkCollision(pointerPlayGame3, pointerBox6) == true)
		{
			if (timeMoveDie >= 0.1f)
			{
				timeMoveDie -= deltaTime;
			}
			else
			{
				pointerPlayGame3->Move(5);
				pointerBox6->Move(0);
				timeMoveDie = 0.6f;
			}
		}
		break;
	default:
		break;
	}*/

	if (checkCollision(pointerPlayGame3, pointerBox1) == true)
	{
		if (timeMoveDie >= 0.5f)
		{
			timeMoveDie -= deltaTime;
		}
		else if (timeMoveDie < 0.5f && timeMoveDie > 0.0f )
		{
			pointerPlayGame3->Move(5);
			pointerBox1->Move(0);
			timeMoveDie -= deltaTime;

			if (timeMoveDie <= 0.0f  )
			{
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIEGAME3);
			ResourceManagers::GetInstance()->StopSound(name);

			}
		}

	}
	if (checkCollision(pointerPlayGame3, pointerBox3) == true)
	{
		if (timeMoveDie >= 0.5f)
		{
			timeMoveDie -= deltaTime;
		}
		else if (timeMoveDie < 0.5f && timeMoveDie > 0.0f)
		{
			pointerPlayGame3->Move(5);
			pointerBox3->Move(0);
			timeMoveDie -= deltaTime;

			if (timeMoveDie <= 0.0f)
			{
				GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIEGAME3);
				ResourceManagers::GetInstance()->StopSound(name);

			}
		}
	}
	if (checkCollision(pointerPlayGame3, pointerBox4) == true)
	{
		if (timeMoveDie >= 0.5f)
		{
			timeMoveDie -= deltaTime;
		}
		else if (timeMoveDie < 0.5f && timeMoveDie > 0.0f)
		{
			pointerPlayGame3->Move(5);
			pointerBox4->Move(0);
			timeMoveDie -= deltaTime;

			if (timeMoveDie <= 0.0f)
			{
				GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIEGAME3);
				ResourceManagers::GetInstance()->StopSound(name);

			}
		}
	}
	if (checkCollision(pointerPlayGame3, pointerBox7) == true)
	{
		if (timeMoveDie >= 0.5f)
		{
			timeMoveDie -= deltaTime;
		}
		else if (timeMoveDie < 0.5f && timeMoveDie > 0.0f)
		{
			pointerPlayGame3->Move(5);
			pointerBox7->Move(0);
			timeMoveDie -= deltaTime;

			if (timeMoveDie <= 0.0f)
			{
				GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIEGAME3);
				ResourceManagers::GetInstance()->StopSound(name);

			}
		}
	}
	//Play1
	for (auto it : m_listPlayGame3Animation)
	{
		it->UpdatePlayGame3Pos(deltaTime);
	}
	//Box
	for (auto it : m_listBoxAnimation)
	{
		it->UpdateBoxPos(deltaTime);
	}
		//1
		for (auto it : m_listBoxAnimation1)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimation2)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimation3)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimation4)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimation5)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimation6)
		{
			it->UpdateBoxPos(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimation7)
		{
			it->UpdateBoxPos(deltaTime);
		}

	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
	
	//PlayGame2 Move

	switch (m_KeyPress)//Handle Key event
	{
	case 0:
		pointerPlayGame3->Move(0);
		break;
	case 1:
		pointerPlayGame3 ->Move(1);
		break;
	case 2:
		pointerPlayGame3->Move(2);
		break;
	case 8:
		pointerPlayGame3->Move(3);
		break;
	case 4:
		pointerPlayGame3->Move(4);
		break;
	default:
		break;
	}



	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listPlayGame3Animation)
	{
		it->PlayGame3Update(deltaTime);
	}
	//Box
	for (auto it : m_listBoxAnimation)
	{
		it->BoxUpdate(deltaTime);
	}
		//1
		for (auto it : m_listBoxAnimation1)
		{
			it->BoxUpdate(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimation2)
		{
			it->BoxUpdate(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimation3)
		{
			it->BoxUpdate(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimation4)
		{
			it->BoxUpdate(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimation5)
		{
			it->BoxUpdate(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimation6)
		{
			it->BoxUpdate(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimation7)
		{
			it->BoxUpdate(deltaTime);
		}
}

void GSPlay2::Draw()
{
	m_background->Draw();
	m_BgTime->Draw();
	m_time->Draw();
	m_time1->Draw();

	for (auto& it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listButton1)
	{
		it->Draw();
	}
	//box
	for (auto& it : m_listBoxAnimation)
	{
		it->BoxDraw();
	}
		//1
		for (auto& it : m_listBoxAnimation1)
		{
			it->BoxDraw();
		}
		//2
		for (auto& it : m_listBoxAnimation2)
		{
			it->BoxDraw();
		}
		//3
		for (auto& it : m_listBoxAnimation3)
		{
			it->BoxDraw();
		}
		//4
		for (auto& it : m_listBoxAnimation4)
		{
			it->BoxDraw();
		}
		//5
		for (auto& it : m_listBoxAnimation5)
		{
			it->BoxDraw();
		}
		//6
		for (auto& it : m_listBoxAnimation6)
		{
			it->BoxDraw();
		}
		//7
		for (auto& it : m_listBoxAnimation7)
		{
			it->BoxDraw();
		}
	//player
	for (auto& it : m_listPlayGame3Animation)
	{
		it->PlayGame3Draw();
	}

	for (auto& it : m_listButtonMenu)
	{
		it->Draw();
	}
}