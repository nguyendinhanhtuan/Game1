#include "GSPlay4.h"
#include <cstdlib>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "ActorACC.h"
#include "Slime.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"
#include "PlayGame4.h"
#include "AiPlayGame4.h"
#include "Box1.h"



GSPlay4::GSPlay4()
{
}


GSPlay4::~GSPlay4()
{
}


void GSPlay4::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_GSPlay4.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 380, 25);
	button->SetSize(150, 50);
	button->SetOnClick([this]() {
		exit(0);
		});
	m_listButton.push_back(button);

	// button Menu
	texture = ResourceManagers::GetInstance()->GetTexture("btn_menu.tga");
	std::shared_ptr<GameButton>  buttonMenu = std::make_shared<GameButton>(model, shader, texture);
	buttonMenu->Set2DPosition(Globals::screenWidth - 650, 30);
	buttonMenu->SetSize(150, 50);
	buttonMenu->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PushState(StateType::STATE_MENU);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButtonMenu.push_back(buttonMenu);

	// button reset
	texture = ResourceManagers::GetInstance()->GetTexture("btn_pause.tga");
	std::shared_ptr<GameButton>  buttonPause = std::make_shared<GameButton>(model, shader, texture);
	buttonPause->Set2DPosition(Globals::screenWidth - 900, 30);
	buttonPause->SetSize(150, 50);
	buttonPause->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PushState(StateType::STATE_HELPGAME4);
		ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButton1.push_back(buttonPause);

	// time
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time = std::make_shared< Text>(shader, font, "60", TextColor::BLACK, 1.5);
	m_time->Set2DPosition(Vector2(640, 147));
	// 00:00
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font1 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_time1 = std::make_shared< Text>(shader, font1, "00:", TextColor::BLACK, 1.5);
	m_time1->Set2DPosition(Vector2(585, 147));

	// Bg Time
	model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	texture = ResourceManagers::GetInstance()->GetTexture("BgTime.tga");
	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BgTime = std::make_shared<Sprite2D>(model, shader, texture);
	m_BgTime->SetSize(400, 400);
	m_BgTime->Set2DPosition(630, 135);


	//PlayerGame2
	std::shared_ptr<PlayGame4> Obj = std::make_shared<PlayGame4>(370, 442, 150, 350);
	pointerPlayGame4 = Obj;
	m_listPlayGame4Animation.push_back(Obj);
	m_KeyPress = 0;

	//AiPlayerGame2
	std::shared_ptr<AiPlayGame4> Bbj = std::make_shared<AiPlayGame4>(1000, 442, 150, 350);
	pointerAiPlayGame4 = Bbj;
	m_listAiPlayGame4Animation.push_back(Bbj);
	m_KeyPress1 = 0;


	// text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font4 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_tttt = std::make_shared< Text>(shader, font4, "Point:", TextColor::BLACK, 1.2);
	m_tttt->Set2DPosition(Vector2(50, 90));

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font5 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_tttt1 = std::make_shared< Text>(shader, font5, "Point:", TextColor::BLACK, 1.2);
	m_tttt1->Set2DPosition(Vector2(1110, 90));

	//point play 
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font2 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_point = std::make_shared< Text>(shader, font2, "0", TextColor::BLACK, 1.2);
	m_point->Set2DPosition(Vector2(135, 90));

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font3 = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_pointAi = std::make_shared< Text>(shader, font3, "0", TextColor::BLACK, 1.2);
	m_pointAi->Set2DPosition(Vector2(1200, 90));

	//Box
	std::shared_ptr<Box1> BoxObj = std::make_shared<Box1>(500, -100, 150, 350);//500 , 100
	pointerBoxGame4 = BoxObj;
	m_listBoxAnimationGame4.push_back(BoxObj);
		//1
		std::shared_ptr<Box1> BoxObj1 = std::make_shared<Box1>(600, -200, 150, 350);
		pointerBoxGame41 = BoxObj1;
		m_listBoxAnimationGame41.push_back(BoxObj1);
		//2
		std::shared_ptr<Box1> BoxObj2 = std::make_shared<Box1>(700, -300, 150, 350);
		pointerBoxGame42 = BoxObj2;
		m_listBoxAnimationGame42.push_back(BoxObj2);
		//3
		std::shared_ptr<Box1> BoxObj3 = std::make_shared<Box1>(800, -400, 150, 350);
		pointerBoxGame43 = BoxObj3;
		m_listBoxAnimationGame43.push_back(BoxObj3);
		//4
		std::shared_ptr<Box1> BoxObj4 = std::make_shared<Box1>(900, -500, 150, 350);
		pointerBoxGame44 = BoxObj4;
		m_listBoxAnimationGame44.push_back(BoxObj4);
		//5
		std::shared_ptr<Box1> BoxObj5 = std::make_shared<Box1>(550, 1200, 150, 350);
		pointerBoxGame45 = BoxObj5;
		m_listBoxAnimationGame45.push_back(BoxObj5);
		//6
		std::shared_ptr<Box1> BoxObj6 = std::make_shared<Box1>(650, 1000, 150, 350);
		pointerBoxGame46 = BoxObj6;
		m_listBoxAnimationGame46.push_back(BoxObj6);
		//7
		std::shared_ptr<Box1> BoxObj7 = std::make_shared<Box1>(750, 1100, 150, 350);
		pointerBoxGame47 = BoxObj7;
		m_listBoxAnimationGame47.push_back(BoxObj7);
		//8
		std::shared_ptr<Box1> BoxObj8 = std::make_shared<Box1>(850, 900, 150, 350);
		pointerBoxGame48 = BoxObj8;
		m_listBoxAnimationGame48.push_back(BoxObj8);
		//9
		std::shared_ptr<Box1> BoxObj9 = std::make_shared<Box1>(950, 800, 150, 350);
		pointerBoxGame49 = BoxObj9;
		m_listBoxAnimationGame49.push_back(BoxObj9);

	//Box
		std::shared_ptr<Box1> BoxObj01 = std::make_shared<Box1>(-300, 250, 150, 350);//500 , 100
		pointerBoxGame40 = BoxObj01;
		m_listBoxAnimationGame40.push_back(BoxObj01);
		//1
		std::shared_ptr<Box1> BoxObj11 = std::make_shared<Box1>(-200, 330, 150, 350);
		pointerBoxGame411 = BoxObj11;
		m_listBoxAnimationGame411.push_back(BoxObj11);
		//2
		std::shared_ptr<Box1> BoxObj22 = std::make_shared<Box1>(-400, 620, 150, 350);
		pointerBoxGame422 = BoxObj2;
		m_listBoxAnimationGame422.push_back(BoxObj22);
		//3
		std::shared_ptr<Box1> BoxObj33 = std::make_shared<Box1>(-600, 490, 150, 350);
		pointerBoxGame433 = BoxObj33;
		m_listBoxAnimationGame433.push_back(BoxObj33);
		//4
		std::shared_ptr<Box1> BoxObj44 = std::make_shared<Box1>(-500, 500, 150, 350);
		pointerBoxGame444 = BoxObj44;
		m_listBoxAnimationGame444.push_back(BoxObj44);
		//5
		std::shared_ptr<Box1> BoxObj55 = std::make_shared<Box1>(1300, 220, 150, 350);
		pointerBoxGame455 = BoxObj55;
		m_listBoxAnimationGame455.push_back(BoxObj55);
		//6
		std::shared_ptr<Box1> BoxObj66 = std::make_shared<Box1>(1400, 560, 150, 350);
		pointerBoxGame466 = BoxObj66;
		m_listBoxAnimationGame466.push_back(BoxObj66);
		//7
		std::shared_ptr<Box1> BoxObj77 = std::make_shared<Box1>(1450, 350, 150, 350);
		pointerBoxGame477 = BoxObj77;
		m_listBoxAnimationGame477.push_back(BoxObj77);
		//8
		std::shared_ptr<Box1> BoxObj88 = std::make_shared<Box1>(1380, 700, 150, 350);
		pointerBoxGame488 = BoxObj88;
		m_listBoxAnimationGame488.push_back(BoxObj88);
		//9
		std::shared_ptr<Box1> BoxObj99 = std::make_shared<Box1>(1330, 650, 150, 350);
		pointerBoxGame499 = BoxObj99;
		m_listBoxAnimationGame499.push_back(BoxObj99);



	//ResourceManagers::GetInstance()->PlaySound(name);


}

void GSPlay4::Exit()
{
}


void GSPlay4::Pause()
{
}

void GSPlay4::Resume()
{
}


void GSPlay4::HandleEvents()
{
}

void GSPlay4::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress1 |= 1;
			break;
		case KEY_RIGHT:
			m_KeyPress1 |= 1 << 2;
			break;
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1 << 1;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1 << 3;
			break;
		case KEY_DOWN:
			m_KeyPress1 |= 1 << 1;
			break;
		case KEY_UP:
			m_KeyPress1 |= 1 << 3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress1 ^= 1;
			break;
		case KEY_RIGHT:
			m_KeyPress1 ^= 1 << 2;
			break;
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		case KEY_DOWN:
			m_KeyPress1 ^= 1 << 1;
			break;
		case KEY_UP:
			m_KeyPress1 ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}


void GSPlay4::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}

	for (auto buttonPause : m_listButton1)
	{
		if (buttonPause->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
	for (auto buttonMenu : m_listButtonMenu)
	{
		if (buttonMenu->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay4::HandleMouseMoveEvents(int x, int y)
{

}



void GSPlay4::CountTime(GLfloat deltaTime)
{
	if (countTime > 0)
	{
		countTime -= deltaTime;
		m_time->SetText(std::to_string(int(countTime)));
	}
	if (countTime <= 0)
	{

		if (countPoints == countPointsAi)
		{
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMAVTEAMB1);
			ResourceManagers::GetInstance()->StopSound(name);
		}
		else if (countPoints > countPointsAi)
		{
			ResourceManagers::GetInstance()->StopSound(name);
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMAWIN1);
		}
		else if (countPoints < countPointsAi)
		{
			ResourceManagers::GetInstance()->StopSound(name);
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_TEAMAWIN2);
		}
	}
}

void GSPlay4::CountPoint(GLfloat point)
{
	m_point->SetText(std::to_string(int(point)));
}

void GSPlay4::CountPointAi(GLfloat point)
{
	m_pointAi->SetText(std::to_string(int(point)));
}

bool GSPlay4::checkCollision(std::shared_ptr< PlayGame4 > rect1, std::shared_ptr< Box1 >  rect2)
{
	int left_a = rect1->posX ;
	int right_a = rect1->posX + rect1->sizeX - 180;
	int top_a = rect1->posY -200 ;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX-70;
	int right_b = rect2->posX + rect2->sizeX -190  ;
	int top_b = rect2->posY +310 ;
	int bottom_b = rect2->posY + rect2->sizeY+30;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}
bool GSPlay4::checkCollision(std::shared_ptr< AiPlayGame4 > rect1, std::shared_ptr< Box1 >  rect2)
{
	int left_a = rect1->posX;
	int right_a = rect1->posX + rect1->sizeX - 180;
	int top_a = rect1->posY -200 ;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX - 70;
	int right_b = rect2->posX + rect2->sizeX - 190;
	int top_b = rect2->posY + 310;
	int bottom_b = rect2->posY + rect2->sizeY + 30;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}


void GSPlay4::Update(float deltaTime)
{
	if (checkCollision(pointerPlayGame4, pointerBoxGame4) == true )
	{
		if (state != 0) {
			pointerBoxGame4 -> Dead(1);
			countPoints ++ ;
			
			ResourceManagers::GetInstance()->PlaySound(name1);
		}
		state = 0;
	}else 
	{
		if (state != 1)
		{
	
		}
		state = 1;
	}

	if (checkCollision(pointerPlayGame4, pointerBoxGame41) == true)
	{
		if (state != 0) {
			pointerBoxGame41->Dead(1);
			countPoints ++ ;
			ResourceManagers::GetInstance()->PlaySound(name1);
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame42) == true)
	{
		if (state != 0) {
			pointerBoxGame42->Dead(1);
			countPoints++;
			ResourceManagers::GetInstance()->PlaySound(name1);
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame43) == true)
	{
		if (state != 0) {
			pointerBoxGame43->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame44) == true)
	{
		if (state != 0) {
			pointerBoxGame44->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame45) == true)
	{
		if (state != 0) {
			pointerBoxGame45->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame46) == true)
	{
		if (state != 0) {
			pointerBoxGame46->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame47) == true)
	{
		if (state != 0) {
			pointerBoxGame47->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame48) == true)
	{
		if (state != 0) {
			pointerBoxGame48->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame49) == true)
	{
		if (state != 0) {
			pointerBoxGame49->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
//////////////////////////////////
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame4) == true)
	{
		if (state != 0) {
			pointerBoxGame4->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}

	if (checkCollision(pointerAiPlayGame4, pointerBoxGame41) == true)
	{
		if (state != 0) {
			pointerBoxGame41->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame42) == true)
	{
		if (state != 0) {
			pointerBoxGame42->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame43) == true)
	{
		if (state != 0) {
			pointerBoxGame43->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame44) == true)
	{
		if (state != 0) {
			pointerBoxGame44->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame45) == true)
	{
		if (state != 0) {
			pointerBoxGame45->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame46) == true)
	{
		if (state != 0) {
			pointerBoxGame46->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame47) == true)
	{
		if (state != 0) {
			pointerBoxGame47->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame48) == true)
	{
		if (state != 0) {
			pointerBoxGame48->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame49) == true)
	{
		if (state != 0) {
			pointerBoxGame49->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	///////////////////////////////////////////////////////////////////////
	if (checkCollision(pointerPlayGame4, pointerBoxGame40) == true)
	{
		if (state != 0) {
			pointerBoxGame40->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;


		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{

		}
		state = 1;
	}

	if (checkCollision(pointerPlayGame4, pointerBoxGame411) == true)
	{
		if (state != 0) {
			pointerBoxGame411->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame422) == true)
	{
		if (state != 0) {
			pointerBoxGame422->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame433) == true)
	{
		if (state != 0) {
			pointerBoxGame433->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame444) == true)
	{
		if (state != 0) {
			pointerBoxGame444->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerPlayGame4, pointerBoxGame455) == true)
	{
		if (state != 0) {
			pointerBoxGame455->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame466) == true)
	{
		if (state != 0) {
			pointerBoxGame466->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame477) == true)
	{
		if (state != 0) {
			pointerBoxGame477->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame488) == true)
	{
		if (state != 0) {
			pointerBoxGame488->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerPlayGame4, pointerBoxGame499) == true)
	{
		if (state != 0) {
			pointerBoxGame499->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPoints++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	//////////////////////////////////
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame40) == true)
	{
		if (state != 0) {
			pointerBoxGame40->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}

	if (checkCollision(pointerAiPlayGame4, pointerBoxGame411) == true)
	{
		if (state != 0) {
			pointerBoxGame411->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame422) == true)
	{
		if (state != 0) {
			pointerBoxGame422->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame433) == true)
	{
		if (state != 0) {
			pointerBoxGame433->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame444) == true)
	{
		if (state != 0) {
			pointerBoxGame444->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	if (checkCollision(pointerAiPlayGame4, pointerBoxGame455) == true)
	{
		if (state != 0) {
			pointerBoxGame455->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame466) == true)
	{
		if (state != 0) {
			pointerBoxGame466->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame477) == true)
	{
		if (state != 0) {
			pointerBoxGame477->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame488) == true)
	{
		if (state != 0) {
			pointerBoxGame488->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}	if (checkCollision(pointerAiPlayGame4, pointerBoxGame499) == true)
	{
		if (state != 0) {
			pointerBoxGame499->Dead(1);
			ResourceManagers::GetInstance()->PlaySound(name1);
			countPointsAi++;
		}
		state = 0;
	}
	else
	{
		if (state != 1)
		{
		}
		state = 1;
	}
	pointerBoxGame4->Move(1);
	pointerBoxGame41->Move(2);
	pointerBoxGame42->Move(3);
	pointerBoxGame43->Move(4);
	pointerBoxGame44->Move(5);
	pointerBoxGame45->Move(6);
	pointerBoxGame46->Move(7);
	pointerBoxGame47->Move(8);
	pointerBoxGame48->Move(9);
	pointerBoxGame49->Move(10);
	pointerBoxGame40->Move(11);
	pointerBoxGame411->Move(12);
	pointerBoxGame422->Move(13);
	pointerBoxGame433->Move(14);
	pointerBoxGame444->Move(15);
	pointerBoxGame455->Move(16);
	pointerBoxGame466->Move(17);
	pointerBoxGame477->Move(18);
	pointerBoxGame488->Move(19);
	pointerBoxGame499->Move(20);
	//////////////////////////////////////////////////
	for (auto it : m_listBoxAnimationGame4)
	{
		it->UpdateBox4Pos(deltaTime);
	}
		//1
		for (auto it : m_listBoxAnimationGame41)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimationGame42)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimationGame43)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimationGame44)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimationGame45)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimationGame46)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimationGame47)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//8
		for (auto it : m_listBoxAnimationGame48)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//9
		for (auto it : m_listBoxAnimationGame49)
		{
			it->UpdateBox4Pos(deltaTime);
		}
///////////////////////////////////////////////////////////////
		for (auto it : m_listBoxAnimationGame40)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//1
		for (auto it : m_listBoxAnimationGame411)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimationGame422)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimationGame433)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimationGame444)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimationGame455)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimationGame466)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimationGame477)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//8
		for (auto it : m_listBoxAnimationGame488)
		{
			it->UpdateBox4Pos(deltaTime);
		}
		//9
		for (auto it : m_listBoxAnimationGame499)
		{
			it->UpdateBox4Pos(deltaTime);
		}
	CountTime(deltaTime);
	//PlayGame2 Move
	for (auto it : m_listPlayGame4Animation)
	{
		it->UpdatePlayGame4Pos(deltaTime);
	}
	for (auto it : m_listAiPlayGame4Animation)
	{
		it->UpdateAiPlayGame4Pos(deltaTime);
	}

	for (auto it : m_listButtonMenu)
	{
		it->Update(deltaTime);
	}


	switch (m_KeyPress)//Handle Key event
	{
	case 0:
		pointerPlayGame4->Move(0);

		break;
	case 1:
		pointerPlayGame4->Move(1);

		break;
	case 2:
		pointerPlayGame4->Move(2);

		break;
	case 8:
		pointerPlayGame4->Move(3);

		break;
	case 4:
		pointerPlayGame4->Move(4);
	
		break;
	default:
		break;
	}
	////////////////////////////////////////////
	//Play2
	
	switch (m_KeyPress1)//Handle Key event
	{
	case 0:
		pointerAiPlayGame4->Move(0);

		break;
	case 1:
		pointerAiPlayGame4->Move(1);

		break;
	case 2:
		pointerAiPlayGame4->Move(2);

		break;
	case 8:
		pointerAiPlayGame4->Move(3);

		break;
	case 4:
		pointerAiPlayGame4->Move(4);

		break;
	default:
		break;
	}
	

	CountPoint(countPoints);
	CountPointAi(countPointsAi);
	//Box
	for (auto it : m_listBoxAnimationGame4)
	{
		it->Box4Update(deltaTime);
	}
		//1
		for (auto it : m_listBoxAnimationGame41)
		{
			it->Box4Update(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimationGame42)
		{
			it->Box4Update(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimationGame43)
		{
			it->Box4Update(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimationGame44)
		{
			it->Box4Update(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimationGame45)
		{
			it->Box4Update(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimationGame46)
		{
			it->Box4Update(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimationGame47)
		{
			it->Box4Update(deltaTime);
		}
		//8
		for (auto it : m_listBoxAnimationGame48)
		{
			it->Box4Update(deltaTime);
		}
		//9
		for (auto it : m_listBoxAnimationGame49)
		{
			it->Box4Update(deltaTime);
		}
		//////////////////////////////////////////////////////////////
			//Box
		for (auto it : m_listBoxAnimationGame40)
		{
			it->Box4Update(deltaTime);
		}
		//1
		for (auto it : m_listBoxAnimationGame411)
		{
			it->Box4Update(deltaTime);
		}
		//2
		for (auto it : m_listBoxAnimationGame422)
		{
			it->Box4Update(deltaTime);
		}
		//3
		for (auto it : m_listBoxAnimationGame433)
		{
			it->Box4Update(deltaTime);
		}
		//4
		for (auto it : m_listBoxAnimationGame444)
		{
			it->Box4Update(deltaTime);
		}
		//5
		for (auto it : m_listBoxAnimationGame455)
		{
			it->Box4Update(deltaTime);
		}
		//6
		for (auto it : m_listBoxAnimationGame466)
		{
			it->Box4Update(deltaTime);
		}
		//7
		for (auto it : m_listBoxAnimationGame477)
		{
			it->Box4Update(deltaTime);
		}
		//8
		for (auto it : m_listBoxAnimationGame488)
		{
			it->Box4Update(deltaTime);
		}
		//9
		for (auto it : m_listBoxAnimationGame499)
		{
			it->Box4Update(deltaTime);
		}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listPlayGame4Animation)
	{
		it->PlayGame4Update(deltaTime);
	}
	for (auto it : m_listAiPlayGame4Animation)
	{
		it->AiPlayGame4Update(deltaTime);
	}

}

void GSPlay4::Draw()
{
	m_background->Draw();
	m_BgTime->Draw();
	m_time->Draw();
	m_time1->Draw();
	m_tttt->Draw();
	m_tttt1->Draw();
	m_point->Draw();
	m_pointAi->Draw();
	for (auto& it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listButton1)
	{
		it->Draw();
	}

	for (auto& it : m_listPlayGame4Animation)
	{
		it->PlayGame4Draw();
	}
	for (auto& it : m_listAiPlayGame4Animation)
	{
		it->AiPlayGame4Draw();
	}

	for (auto& it : m_listButtonMenu)
	{
		it->Draw();
	}
	for (auto& it : m_listBoxAnimationGame4)
	{
		it->Box4Draw();
	}
		//1
		for (auto& it : m_listBoxAnimationGame41)
		{
			it->Box4Draw();
		}
		//2
		for (auto& it : m_listBoxAnimationGame42)
		{
			it->Box4Draw();
		}
		//3
		for (auto& it : m_listBoxAnimationGame43)
		{
			it->Box4Draw();
		}
		//4
		for (auto& it : m_listBoxAnimationGame44)
		{
			it->Box4Draw();
		}
		//5
		for (auto& it : m_listBoxAnimationGame45)
		{
			it->Box4Draw();
		}
		//6
		for (auto& it : m_listBoxAnimationGame46)
		{
			it->Box4Draw();
		}
		//7
		for (auto& it : m_listBoxAnimationGame47)
		{
			it->Box4Draw();
		}
		//8
		for (auto& it : m_listBoxAnimationGame48)
		{
			it->Box4Draw();
		}
		//9
		for (auto& it : m_listBoxAnimationGame49)
		{
			it->Box4Draw();
		}

		for (auto& it : m_listBoxAnimationGame40)
		{
			it->Box4Draw();
		}
		//1
		for (auto& it : m_listBoxAnimationGame411)
		{
			it->Box4Draw();
		}
		//2
		for (auto& it : m_listBoxAnimationGame422)
		{
			it->Box4Draw();
		}
		//3
		for (auto& it : m_listBoxAnimationGame433)
		{
			it->Box4Draw();
		}
		//4
		for (auto& it : m_listBoxAnimationGame444)
		{
			it->Box4Draw();
		}
		//5
		for (auto& it : m_listBoxAnimationGame455)
		{
			it->Box4Draw();
		}
		//6
		for (auto& it : m_listBoxAnimationGame466)
		{
			it->Box4Draw();
		}
		//7
		for (auto& it : m_listBoxAnimationGame477)
		{
			it->Box4Draw();
		}
		//8
		for (auto& it : m_listBoxAnimationGame488)
		{
			it->Box4Draw();
		}
		//9
		for (auto& it : m_listBoxAnimationGame499)
		{
			it->Box4Draw();
		}

}