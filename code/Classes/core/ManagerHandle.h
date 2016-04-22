#ifndef __CORE_MANAGER_HANDLE_H__
#define __CORE_MANAGER_HANDLE_H__

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