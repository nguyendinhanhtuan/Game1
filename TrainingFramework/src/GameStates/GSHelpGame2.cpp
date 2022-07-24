#include "GSHelpGame2.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

GSHelpGame2::GSHelpGame2() : GameStateBase(StateType::STATE_HELPGAME2), m_time(0.0f)
{
}


GSHelpGame2::~GSHelpGame2()
{
}


void GSHelpGame2::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo.tga");

	// background
	texture = ResourceManagers::GetInstance()->GetTexture("bg_HelpGame2.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//count 3 2 1 letgo
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("Count1.tga");
	std::shared_ptr<SpriteAnimation> count = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 1, 0, 1.1f);
	count->Set2DPosition(Globals::screenWidth / 2.0f, Globals::screenHeight / 2.0f);
	count->SetSize(300, 1000);
	m_listAnimation.push_back(count);
	ResourceManagers::GetInstance()->PlaySound(name);
}

void GSHelpGame2::Exit()
{
}


void GSHelpGame2::Pause()
{
}

void GSHelpGame2::Resume()
{
}


void GSHelpGame2::HandleEvents()
{
}

void GSHelpGame2::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSHelpGame2::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSHelpGame2::HandleMouseMoveEvents(int x, int y)
{
}

void GSHelpGame2::Update(float deltaTime)
{
	m_time += deltaTime;
	if (m_time > 5.5)
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY1);
		//ResourceManagers::GetInstance()->StopSound(name);
		ResourceManagers::GetInstance()->PlaySound(name1);
		ResourceManagers::GetInstance()->StopSound(name);

		m_time = 0;
	}

	if (m_time >= 2.0)
	{
		for (auto it : m_listAnimation)
		{
		it->Update(deltaTime);
		}
	}
}

void GSHelpGame2::Draw()
{
	m_background->Draw();
	if(m_time >= 2.0)
	{
		for (auto& it : m_listAnimation)
		{
		it->Draw();
		}
		
	}
}