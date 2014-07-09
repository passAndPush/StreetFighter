/*����ļ��Ƕ�����cocos�߼���һ����Ϸģ�飬����
��game play ��ص��߼����������ڲ�����ʵ��*/
#ifndef __GAME_STATE_BASE_H__
#define __GAME_STATE_BASE_H__
#include "CCRef.h"
class CGameStateBase:public cocos2d::Ref
{    
public:
	CGameStateBase ();
	virtual ~CGameStateBase(){}
	int GetType() {return m_iType;}
	virtual bool OnEnterState(){ return true;};
	virtual bool OnLeaveState(){ return true;};
	virtual void OnLoadingComplete(){}
protected:
	int m_iType;
};

#endif // __GAME_H__