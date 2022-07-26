#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class PlayGame3

{
public:
	bool isDie;
	std::string name = "SoundGame2.wav";
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat sizeX = 0.0f;
	GLfloat sizeY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat YY_Val = 0.0f;
	GLfloat m_DisapearTime;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	PlayGame3(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~PlayGame3();
	//function
	void Dead(int die);
	void Move(int dir);
	// caculate function
	void UpdatePlayGame3Pos(GLfloat deltaTime);
	// sprite function
	void PlayGame3Update(GLfloat deltaTime);
	void PlayGame3Draw();
private:
	std::shared_ptr <SpriteAnimation> PlayGame3Sprite;
};