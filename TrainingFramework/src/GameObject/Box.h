#include "SpriteAnimation.h"
#include "ResourceManagers.h"

class SpriteAnimation;
class Box

{
public:
	std::string name1 = "enemysound.wav";
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
	Box(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~Box();
	//function
	void Move(int dir);
	void onDead();
	// caculate function
	void UpdateBoxPos(GLfloat deltaTime);
	// ActorACC function
	void BoxUpdate(GLfloat deltaTime);
	void BoxDraw();
private:
	std::shared_ptr <SpriteAnimation> BoxSprite;
};
