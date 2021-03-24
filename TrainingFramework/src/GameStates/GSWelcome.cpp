#include "GSWelcome.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSWelcome::GSWelcome()
{
	m_time = 0;
}


GSWelcome::~GSWelcome()
{
}


void GSWelcome::Init()
{

	
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("welcome");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_Text_gameName = std::make_shared< Text>(shader, font, "DAY LA WELCOME", TEXT_COLOR::RED, 1.0);
	m_Text_gameName->Set2DPosition(Vector2(50, (float)screenHeight/2));
}

void GSWelcome::Exit()
{

}


void GSWelcome::Pause()
{

}

void GSWelcome::Resume()
{

}


void GSWelcome::HandleEvents()
{

}

void GSWelcome::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSWelcome::HandleTouchEvents(int x, int y, bool bIsPressed)
{

}

void GSWelcome::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	m_time += deltaTime;
	if (m_time > 3)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		m_time = 0;
	}
}

void GSWelcome::Draw()
{
	m_BackGround->Draw();
	m_Text_gameName->Draw();
}
