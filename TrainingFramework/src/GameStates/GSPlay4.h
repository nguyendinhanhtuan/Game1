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
class PlayGame4;
class AiPlayGame4;
class Box1;

class GSPlay4 :
	public GameStateBase
{
public:
	std::string name1 = "Kill.wav";
	std::string name = "SoundGame41.wav";
	GSPlay4();
	~GSPlay4();
	GLfloat	countPoints = 0.0f;
	GLfloat	countPointsAi = 0.0f;
	bool	die = false;
	GLfloat m_ACCTime = 0.0f;
	GLfloat m_RandumTime = 0.0f;
	GLfloat countTime = 60.0f;
	GLfloat timeMoveDie = 0.6f;
	int		state = 0;
	void	CountTime(GLfloat deltaTime);
	void	CountPoint(GLfloat point);
	void	CountPointAi(GLfloat  point);
	bool	aTime = true;
	void	Init() override;
	void	Exit() override;
	void	Pause() override;
	void	Resume() override;
	bool	checkCollision(std::shared_ptr<PlayGame4> rect1, std::shared_ptr<Box1>  rect2);
	bool	checkCollision(std::shared_ptr<AiPlayGame4> rect1, std::shared_ptr<Box1>  rect2);
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
	std::shared_ptr<PlayGame4> pointerPlayGame4;
	std::list<std::shared_ptr<PlayGame4>>	m_listPlayGame4Animation;

	//AiPlayGame2
	std::shared_ptr<AiPlayGame4> pointerAiPlayGame4;
	std::list<std::shared_ptr<AiPlayGame4>>	m_listAiPlayGame4Animation;

	//Button
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;

	// none
	std::list<std::shared_ptr<Text>>	m_listTime;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;

	std::list<std::shared_ptr<GameButton>>	m_listButtonMenu;

	//Ai
	std::shared_ptr<Box1> pointerBoxGame4;
	std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame4;
		//1
		std::shared_ptr<Box1> pointerBoxGame41;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame41;
		//2
		std::shared_ptr<Box1> pointerBoxGame42;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame42;
		//3
		std::shared_ptr<Box1> pointerBoxGame43;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame43;
		//4
		std::shared_ptr<Box1> pointerBoxGame44;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame44;
		//5
		std::shared_ptr<Box1> pointerBoxGame45;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame45;
		//6
		std::shared_ptr<Box1> pointerBoxGame46;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame46;
		//7
		std::shared_ptr<Box1> pointerBoxGame47;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame47;
		//8
		std::shared_ptr<Box1> pointerBoxGame48;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame48;
		//9
		std::shared_ptr<Box1> pointerBoxGame49;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame49;
	//Ai01
		std::shared_ptr<Box1> pointerBoxGame40;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame40;
		//1
		std::shared_ptr<Box1> pointerBoxGame411;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame411;
		//2
		std::shared_ptr<Box1> pointerBoxGame422;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame422;
		//3
		std::shared_ptr<Box1> pointerBoxGame433;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame433;
		//4
		std::shared_ptr<Box1> pointerBoxGame444;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame444;
		//5
		std::shared_ptr<Box1> pointerBoxGame455;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame455;
		//6
		std::shared_ptr<Box1> pointerBoxGame466;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame466;
		//7
		std::shared_ptr<Box1> pointerBoxGame477;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame477;
		//8
		std::shared_ptr<Box1> pointerBoxGame488;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame488;
		//9
		std::shared_ptr<Box1> pointerBoxGame499;
		std::list<std::shared_ptr<Box1>>	m_listBoxAnimationGame499;
};