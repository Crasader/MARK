#ifndef __GAME_MANAGER_HANDLE_H__
#define __GAME_MANAGER_HANDLE_H__

#include "cocos2d.h"
#include "common/observer/Observer.h"

class ManagerHandle : public Subject
{
public:
	static ManagerHandle* getInstance();

	~ManagerHandle();

private:
	ManagerHandle();
	ManagerHandle(const ManagerHandle&);
	ManagerHandle& operator=(const ManagerHandle&);

	static ManagerHandle* _instance;
	
};

#endif