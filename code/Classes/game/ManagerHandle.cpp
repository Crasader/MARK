#include "ManagerHandle.h"

ManagerHandle* ManagerHandle::_instance = new ManagerHandle();

ManagerHandle* ManagerHandle::getInstance()
{
	return _instance;
}

ManagerHandle::~ManagerHandle()
{
}

ManagerHandle::ManagerHandle()
{
}

ManagerHandle::ManagerHandle(const ManagerHandle&)
{

}

ManagerHandle& ManagerHandle::operator=(const ManagerHandle&)
{
	return *_instance;
}
