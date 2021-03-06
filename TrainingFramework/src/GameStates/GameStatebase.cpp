/*
#include "GSIntro.h"
#include "GSMenu.h"
*/
#include "GSPlay.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSCredit.h"
#include "GSWelcome.h"
#include "GSOption.h"
#include "GameStatebase.h"

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateTypes stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case STATE_INVALID:
		break;
	case STATE_Intro:
		gs = std::make_shared<GSIntro>();
		break;
	case STATE_Menu:
		gs = std::make_shared<GSMenu>();
		break;
	case STATE_Play:
		gs = std::make_shared<GSPlay>();
		break;
	case STATE_CREDIT:
		gs = std::make_shared<GSCredit>();
		break;
	case STATE_WELCOME:
		gs = std::make_shared<GSWelcome>();
		break;
	case STATE_OPTION:
		gs = std::make_shared<GSOption>();
		break;
	default:
		break;
	}
	return gs;
}