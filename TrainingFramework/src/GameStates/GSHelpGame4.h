#pragma once
#include "GameStateBase.h"

class SpriteAnimation;

class GSHelpGame4 : public GameStateBase
{
public:
	GSHelpGame4();
	~GSHelpGame4();
	std::string name = "countdownGame2.wav";
	std::string name1 = "SoundGame41.wav";
	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

private:
	std::shared_ptr<Sprite2D>m_background;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	float	m_time;
};