#include "GSPlay1.h"
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
#include "PlayGame2.h"
#include "AiPlayGame2.h"
#include "ButtonB.h"
#include "ButtonA.h"
#include "ButtonLeft.h"
#include "ButtonRight.h"



GSPlay1::GSPlay1()
{
}


GSPlay1::~GSPlay1()
{
}


void GSPlay1::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_GSPlay1.tga");

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
		GameStateMachine::GetInstance()->PushState(StateType::STATE_HELPGAME2);
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
	std::shared_ptr<PlayGame2> Obj = std::make_shared<PlayGame2>(240, 442);
	pointerPlayGame2 = Obj;
	m_listPlayGame2Animation.push_back(Obj);
	m_KeyPress = 0;

	//AiPlayerGame2
	std::shared_ptr<AiPlayGame2> Bbj = std::make_shared<AiPlayGame2>(1140, 510);
	pointerAiPlayGame2 = Bbj;
	m_listAiPlayGame2Animation.push_back(Bbj);
	m_KeyPress1 = 0;

	//Button A
	std::shared_ptr<ButtonA> Dbj = std::make_shared<ButtonA>(220, 175);
	pointerButtonA = Dbj;
	m_listButtonAAnimation.push_back(Dbj);

	//Button D
	std::shared_ptr<ButtonB> Cbj = std::make_shared<ButtonB>(320, 175);
	pointerButtonB = Cbj;
	m_listButtonBAnimation.push_back(Cbj);

	//ButtonLeft
	std::shared_ptr<ButtonLeft> Ibj = std::make_shared<ButtonLeft>(1000, 175);
	pointerButtonLeft = Ibj;
	m_listButtonLeftAnimation.push_back(Ibj);

	//ButtonRight
	std::shared_ptr<ButtonRight> Kbj = std::make_shared<ButtonRight>(1100, 177);
	pointerButtonRight = Kbj;
	m_listButtonRightAnimation.push_back(Kbj);

	// text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font4 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_tttt = std::make_shared< Text>(shader, font4, "Point:", TextColor::BLACK, 1.2);
	m_tttt->Set2DPosition(Vector2(90, 100));

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font5 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_tttt1 = std::make_shared< Text>(shader, font5, "Point:", TextColor::BLACK, 1.2);
	m_tttt1->Set2DPosition(Vector2(1040, 100));

	//point play 
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font2 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_point = std::make_shared< Text>(shader, font2, "0", TextColor::BLACK, 1.2);
	m_point->Set2DPosition(Vector2(180, 100));
	
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font3 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_pointAi = std::make_shared< Text>(shader, font3, "0", TextColor::BLACK, 1.2);
	m_pointAi->Set2DPosition(Vector2(1130, 100));

	//ResourceManagers::GetInstance()->PlaySound(name);


}

void GSPlay1::Exit()
{
}


void GSPlay1::Pause()
{
}

void GSPlay1::Resume()
{
}


void GSPlay1::HandleEvents()
{
}

void GSPlay1::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress1 |= 1;
			break;
		case KEY_RIGHT:
			m_KeyPress1 |= 1 << 2;
			break;
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress1 ^= 1;
			break;
		case KEY_RIGHT:
			m_KeyPress1 ^= 1 << 2;
			break;
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		default:
			break;
		}
	}
}


void GSPlay1::HandleTouchEvents(int x, int y, bool bIsPressed)
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

void GSPlay1::HandleMouseMoveEvents(int x, int y)
{

}



void GSPlay1::CountTime(GLfloat deltaTime)
{
	if (countTime > 0) 
	{
		countTime -= deltaTime;
		m_time->SetText(std::to_string(int(countTime)));

		if (countPoints > countPointsAi)
		{
			pointerPlayGame2->MovePoiter(0);
			pointerAiPlayGame2->MovePoiter(0);
		} else if (countPoints < countPointsAi)
		{
			pointerPlayGame2->MovePoiter(1);
			pointerAiPlayGame2->MovePoiter(1);
		}
	}
	if (countTime <= 0)
	{
		
		if(countPoints == countPointsAi)
		{
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMAVTEAMB);
			ResourceManagers::GetInstance()->StopSound(name);
		}
	}
}

void GSPlay1::CountPoint(GLfloat point)
{
		m_point->SetText(std::to_string(int(point)));
}

void GSPlay1::CountPointAi(GLfloat point)
{
	m_pointAi->SetText(std::to_string(int(point)));
}



void GSPlay1::Update(float deltaTime)
{

	CountTime(deltaTime);
	//PlayGame2 Move
	for (auto it : m_listPlayGame2Animation)
	{
		it->UpdatePlayGame2Pos(deltaTime);
	}
	for (auto it : m_listAiPlayGame2Animation)
	{
		it->UpdateAiPlayGame2Pos(deltaTime);
	}
	for (auto it : m_listButtonBAnimation)
	{
		it->UpdateButtonBPos(deltaTime);
	}
	for (auto it : m_listButtonAAnimation)
	{
		it->UpdateButtonAPos(deltaTime);
	}
	for (auto it : m_listButtonLeftAnimation)
	{
		it->UpdateButtonLeftPos(deltaTime);
	}
	for (auto it : m_listButtonRightAnimation)
	{
		it->UpdateButtonRightPos(deltaTime);
	}
	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
	//Play1

	if (m_KeyPress == 0)
	{
		pointerPlayGame2->Move(0);
		//pointerAiPlayGame2->Move(0);
		pointerButtonB->Move(0);
		pointerButtonA->Move(0);
		pointerButtonB->Move(0);
	}
	else if (m_KeyPress == 1)
	{
		countPoints += 1.0f;
		pointerPlayGame2->Move(1);
		//pointerAiPlayGame2->Move(1);
		pointerButtonB->Move(1);
		pointerButtonA->Move(1);
	}
	else if (m_KeyPress == 4)
	{
		countPoints += 1.0f;
		pointerPlayGame2->Move(4);
		//pointerAiPlayGame2->Move(4);
		pointerButtonB->Move(4);
		pointerButtonA->Move(4);
	}
	else if (m_KeyPress ^= 1)
	{
		countPoints += 1.0f;
		pointerPlayGame2->Move(1);
		//pointerAiPlayGame2->Move(1);
		pointerButtonB->Move(1);
		pointerButtonA->Move(1);
	}
	else if (m_KeyPress ^= 1 << 2)
	{
		countPoints += 1.0f;
		pointerPlayGame2->Move(4);
		//pointerAiPlayGame2->Move(4);
		pointerButtonB->Move(4);
		pointerButtonA->Move(4);
	}
	////////////////////////////////////////////
	//Play2
	if (m_KeyPress1 == 0)
	{
		//pointerPlayGame2->Move(0);
		pointerAiPlayGame2->Move(0);
		pointerButtonLeft->Move(0);
		pointerButtonRight->Move(0);
	}else if (m_KeyPress1 == 1)
		{
		countPointsAi += 1.0f;
		//pointerPlayGame2->Move(1);
		pointerAiPlayGame2->Move(1);
		pointerButtonLeft->Move(1);
		pointerButtonRight->Move(1);
		}else if (m_KeyPress1 == 4 )
		{
			countPointsAi += 1.0f;
			//pointerPlayGame2->Move(4);
			pointerAiPlayGame2->Move(4);
			pointerButtonLeft->Move(4);
			pointerButtonRight->Move(4);
			}else if (m_KeyPress1 ^= 1)
			{
				countPointsAi += 1.0f;
				//pointerPlayGame2->Move(1);
				pointerAiPlayGame2->Move(1);
				pointerButtonLeft->Move(1);
				pointerButtonRight->Move(1);
				}else if (m_KeyPress1 ^= 1 << 2)
				{
					countPointsAi += 1.0f;
					//pointerPlayGame2->Move(4);
					pointerAiPlayGame2->Move(4);
					pointerButtonLeft->Move(4);
					pointerButtonRight->Move(4);
				}
	/*
	switch (m_KeyPress)//Handle Key event
	{
	case 0:
		pointerPlayGame2->Move(0);
		//pointerAiPlayGame2->Move(0);
		pointerButtonB->Move(0);
		pointerButtonA->Move(0);
		pointerButtonB->Move(0);
		break;
	case 1:
		countPoints += 1.0f;
		pointerPlayGame2->Move(1);
		//pointerAiPlayGame2->Move(1);
		pointerButtonB->Move(1);
		pointerButtonA->Move(1);
		break;
	case 4:
		countPoints += 1.0f;
		pointerPlayGame2->Move(4);
		//pointerAiPlayGame2->Move(4);
		pointerButtonB->Move(4);
		pointerButtonA->Move(4);
		break;
	default:
		break;
	}

	switch (m_KeyPress1)//Handle Key event
	{
	case 0:
		//pointerPlayGame2->Move(0);
		pointerAiPlayGame2->Move(0);
		pointerButtonLeft->Move(0);
		pointerButtonRight->Move(0);
		break;
	case 1:
		countPointsAi += 1.0f;
		//pointerPlayGame2->Move(1);
		pointerAiPlayGame2->Move(1);
		pointerButtonLeft->Move(1);
		pointerButtonRight->Move(1);
		break;
	case 4:
		countPointsAi += 1.0f;
		//pointerPlayGame2->Move(4);
		pointerAiPlayGame2->Move(4);
		pointerButtonLeft->Move(4);
		pointerButtonRight->Move(4);
		break;
		
	default:
		break;
	}	
	*/
	CountPoint(countPoints);
	CountPointAi(countPointsAi);

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listPlayGame2Animation)
	{
		it->PlayGame2Update(deltaTime);
	}
	for (auto it : m_listAiPlayGame2Animation)
	{
		it->AiPlayGame2Update(deltaTime);
	}

	for (auto it : m_listButtonBAnimation)
	{
		it->ButtonBUpdate(deltaTime);
	}

	for (auto it : m_listButtonAAnimation)
	{
		it->ButtonAUpdate(deltaTime);
	}	
	for (auto it : m_listButtonLeftAnimation)
	{
		it->ButtonLeftUpdate(deltaTime);
	}
	for (auto it : m_listButtonRightAnimation)
	{
		it->ButtonRightUpdate(deltaTime);
	}
}

void GSPlay1::Draw()
{
	m_background->Draw();
	m_BgTime->Draw();
	m_time->Draw();
	m_time1->Draw();
	m_tttt->Draw();
	m_tttt1->Draw();
	m_point->Draw();
	m_pointAi->Draw();
	for (auto& it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listButton1)
	{
		it->Draw();
	}

	for (auto& it : m_listPlayGame2Animation)
	{
		it->PlayGame2Draw();
	}	
	for (auto& it : m_listAiPlayGame2Animation)
	{
		it->AiPlayGame2Draw();
	}
	for (auto& it : m_listButtonBAnimation)
	{
		it->ButtonBDraw();
	}
	for (auto& it : m_listButtonAAnimation)
	{
		it->ButtonADraw();
	}

	for (auto& it : m_listButtonLeftAnimation)
	{
		it->ButtonLeftDraw();
	}
	for (auto& it : m_listButtonRightAnimation)
	{
		it->ButtonRightDraw();
	}
	for (auto& it : m_listButtonMenu)
	{
		it->Draw();
	}
}