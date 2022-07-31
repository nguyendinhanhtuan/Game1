#include "TeamAWin1.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

TeamAWin1::TeamAWin1() : GameStateBase(StateType::STATE_TEAMAWIN1), m_time(0.0f)
{
}


TeamAWin1::~TeamAWin1()
{
}


void TeamAWin1::Init()
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
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_HELPGAME4);
		ResourceManagers::GetInstance()->PlaySound(Click);
		ResourceManagers::GetInstance()->StopSound(name);
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
	texture = ResourceManagers::GetInstance()->GetTexture("TeamAWin1.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);


	//animation fire
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Fire.tga");
	std::shared_ptr<SpriteAnimation> countFire = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 1, 0, 0.1f);
	countFire->Set2DPosition(Globals::screenWidth / 1.2f, Globals::screenHeight / 3.5f);
	countFire->SetSize(850, 1600);
	m_listAnimationFire.push_back(countFire);
	//animation fire1
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Fire.tga");
	std::shared_ptr<SpriteAnimation> countFire1 = std::make_shared<SpriteAnimation>(model, shader, texture, 6, 1, 0, 0.1f);
	countFire1->Set2DPosition(Globals::screenWidth / 5.5f, Globals::screenHeight / 3.5f);
	countFire1->SetSize(850, 1400);
	m_listAnimationFire1.push_back(countFire1);

	ResourceManagers::GetInstance()->PlaySound(name);
}

void TeamAWin1::Exit()
{
	ResourceManagers::FreeInstance();
}


void TeamAWin1::Pause()
{
}

void TeamAWin1::Resume()
{
}


void TeamAWin1::HandleEvents()
{
}

void TeamAWin1::HandleKeyEvents(int key, bool bIsPressed)
{
}

void TeamAWin1::HandleTouchEvents(int x, int y, bool bIsPressed)
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
	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

}

void TeamAWin1::HandleMouseMoveEvents(int x, int y)
{
}

void TeamAWin1::Update(float deltaTime)
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
	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimationFire)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimationFire1)
	{
		it->Update(deltaTime);
	}
}

void TeamAWin1::Draw()
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
	for (auto it : m_listButtonMenu)
	{
		it->Draw();
	}
	for (auto it : m_listAnimationFire)
	{
		it->Draw();
	}
	for (auto it : m_listAnimationFire1)
	{
		it->Draw();
	}
}