#ifndef __CORE_ACROSS_I_ACROSS_OBJECT_H__
#define __CORE_ACROSS_I_ACROSS_OBJECT_H__

#include "cocos2d.h"

class IAcrossObject
{
public:
	virtual IAcrossObject* getUpObject() { return nullptr; }
	virtual void setUpObject(IAcrossObject* var) {}

	virtual IAcrossObject* getDownObject() { return nullptr; }
	virtual void setDownObject(IAcrossObject* var) {}

	virtual IAcrossObject* getLeftObject() { return nullptr; }
	virtual void setLeftObject(IAcrossObject* var) {}

	virtual IAcrossObject* getRightObject() { return nullptr; }
	virtual void setRightObject(IAcrossObject* var) {}

};

#endif
