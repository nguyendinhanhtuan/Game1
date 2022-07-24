/*
#include "GSIntro.h"
#include "GSMenu.h"
*/
#include "GSPlay.h"
#include "GSPlay1.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include"GSPrepareToPlay.h"
#include "GameStatebase.h"
#include "GSDie.h"
#include "GSWin.h"
#include "GSHelp.h"
#include "GSHelpGame2.h"
#include "ChooseGame.h"
#include "TeamAWin.h"
#include "TeamBWin.h"
#include "TeamAvTeamB.h"

GameStateBase::GameStateBase(StateType stateType) : m_stateType(stateType)
{}

std::shared_ptr<GameStateBase> GameStateBase::CreateState(StateType stt)
{
	std::shared_ptr<GameStateBase> gs = nullptr;
	switch (stt)
	{
	case StateType::STATE_INVALID:
		break;
	case StateType::STATE_INTRO:
		gs = std::make_shared<GSIntro>();
		break;
	case StateType::STATE_MENU:
		gs = std::make_shared<GSMenu>();
		break;
	case StateType::STATE_PrepareToPlay:
		gs = std::make_shared<GSPrepareToPlay>();
		break;
	case StateType::STATE_PLAY:
		gs = std::make_shared<GSPlay>();
		break;
	case StateType::STATE_PLAY1:
		gs = std::make_shared<GSPlay1>();
		break;
	case StateType::STATE_DIE:
		gs = std::make_shared<GSDie>();
		break;
	case StateType::STATE_WIN:
		gs = std::make_shared<GSWin>();
		break;
	case StateType::STATE_HELP:
		gs = std::make_shared<GSHelp>();
		break;
	case StateType::STATE_HELPGAME2:
		gs = std::make_shared<GSHelpGame2>();
		break;
	case StateType::STATE_CHOOSEGAME:
		gs = std::make_shared<ChooseGame>();
		break;
	case StateType::STATE_TEAMAWIN:
		gs = std::make_shared<TeamAWin>();
		break;
	case StateType::STATE_TEAMBWIN:
		gs = std::make_shared<TeamBWin>();
		break;
	case StateType::STATE_TEAMAVTEAMB:
		gs = std::make_shared<TeamAvTeamB>();
		break;
	default:
		break;
	}
	return gs;
}

StateType GameStateBase::GetGameStateType()
{
	return m_stateType;
}