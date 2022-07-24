#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class ButtonLeft

{
public:
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	ButtonLeft(float x, float y);
	~ButtonLeft();
	//function
	void MovePoiter(int dir);
	void Move(int dir);
	// caculate function
	void UpdateButtonLeftPos(GLfloat deltaTime);
	// sprite function
	void ButtonLeftUpdate(GLfloat deltaTime);
	void ButtonLeftDraw();
private:
	std::shared_ptr <SpriteAnimation> ButtonLeftSprite;
};
