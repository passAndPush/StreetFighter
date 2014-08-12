#include "SceneTouchLayer.h"
#include "CCEventListenerTouch.h"
USING_NS_CC;
bool CSceneInputLayer::init()
{
	Layer::init();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = CC_CALLBACK_2(CSceneInputLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(CSceneInputLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(CSceneInputLayer::onTouchEnded, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(CSceneInputLayer::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	return true;
}

bool CSceneInputLayer::onTouchBegan( Touch* touch, Event* event )
{
	_ClearRecords();
	m_bRecording = true;
	return true;
}

void CSceneInputLayer::onTouchEnded( Touch* touch, Event* event )
{
	//С��3��Ϊ��һ�δ�����ȡ���ĵ���Ϊ�����㣬��ֹ�ֶ�ר��
	if(m_iRecordCount < 3)
	{
		
	}
	_ClearRecords();
	m_bRecording = false;
}

void CSceneInputLayer::onTouchCancelled( Touch* touch, Event* event )
{
	m_bRecording = false;
	_ClearRecords();
}

void CSceneInputLayer::onTouchMoved( Touch* touch, Event* event )
{
	if(m_bRecording)
	{
		m_RecordPoints[m_iRecordCount] = touch->getLocation();
		m_iRecordCount ++;
	}
}

CSceneInputLayer::CSceneInputLayer()
{

}

void CSceneInputLayer::_ClearRecords()
{
	m_iRecordCount = 0;
	memset(m_RecordPoints,0,sizeof(Point)*MAXRECORDPOINT);
}