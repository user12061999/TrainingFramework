#include "GSOption.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSOption::GSOption()
{
	
}


GSOption::~GSOption()
{
}


void GSOption::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition((float)screenWidth / 2, (float)screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//audio button
	texture = ResourceManagers::GetInstance()->GetTexture("button_audio");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition((float)screenWidth / 2, 500);
	button->SetSize(50, 30);
	button->SetOnClick([]() {
		
		});
	m_listButton.push_back(button);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition((float)screenWidth / 2, 600);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});
	m_listButton.push_back(button);

	//text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_Text_gameName = std::make_shared< Text>(shader, font, "day la option", TEXT_COLOR::RED, 1.0);
	m_Text_gameName->Set2DPosition(Vector2((float)screenWidth / 2, (float)screenHeight / 2));
}

void GSOption::Exit()
{

}


void GSOption::Pause()
{

}

void GSOption::Resume()
{

}


void GSOption::HandleEvents()
{

}

void GSOption::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSOption::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSOption::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSOption::Draw()
{
	m_BackGround->Draw();
	m_Text_gameName->Draw();
	for (auto but : m_listButton) {
		but->Draw();
	}
}
