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
	virtual bool OnEnter(){ return true;};
	virtual bool OnLeave(){ return true;};
private:
	int m_iType;
};

#endif // __GAME_H__