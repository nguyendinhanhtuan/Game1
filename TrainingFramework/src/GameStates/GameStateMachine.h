#pragma once
#include "GameManager/Singleton.h"
#include "GameConfig.h"
#include <list>

class GameStateBase;

enum class StateType
{
	STATE_INVALID = 0,
	STATE_INTRO,	
	STATE_MENU,
	STATE_CHOOSEGAME,
	STATE_HELP, 
	STATE_PrepareToPlay,	
	STATE_PLAY,	
	STATE_DIE, 
	STATE_WIN,
	STATE_HELPGAME2,		
	STATE_PLAY1,
	STATE_HELPGAME3,	
	STATE_PLAY2,		
	STATE_HELPGAME4,
	STATE_PLAY4,
	STATE_TEAMAWIN,
	STATE_TEAMAWIN1,
	STATE_TEAMAWIN2,
	STATE_TEAMBWIN,
	STATE_TEAMAVTEAMB,
	STATE_TEAMAVTEAMB1,
	STATE_DIEGAME3,
	STATE_WINGAME3,

};

class GameStateMachine : public CSingleton<GameStateMachine>
{
public:
	GameStateMachine();
	~GameStateMachine();

	void	Cleanup();

	void	ChangeState(std::shared_ptr<GameStateBase> state);
	void	ChangeState1(StateType state);
	void	ChangeState(StateType stt);
	void	PushState(StateType stt);
	void	PopState();

	bool	isRunning() { return m_running; }
	void	Quit() { m_running = false; }
	void	PerformStateChange();

	inline std::shared_ptr<GameStateBase> CurrentState()const
	{
		return m_pActiveState;
	}

	inline bool NeedsToChangeState()const
	{
		return (m_pNextState != 0);
	}

	inline bool HasState()const
	{
		return m_StateStack.size() > 0;
	}

private:
	std::list < std::shared_ptr<GameStateBase>>	m_StateStack;
	std::shared_ptr<GameStateBase>				m_pActiveState;
	std::shared_ptr<GameStateBase>				m_pNextState;
	bool	m_running;
	bool	m_fullscreen;
};

