#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class AiPlayGame4

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
	bool isPlayable;
	bool isFaceRight;
	std::string SoundGun = "M4-shoot.wav";
	//decletion
	AiPlayGame4(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~AiPlayGame4();
	//function
	void Dead(int die);
	void Move(int dir);
	// caculate function
	void UpdateAiPlayGame4Pos(GLfloat deltaTime);
	// sprite function
	void AiPlayGame4Update(GLfloat deltaTime);
	void AiPlayGame4Draw();
private:
	std::shared_ptr <SpriteAnimation>AiPlayGame4Sprite;
};