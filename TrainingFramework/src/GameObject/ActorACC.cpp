#include "ActorACC.h"


ActorACC::ActorACC(float x, float y)
{
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ActorACC.tga");
	ActorACCSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.3f);
	ActorACCSprite->SetSize(200, 600);
	ActorACCSprite->Set2DPosition(posX, posY);
	state = 0;
	timer = 1.0f;
}

ActorACC::~ActorACC()
{
}



void ActorACC::Move(int dir)
{
	
	switch (dir)
	{
	case 0:
		if (state != 0) {
			//std::printf("dung yen");
			timer = 1.0f;
			ActorACCSprite->SetCurrentAction(0);
			ResourceManagers::GetInstance()->StopSound(name);
		}
			state = 0;
			break;
	case 1:
		if (state != 1)
		{
			//std::printf("count = %d",count);
			timer = 1.0f;
			ActorACCSprite->SetCurrentAction(1);
			count++;
			if(count <=3 )
			{
			ResourceManagers::GetInstance()->PlaySound(name);
			ResourceManagers::GetInstance()->PlaySound(name);
			}
		}
			ActorACCSprite->Set2DPosition(posX, 330);
			state = 1;
			break;
	default:
		break;
	}
	
}


void ActorACC::ActorACCDraw()
{
	ActorACCSprite->Draw();
}

void ActorACC::UpdateActorACCPos(GLfloat deltaTime)
{
	ActorACCSprite->Set2DPosition(posX, posY);
	if (state == 1) timer -= deltaTime;
}

void ActorACC::ActorACCUpdate(GLfloat deltaTime)
{
	if (timer > 0.0f) {
		ActorACCSprite->Update(deltaTime);
	}
}