#pragma once
#include "GameStateBase.h"
#include <map>
#include "GameManager/Singleton.h"
#include "GameConfig.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class PlayGame2;
class AiPlayGame2;
class ButtonB;
class ButtonA;
class ButtonLeft;
class ButtonRight;
class GSPlay1 :
	public GameStateBase
{
public:
	std::string name1 = "enemysound.wav";
	std::string name = "SoundGame2.wav";
	GSPlay1();
	~GSPlay1();
	GLfloat	countPoints = 0.0f;
	GLfloat	countPointsAi = 0.0f;
	bool	die = false;
	GLfloat m_ACCTime = 0.0f;
	GLfloat m_RandumTime = 0.0f;
	GLfloat countTime = 60.0f;
	void	CountTime(GLfloat deltaTime);
	void	CountPoint(GLfloat point );
	void	CountPointAi(GLfloat  point);
	bool	aTime = true;
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
	int		m_KeyPress;
	int		m_KeyPress1;

private:
	//
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_time;
	std::shared_ptr<Text>		m_time1;
	std::shared_ptr<Text>		m_tttt;
	std::shared_ptr<Text>		m_tttt1;
	std::shared_ptr<Text>		m_point;
	std::shared_ptr<Text>		m_pointAi;
	std::shared_ptr<Sprite2D>	m_BgTime;

	//playerGame2
	std::shared_ptr<PlayGame2> pointerPlayGame2;
	std::list<std::shared_ptr<PlayGame2>>	m_listPlayGame2Animation;

	//AiPlayGame2
	std::shared_ptr<AiPlayGame2> pointerAiPlayGame2;
	std::list<std::shared_ptr<AiPlayGame2>>	m_listAiPlayGame2Animation;

	//button A
	std::shared_ptr<ButtonA> pointerButtonA;
	std::list<std::shared_ptr<ButtonA>>	m_listButtonAAnimation;

	//button D
	std::shared_ptr<ButtonB> pointerButtonB;
	std::list<std::shared_ptr<ButtonB>>	m_listButtonBAnimation;

	//button Left
	std::shared_ptr<ButtonLeft> pointerButtonLeft;
	std::list<std::shared_ptr<ButtonLeft>>	m_listButtonLeftAnimation;

	//ButtonRight
	std::shared_ptr<ButtonRight> pointerButtonRight;
	std::list<std::shared_ptr<ButtonRight>>	m_listButtonRightAnimation;
	//Button
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;

	// none
	std::list<std::shared_ptr<Text>>	m_listTime;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;

	std::list<std::shared_ptr<GameButton>>	m_listButtonMenu;
};
