#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class ButtonA

{
public:
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	ButtonA(float x, float y);
	~ButtonA();
	//function
	void MovePoiter(int dir);
	void Move(int dir);
	// caculate function
	void UpdateButtonAPos(GLfloat deltaTime);
	// sprite function
	void ButtonAUpdate(GLfloat deltaTime);
	void ButtonADraw();
private:
	std::shared_ptr <SpriteAnimation> ButtonASprite;
};