#include "DieGame3.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

DieGame3::DieGame3() : GameStateBase(StateType::STATE_DIEGAME3), m_time(0.0f)
{
}


DieGame3::~DieGame3()
{
}


void DieGame3::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//button Menu
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_MenuAgian.tga");
	std::shared_ptr<GameButton> buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 50, 50);
	buttonMenu->SetSize(100, 100);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonMenu.push_back(buttonMenu);

	//button Play again
	texture = ResourceManagers::GetInstance()->GetTexture("btn_PlayAgain.tga");
	std::shared_ptr<GameButton> buttonPlayAgain = std::make_shared<GameButton>(model, shader, texture);
	buttonPlayAgain->Set2DPosition(Globals::screenWidth - 780, 650);
	buttonPlayAgain->SetSize(100, 100);
	buttonPlayAgain->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PrepareToPlay);
		ResourceManagers::GetInstance()->PlaySound(Click);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonPlayAgain.push_back(buttonPlayAgain);

	//button exit
	texture = ResourceManagers::GetInstance()->GetTexture("btn_ExitGame .tga");
	std::shared_ptr<GameButton> buttonExit = std::make_shared<GameButton>(model, shader, texture);
	buttonExit->Set2DPosition(Globals::screenWidth - 490, 650);
	buttonExit->SetSize(100, 100);
	buttonExit->SetOnClick([this]() {
		exit(0);
		//ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonExit.push_back(buttonExit);
	// background
	texture = ResourceManagers::GetInstance()->GetTexture("DieGame3.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);


	ResourceManagers::GetInstance()->PlaySound(name);
}

void DieGame3::Exit()
{
	ResourceManagers::FreeInstance();
}


void DieGame3::Pause()
{
}

void DieGame3::Resume()
{
}


void DieGame3::HandleEvents()
{
}

void DieGame3::HandleKeyEvents(int key, bool bIsPressed)
{
}

void DieGame3::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto buttonExit : m_listButtonExit)
	{
		if (buttonExit->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
	for (auto buttonPlayAgain : m_listButtonPlayAgain)
	{
		if (buttonPlayAgain->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			//ResourceManagers::GetInstance()->StopSound(name);
			break;
		}
	}
}

void DieGame3::HandleMouseMoveEvents(int x, int y)
{
}

void DieGame3::Update(float deltaTime)
{
	m_background->Update(deltaTime);

	for (auto it : m_listButtonExit)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonPlayAgain)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
}

void DieGame3::Draw()
{
	m_background->Draw();
	for (auto& it : m_listAnimation)
	{
		it->Draw();
	}
	for (auto it : m_listButtonExit)
	{
		it->Draw();
	}
	for (auto it : m_listButtonPlayAgain)
	{
		it->Draw();
	}
	for (auto it : m_listButtonMenu)
	{
		it->Draw();
	}
}