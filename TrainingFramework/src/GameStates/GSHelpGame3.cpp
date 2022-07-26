#include "GSHelpGame3.h"
#include "SpriteAnimation.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"

GSHelpGame3::GSHelpGame3() : GameStateBase(StateType::STATE_HELPGAME3), m_time(0.0f)
{
}


GSHelpGame3::~GSHelpGame3()
{
}


void GSHelpGame3::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo.tga");

	// background
	texture = ResourceManagers::GetInstance()->GetTexture("bg_HelpGame3.tga");
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

void GSHelpGame3::Exit()
{
}


void GSHelpGame3::Pause()
{
}

void GSHelpGame3::Resume()
{
}


void GSHelpGame3::HandleEvents()
{
}

void GSHelpGame3::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSHelpGame3::HandleTouchEvents(int x, int y, bool bIsPressed)
{
}

void GSHelpGame3::HandleMouseMoveEvents(int x, int y)
{
}

void GSHelpGame3::Update(float deltaTime)
{
	m_time += deltaTime;
	if (m_time > 5.5)
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY2);
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

void GSHelpGame3::Draw()
{
	m_background->Draw();
	if (m_time >= 2.0)
	{
		for (auto& it : m_listAnimation)
		{
			it->Draw();
		}

	}
}