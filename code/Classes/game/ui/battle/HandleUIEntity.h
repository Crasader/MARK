#pragma execution_character_set("utf-8")

#ifndef __UI_MAIN_BATTLE_HANDLE_ENTITY_H__
#define __UI_MAIN_BATTLE_HANDLE_ENTITY_H__

#include "cocos2d.h"
#include "ui/UILayout.h"
#include "common/basic/Observer.h"
#include "game/temp/Grid.h"
#include "game/temp/EntityTemp.h"

USING_NS_CC;
using namespace ui;
using namespace coreTemp;

class HandleUIEntity : public Ref, public Observer
{
public:
	CREATE_FUNC(HandleUIEntity);

public:
	HandleUIEntity();
	~HandleUIEntity();

	virtual bool init();

	void setSkin(Layout *skin);
	void resetSkin();

	virtual void updateBySubject(va_list values);
	void runEntityAppear();

private:
	void setTxtHpOrEnergy(EntityTemp *entity, const bool &isMst, const bool &isHp);

	void runEntityAction();
	
	void dealTurnOver();//轮结束处理

	void dealRoundOver(const bool &isForce = false);//回合结束处理
	/*刷新血量
	type 0hp1energy*/
	void updateTxtHpOrEnergy(const bool &isHp);
	
private:
	Layout *_skin;

};

#endif