#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class ButtonRight

{
public:
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	ButtonRight(float x, float y);
	~ButtonRight();
	//function
	void MovePoiter(int dir);
	void Move(int dir);
	// caculate function
	void UpdateButtonRightPos(GLfloat deltaTime);
	// sprite function
	void ButtonRightUpdate(GLfloat deltaTime);
	void ButtonRightDraw();
private:
	std::shared_ptr <SpriteAnimation> ButtonRightSprite;
};