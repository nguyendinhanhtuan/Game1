#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class ButtonB

{
public:
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	ButtonB(float x, float y);
	~ButtonB();
	//function
	void MovePoiter(int dir);
	void Move(int dir);
	// caculate function
	void UpdateButtonBPos(GLfloat deltaTime);
	// sprite function
	void ButtonBUpdate(GLfloat deltaTime);
	void ButtonBDraw();
private:
	std::shared_ptr <SpriteAnimation> ButtonBSprite;
};