#include "Maid.h"
#include "cocostudio/CocoStudio.h"
#include "model/define/DefinesString.h"
#include "../ManagerHandle.h"
#include "ManagerEntity.h"

using namespace coreTemp;

Maid::Maid()
{
}

Maid::~Maid()
{
}

bool Maid::init()
{
	auto isInit = false;
	do 
	{
		CC_BREAK_IF(!EntityTemp::init());

		
		isInit = true;
	} while (0);
	return isInit;
}

void Maid::setDataEntity()
{
	_dataEntity = ManagerData::getInstance()->getHandleDataEntity()->getDataEntityMaid();
}

void Maid::setMyScale()
{
	_skin->setScaleX(0.7f);
	_skin->setScaleY(0.7f);
}

cocos2d::Vec2 Maid::getPostionAppearDisAppear()
{
	auto size = _skin->getContentSize();
	return Vec2(size.width, -size.height);
}

cocos2d::Vec2 Maid::getPostionEndAttack()
{
	auto size = _skin->getContentSize();
	return Vec2(-size.width * 2.0f, 0.0f);
}

void Maid::updateHp()
{
	/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_HEAD, TYPE_OBSERVER_HANDLE_HEAD::UPDATE_HP, false);//����ˢ��*/
}

void Maid::updateHpAll()
{
	/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_HEAD, TYPE_OBSERVER_HANDLE_HEAD::UPDATE_HP_ALL, false);//����ˢ��*/
}

void Maid::updateEnergy()
{
	/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_HEAD, TYPE_OBSERVER_HANDLE_HEAD::UPDATE_ENERGY, false);//����ˢ��*/
}

void Maid::dealDead()
{
	auto dataEntityMst = ManagerData::getInstance()->getHandleDataEntity()->getDataEntityMst();
	dataEntityMst->addAttribute(IdAttribute::ENTITY_KILL_NUM, 1);
	auto handleDataEntity = ManagerData::getInstance()->getHandleDataEntity();
	auto isBattleOver = handleDataEntity->isBattleOver();
	if (!isBattleOver)
	{
		/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::HANDLE_HEAD, TYPE_OBSERVER_HANDLE_HEAD::SWITCH_NODE_HEAD_TO, false, ENTITY_BATTLE_MAX);//���������ǹ���л���һ��*/
	}
	else
	{
		ManagerEntity::getInstance()->dealBattleOver();
	}
}

void Maid::switchDataEntity(const int &indexSwitchTo, bool &isSwitchSuccess)
{
	if (indexSwitchTo < 0 || indexSwitchTo > ENTITY_BATTLE_MAX)
	{
		return;
	}
	auto handleDataEntity = ManagerData::getInstance()->getHandleDataEntity();
	if (indexSwitchTo == ENTITY_BATTLE_MAX)//�л�����һ��
	{
		auto vecDataEntity = handleDataEntity->getVecDataEntityMaid();
		for (auto i = 0; i < ENTITY_BATTLE_MAX; i++)
		{
			auto index = handleDataEntity->getIndexMaid();
			auto indexTo = (index + i + 1) % ENTITY_BATTLE_MAX;
			if (vecDataEntity.at(indexTo)->getIsAlive())
			{
				handleDataEntity->setIndexMaid(indexTo);
				isSwitchSuccess = true;
				break;
			}
		}
	}
	else
	{
		auto vecDataEntityMaid = handleDataEntity->getVecDataEntityMaid();
		if (vecDataEntityMaid.size() <= indexSwitchTo)
		{
			return;
		}
		auto isAlive = vecDataEntityMaid.at(indexSwitchTo)->getIsAlive();
		if (!isAlive)
		{
			return;
		}
		handleDataEntity->setIndexMaid(indexSwitchTo);
		isSwitchSuccess = true;
	}
}

Vector<DataEntity *> Maid::getVecDataEntity()
{
	auto handleDataEntity = ManagerData::getInstance()->getHandleDataEntity();
	auto vecDataEntityMaid = handleDataEntity->getVecDataEntityMaid();
	return vecDataEntityMaid;
}