#include "ManagerEntity.h"
#include "common/util/UtilRandom.h"
#include "../ManagerHandle.h"

using namespace coreTemp;

static ManagerEntity *_instance = nullptr;

ManagerEntity * ManagerEntity::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ManagerEntity();
	}
	return _instance;
}

void ManagerEntity::destroyInstance()
{
	CC_SAFE_DELETE(_instance);
}

ManagerEntity::ManagerEntity() : _monster(nullptr), _maid(nullptr), _sceneryMst(nullptr), _sceneryMaid(nullptr)
{
}

ManagerEntity::~ManagerEntity()
{
	_monster = nullptr;
	_maid = nullptr;
	_sceneryMst = nullptr;
	_sceneryMaid = nullptr;
}

void ManagerEntity::stopAllActions()
{
	_monster->stopSkinAllActions();
	_maid->stopSkinAllActions();
}

bool ManagerEntity::isRunAppearOverAll()
{
	return _monster->getIsRunAppearOver() && _maid->getIsRunAppearOver();
}

bool ManagerEntity::isDoActoinOverAll()
{
	return _monster->getIsDoActionOver() && _maid->getIsDoActionOver();
}

bool ManagerEntity::isTurnOverAll()//�ж�����ȫ���������
{
	return _monster->getIsTurnOver() && _maid->getIsTurnOver();
}

void ManagerEntity::dealBattleOver()
{
	stopAllActions();
	
	auto managerData = ManagerData::getInstance();

	auto handleDataEntity = managerData->getHandleDataEntity();
	handleDataEntity->resetDataEntityAttributeTempTurnOver();
	handleDataEntity->resetDataEntityAttributeTempRoundOver();

	auto isBattleWin = handleDataEntity->isBattleWin();

	auto handleDataLevels = managerData->getHandleDataLevels();
	auto dataLevelCurrent = handleDataLevels->getDataLevelCurrent();
	if (isBattleWin)//ս��ʤ��
	{
		dataLevelCurrent->dealLevelTarget();
		dataLevelCurrent->dealLevelPassed();//����ͨ��
	}
	else
	{
		dataLevelCurrent->setVecTargetComplete();
	}

	auto isAnyMstCanCatch = handleDataEntity->getIsAnyMstCanCatch();
	if (isAnyMstCanCatch)//���п��Բ�׽�Ĺ���
	{
		/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::SHOW_LAYER_CATCH);*/
	}
	else
	{
		/*ManagerHandle::getInstance()->notify((int)ID_OBSERVER::LAYER_BATTLE, TYPE_OBSERVER_LAYER_BATTLE::SHOW_LAYER_BATTLE_RESULT);*/
	}
}

void ManagerEntity::runSceneryEffect(const bool &isMst)
{
	auto scenery = isMst ? _sceneryMst : _sceneryMaid;
	scenery->runEffect();
}

void ManagerEntity::stopSceneryEffect(const bool &isMst)
{
	auto scenery = isMst ? _sceneryMst : _sceneryMaid;
	scenery->stopEffect();
}