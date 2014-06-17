#include "Game.h"
#include "GameStateManager.h"
#include "GameStateCombat/GameStateCombat.h"
#include "GameStateBegin/GameStateBegin.h"
#include "Common/CommonDef.h"
CGame* CGame::pStaticGame = nullptr;
CGame* CGame::GetInstance()
{
	if(!pStaticGame)
	{
		pStaticGame = new CGame();
		pStaticGame->Init();
	}
	return pStaticGame;
}

bool CGame::Init()
{
	m_pGameStateManager = CGameStateManager::Create();
	if(m_pGameStateManager)
	{
		m_pGameStateManager->RegisterGameState(GameStateType_Begin,CGameStateBegin::create());
		m_pGameStateManager->RegisterGameState(GameStateType_Combat,CGameStateCombat::create());
		return true;
	}
	return false;
}

CGameStateBase* CGame::GetGameState( int gameState )
{
	return m_pGameStateManager->GetGameState(gameState);
}
