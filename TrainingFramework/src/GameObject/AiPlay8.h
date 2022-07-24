#include "SpriteAnimation.h"
#include "ResourceManagers.h"
class SpriteAnimation;

class AiPlay8

{
public:
	std::string name1 = "M4-shoot.wav";
	bool isDie;
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat X_Val = 0.0f;
	GLfloat m_DisapearTime;
	bool isPlayable;
	bool isFaceRight;
	//stat
	//decletion
	AiPlay8(float x, float y);
	~AiPlay8();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiPlay8Pos(GLfloat deltaTime);
	// sprite function
	void AiPlay8Update(GLfloat deltaTime);
	void AiPlay8Draw();
private:
	std::shared_ptr <SpriteAnimation> AiPlay8Sprite;
};