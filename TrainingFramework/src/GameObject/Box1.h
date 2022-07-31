#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;
class Box1

{
public:
	bool isDie;
	std::string name1 = "enemysound.wav";
	GLfloat countTime = 0.0f;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat sizeY = 0.0f;
	GLfloat sizeX = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat YY_Val = 0.0f;
	int state;
	float timer;
	//stat
	//decletion
	Box1(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~Box1();
	//function
	void Dead(int die);
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateBox4Pos(GLfloat deltaTime);
	// ActorACC function
	void Box4Update(GLfloat deltaTime);
	void Box4Draw();
private:
	std::shared_ptr <SpriteAnimation> Box1Sprite;
};