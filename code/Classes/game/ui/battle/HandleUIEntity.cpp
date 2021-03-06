#pragma execution_character_set("utf-8")

#include "HandleUIEntity.h"
#include "defines/DefinesValue.h"
#include "game/temp/Grid.h"
#include "game/temp/ManagerGrid.h"
#include "game/temp/EntityTemp.h"
#include "game/temp/Maid.h"
#include "game/temp/Monster.h"
#include "game/temp/ManagerEntity.h"
#include "defines/DefinesRes.h"
#include "game/ManagerHandle.h"

HandleUIEntity::HandleUIEntity() : _skin(nullptr)
{
}

HandleUIEntity::~HandleUIEntity()
{
	ManagerHandle::getInstance()->detach(this);
	_skin = nullptr;
}

bool HandleUIEntity::init()
{
	auto isInit = false;
	do 
	{
		/*idObserverSet((int)ID_OBSERVER::HANDLE_ENTITY);*/
		ManagerHandle::getInstance()->attach(this);

		isInit = true;
	} while (0);
	return isInit;
}

void HandleUIEntity::setSkin(Layout *skin)
{
	_skin = skin;

	auto managerEntity = ManagerEntity::getInstance();

	for (int i = 0; i < 2; i++)
	{
		auto isMst = i < 1;
		auto layout = (Layout *)_skin->getChildByName(isMst ? "layoutMst" : "layoutMaid");
		//
		auto scenery = Scenery::create();
		scenery->setName("scenery");
		scenery->updateSkin(isMst);
		layout->addChild(scenery);
		isMst ? managerEntity->setSceneryMst(scenery) : managerEntity->setSceneryMaid(scenery);
		//
		auto entity = isMst ? (EntityTemp *)Monster::create() : (EntityTemp *)Maid::create();
		entity->setName("entity");
		entity->setVisible(false);
		layout->addChild(entity);
		isMst ? managerEntity->setMonster((Monster *)entity) : managerEntity->setMaid((Maid *)entity);
		//
		/*setTxtHpOrEnergy(entity, isMst, true);
		setTxtHpOrEnergy(entity, isMst, false);*/
	}
}

void HandleUIEntity::resetSkin()
{
	for (int i = 0; i < 2; i++)
	{
		/*auto managerEntity = ManagerEntity::getInstance();
		auto entity = isMst ? (Entity *)managerEntity->getMonster() : (Entity *)managerEntity->getMaid();
		entity->setVisible(false);*/
	}
}

void HandleUIEntity::updateBySubject(va_list values)
{
	auto type = va_arg(values, TYPE_OBSERVER_HANDLE_ENTITY);
	if (type == TYPE_OBSERVER_HANDLE_ENTITY::RUN_ENTITY_APPEAR)
	{
		runEntityAppear();
	}
	else if (type == TYPE_OBSERVER_HANDLE_ENTITY::RUN_ENTITY_ACTION)
	{
		runEntityAction();
	}
	else if (type == TYPE_OBSERVER_HANDLE_ENTITY::DEAL_ROUND_OVER)
	{
		auto isForce = va_arg(values, bool);
		dealRoundOver(isForce);
	}
	else if (type == TYPE_OBSERVER_HANDLE_ENTITY::UPDATE_HP)
	{
		/*updateTxtHpOrEnergy(true);*/
	}
	else if (type == TYPE_OBSERVER_HANDLE_ENTITY::UPDATE_ENERGY)
	{
		/*updateTxtHpOrEnergy(false);*/
	}
}

void HandleUIEntity::runEntityAppear()
{
	for (int i = 0; i < 2; i++)
	{
		auto isMst = i < 1;
		auto managerEntity = ManagerEntity::getInstance();
		auto entity = isMst ? (EntityTemp *)managerEntity->getMonster() : (EntityTemp *)managerEntity->getMaid();
		entity->runAppear([entity]()
		{
			auto isAppearAll = ManagerEntity::getInstance()->isRunAppearOverAll();
			if (isAppearAll)
			{
				/*auto anchor = Vec2::ANCHOR_BOTTOM_RIGHT;
				auto postion = entity->getParent()->convertToWorldSpace(entity->getPosition() + Vec2(0.0f, 200.0f));
				ManagerUI::getInstance()->showPlot(entity, anchor, postion, 1000, 0, nullptr, []()
				{
					ManagerUI::getInstance()->notify(ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::SHOW_APPEAR_GRID_SELECTED_MST);
				});//for test*/
				/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::SHOW_APPEAR_GRID_SELECTED_MST);*/
			}
		});
	}
}

void HandleUIEntity::setTxtHpOrEnergy(EntityTemp *entity, const bool &isMst, const bool &isHp)
{
	IdAttribute idAttribute;
	string name = "";
	if (isHp)
	{
		idAttribute = IdAttribute::ENTITY_HP;
		name = "txtHp";
	}
	else
	{
		idAttribute = IdAttribute::ENTITY_ENERGY;
		name = "txtEnergy";
	}
	auto value = entity->getDataEntity()->getAttribute(idAttribute);
	auto text = isMst ? Value(value).asString() + "X" : "X" + Value(value).asString();
	auto txt = (Text *)_skin->getChildByName(isMst ? "layoutMstBar" : "layoutMaidBar")->getChildByName(name);
	txt->setString(text);
}

void HandleUIEntity::runEntityAction()
{
	auto managerEntity = ManagerEntity::getInstance();
	auto monster = managerEntity->getMonster();
	auto maid = managerEntity->getMaid();
	monster->setIsTurnOver(false);
	maid->setIsTurnOver(false);
	auto quickMst = monster->getDataEntity()->getAttribute(IdAttribute::ENTITY_QUICK);
	auto quickMaid = maid->getDataEntity()->getAttribute(IdAttribute::ENTITY_QUICK);
	auto quickMstOnly = quickMst != 0 && quickMaid == 0;
	auto quickMaidOnly = quickMst == 0 && quickMaid != 0;
	if (quickMstOnly || quickMaidOnly)//若仅怪物快速攻击或仅女仆快速攻击
	{
		auto entityQuick = quickMstOnly ? (EntityTemp *)monster : (EntityTemp *)maid;
		auto entityThen = quickMstOnly ? (EntityTemp *)maid : (EntityTemp *)monster;
		entityQuick->doAction([entityQuick, entityThen, this]()//先攻实体动作
		{
			entityThen->showEffect([entityQuick, entityThen, this]()//后续实体结果
			{
				entityThen->doAction([entityQuick, this]()//后续实体动作
				{
					entityQuick->showEffect([this]()//先攻实体结果
					{
						dealTurnOver();
					});
				});
			});
		});
	}
	else
	{
		for (auto i = 0; i < 2; i++)
		{
			auto isMst = i < 1;
			auto entityDoAction = isMst ? (EntityTemp *)monster : (EntityTemp *)maid;
			entityDoAction->doAction([this]()//动作
			{
				auto managerEntity = ManagerEntity::getInstance();
				auto isDoActoinOverAll = managerEntity->isDoActoinOverAll();
				if (isDoActoinOverAll)
				{
					for (auto i = 0; i < 2; i++)
					{
						auto isMst = i < 1;
						auto entityShowEffect = isMst ? (EntityTemp *)managerEntity->getMonster() : (EntityTemp *)managerEntity->getMaid();
						entityShowEffect->showEffect([this]()//结果
						{
							dealTurnOver();
						});
					}
				}
			});
		}
	}
}

void HandleUIEntity::dealTurnOver()
{
	auto isTurnAll = ManagerEntity::getInstance()->isTurnOverAll();//一轮行动的动作全部结束
	if (isTurnAll)
	{
		auto handleDataEntity = ManagerData::getInstance()->getHandleDataEntity();
		handleDataEntity->resetDataEntityAttributeTempTurnOver();
		handleDataEntity->dealVecSkillActiveInUse2UseOverMaid();
		auto isRoundOver = ManagerData::getInstance()->getHandleDataGrid()->isRoundOver();
		if (!isRoundOver)
		{
			/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_GRID, TYPE_OBSERVER_HANDLE_GRID::RUN_GRID_MOVE_AND_THROW);*/
		}
		else//若回合结束
		{
			auto indexTo = 0;
			auto isSkillNeedSwitchEntity = handleDataEntity->getIsSkillNeedSwitchMst(indexTo);
			if (isSkillNeedSwitchEntity)
			{
				/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_HEAD, TYPE_OBSERVER_HANDLE_HEAD::SWITCH_NODE_HEAD_TO, true, indexTo);//参数：是怪物，切换目标*/
			}
			else
			{
				dealRoundOver();
			}
		}
	}
}

void HandleUIEntity::dealRoundOver(const bool &isForce /*= false*/)
{
	auto handleDataGrid = ManagerData::getInstance()->getHandleDataGrid();
	handleDataGrid->resetIndexGridBattle();
	
	auto handleDataEntity = ManagerData::getInstance()->getHandleDataEntity();
	handleDataEntity->resetDataEntityAttributeTempRoundOver();
	handleDataEntity->addRound();
	handleDataEntity->dealDataEntitySkillSort(isForce);

	auto handleDataLevels = ManagerData::getInstance()->getHandleDataLevels();
	handleDataLevels->getDataLevelCurrent()->dealLevelTarget();

	auto isRoundLimitOver = handleDataEntity->isRoundLimitOver();
	if (isRoundLimitOver)
	{
		ManagerEntity::getInstance()->dealBattleOver();
	}
	else
	{
		auto managerUI = ManagerHandle::getInstance();
		/*managerUI->notify((int)ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::RESET_SKIN);
		managerUI->notify((int)ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::SHOW_APPEAR_GRID_SELECTED_MST);*/
	}
}

void HandleUIEntity::updateTxtHpOrEnergy(const bool &isHp)
{
	IdAttribute idAttribute;
	string name = "";
	if (isHp)
	{
		idAttribute = IdAttribute::ENTITY_HP;
		name = "txtHp";
	}
	else
	{
		idAttribute = IdAttribute::ENTITY_ENERGY;
		name = "txtEnergy";
	}
	for (int i = 0; i < 2; i++)
	{
		auto isMst = i < 1;
		auto managerEntity = ManagerEntity::getInstance();
		auto entity = isMst ? (EntityTemp *)managerEntity->getMonster() : (EntityTemp *)managerEntity->getMaid();
		auto value = entity->getDataEntity()->getAttribute(idAttribute);
		auto text = isMst ? Value(value).asString() + "X" : "X" + Value(value).asString();
		auto txt = (Text *)_skin->getChildByName(isMst ? "layoutMstBar" : "layoutMaidBar")->getChildByName(name);
		txt->setString(text);
	}
}
