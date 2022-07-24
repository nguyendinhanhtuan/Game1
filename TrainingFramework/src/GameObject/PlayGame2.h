#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class PlayGame2

{
public:
	std::string name = "SoundGame2.wav";
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	PlayGame2(float x, float y);
	~PlayGame2();
	//function
	void MovePoiter(int dir);
	void Move(int dir);
	// caculate function
	void UpdatePlayGame2Pos(GLfloat deltaTime);
	// sprite function
	void PlayGame2Update(GLfloat deltaTime);
	void PlayGame2Draw();
private:
	std::shared_ptr <SpriteAnimation> PlayGame2Sprite;
};