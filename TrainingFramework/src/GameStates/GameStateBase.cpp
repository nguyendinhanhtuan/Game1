/*
#include "GSIntro.h"
#include "GSMenu.h"
*/
#include "GSPlay.h"
#include "GSPlay1.h"
#include "GSPlay2.h"
#include "GSPlay4.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include"GSPrepareToPlay.h"
#include "GameStatebase.h"
#include "GSDie.h"
#include "GSWin.h"
#include "GSHelp.h"
#include "GSHelpGame2.h"
#include "GSHelpGame3.h"
#include "GSHelpGame4.h"
#include "ChooseGame.h"
#include "TeamAWin.h"
#include "TeamAWin1.h"
#include "TeamAWin2.h"
#include "TeamBWin.h"
#include "TeamAvTeamB.h"
#include "TeamAvTeamB1.h"
#include "DieGame3.h"
#include "WinGame3.h"


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
	case StateType::STATE_PLAY2:
		gs = std::make_shared<GSPlay2>();
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
	case StateType::STATE_HELPGAME3:
		gs = std::make_shared<GSHelpGame3>();
		break;
	case StateType::STATE_HELPGAME4:
		gs = std::make_shared<GSHelpGame4>();
		break;
	case StateType::STATE_CHOOSEGAME:
		gs = std::make_shared<ChooseGame>();
		break;
	case StateType::STATE_TEAMAWIN:
		gs = std::make_shared<TeamAWin>();
		break;
	case StateType::STATE_TEAMAWIN1:
		gs = std::make_shared<TeamAWin1>();
		break;
	case StateType::STATE_TEAMAWIN2:
		gs = std::make_shared<TeamAWin2>();
		break;
	case StateType::STATE_TEAMBWIN:
		gs = std::make_shared<TeamBWin>();
		break;
	case StateType::STATE_TEAMAVTEAMB:
		gs = std::make_shared<TeamAvTeamB>();
		break;
	case StateType::STATE_TEAMAVTEAMB1:
		gs = std::make_shared<TeamAvTeamB1>();
		break;
	case StateType::STATE_DIEGAME3:
		gs = std::make_shared<DieGame3>();
		break;
	case StateType::STATE_WINGAME3:
		gs = std::make_shared<WinGame3>();
		break;
	case StateType::STATE_PLAY4:
		gs = std::make_shared<GSPlay4>();
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