#ifndef __ACTOR_H__
#define __ACTOR_H__
#include "../BaseClass/Entity.h"
#include "cocostudio/CCArmature.h"
class cocostudio::Armature;
class cocos2d::Node;
class CActor:public CEntity
{    
public:
	CActor();
	virtual ~CActor();
	//create cocos resource
	virtual bool init();
	EntityType GetType() { return EntityType_Actor;}
	cocos2d::Node* GetRenderNode() { return m_pArmature;}
	virtual void SetGridPos(const EntityPos& pos);
	virtual void GotoPos(const EntityPos& pos);
protected:
	cocostudio::Armature* m_pArmature;
};

#endif // __ACTOR_H__
