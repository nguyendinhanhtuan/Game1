
#include "GameStateBase.h"
#include <map>
#include "GameManager/Singleton.h"
#include "GameConfig.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class PlayGame3;
class Box;
class GSPlay2 :
	public GameStateBase
{
public:
	std::string name1 = "enemysound.wav";
	std::string name = "SoundGame2.wav";
	GSPlay2();
	~GSPlay2();
	bool	die = false;
	GLfloat m_ACCTime = 0.0f;
	GLfloat m_RandumTime = 0.0f;
	GLfloat countTime = 60.0f;
	GLfloat timeMoveDie = 0.6f;
	int		x;
	bool	aTime = true;
	void	Init() override;
	void	Exit() override;
	void	Pause() override;
	void	Resume() override;
	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	bool	checkCollision(std::shared_ptr<PlayGame3> rect1, std::shared_ptr<Box>  rect2);
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
	std::shared_ptr<Sprite2D>	m_BgTime;
	//playerGame2
	std::shared_ptr<PlayGame3> pointerPlayGame3;
	std::list<std::shared_ptr<PlayGame3>>	m_listPlayGame3Animation;
	//box
	std::shared_ptr<Box> pointerBox;
	std::list<std::shared_ptr<Box>>	m_listBoxAnimation;
		//1
		std::shared_ptr<Box> pointerBox1;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation1;
		//2
		std::shared_ptr<Box> pointerBox2;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation2;
		//3
		std::shared_ptr<Box> pointerBox3;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation3;
		//4
		std::shared_ptr<Box> pointerBox4;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation4;
		//5
		std::shared_ptr<Box> pointerBox5;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation5;
		//6
		std::shared_ptr<Box> pointerBox6;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation6;
		//7
		std::shared_ptr<Box> pointerBox7;
		std::list<std::shared_ptr<Box>>	m_listBoxAnimation7;

	//Button
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<GameButton>>	m_listButton1;
	std::list<std::shared_ptr<GameButton>>	m_listButtonMenu;
};