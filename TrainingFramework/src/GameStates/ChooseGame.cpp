#include "ChooseGame.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

ChooseGame::ChooseGame() : GameStateBase(StateType::STATE_CHOOSEGAME), m_time(0.0f)
{
}


ChooseGame::~ChooseGame()
{
}


void ChooseGame::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//button Menu
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_menu.tga");
	std::shared_ptr<GameButton> buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 150, 50);
	buttonMenu->SetSize(150, 50);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonMenu.push_back(buttonMenu);

	//button Play again
	texture = ResourceManagers::GetInstance()->GetTexture("btnPlayGame.tga");
	std::shared_ptr<GameButton> buttonPlayAgain = std::make_shared<GameButton>(model, shader, texture);
	buttonPlayAgain->Set2DPosition(Globals::screenWidth - 1070, 367);
	buttonPlayAgain->SetSize(340, 220);
	buttonPlayAgain->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PrepareToPlay);
		ResourceManagers::GetInstance()->PlaySound(Click);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonPlayAgain.push_back(buttonPlayAgain);

	//button Play again1
	texture = ResourceManagers::GetInstance()->GetTexture("btnPlayGame2.tga");
	std::shared_ptr<GameButton> buttonPlayAgain1 = std::make_shared<GameButton>(model, shader, texture);
	buttonPlayAgain1->Set2DPosition(Globals::screenWidth - 203, 367);
	buttonPlayAgain1->SetSize(340, 220);
	buttonPlayAgain1->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HELPGAME3);
		ResourceManagers::GetInstance()->PlaySound(Click);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonPlayAgain1.push_back(buttonPlayAgain1);

	//button 
	texture = ResourceManagers::GetInstance()->GetTexture("btnPlayGame1.tga");
	std::shared_ptr<GameButton> buttonExit = std::make_shared<GameButton>(model, shader, texture);
	buttonExit->Set2DPosition(Globals::screenWidth - 637, 367);
	buttonExit->SetSize(340, 220);
	buttonExit->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HELPGAME2);
		ResourceManagers::GetInstance()->PlaySound(Click);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonExit.push_back(buttonExit);
	// background
	texture = ResourceManagers::GetInstance()->GetTexture("bg_choosegame.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	ResourceManagers::GetInstance()->PlaySound(name);
}

void ChooseGame::Exit()
{
	ResourceManagers::FreeInstance();
}


void ChooseGame::Pause()
{
}

void ChooseGame::Resume()
{
}


void ChooseGame::HandleEvents()
{
}

void ChooseGame::HandleKeyEvents(int key, bool bIsPressed)
{
}

void ChooseGame::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto buttonExit : m_listButtonExit)
	{
		if (buttonExit->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
	for (auto buttonPlayAgain : m_listButtonPlayAgain)
	{
		if (buttonPlayAgain->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}

	}

	for (auto buttonPlayAgain1 : m_listButtonPlayAgain1)
	{
		if (buttonPlayAgain1->HandleTouchEvents(x, y, bIsPressed))
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

void ChooseGame::HandleMouseMoveEvents(int x, int y)
{
}

void ChooseGame::Update(float deltaTime)
{
	m_background->Update(deltaTime);

	for (auto it : m_listButtonExit)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listButtonPlayAgain)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonPlayAgain1)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
}

void ChooseGame::Draw()
{
	m_background->Draw();
	
	for (auto it : m_listButtonExit)
	{
		it->Draw();
	}
	for (auto it : m_listButtonPlayAgain)
	{
		it->Draw();
	}
	for (auto it : m_listButtonPlayAgain1)
	{
		it->Draw();
	}
	for (auto it : m_listButtonMenu)
	{
		it->Draw();
	}
}