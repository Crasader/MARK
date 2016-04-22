#ifndef __COMMON_BIT_DATA_BIT_DATA_H__
#define __COMMON_BIT_DATA_BIT_DATA_H__

#include "cocos2d.h"
#include <vector>

/************************************************************************/
/*位数据类                                                              */
/*按位保存 0 1 数据                                                     */
/************************************************************************/
class BitData : public cocos2d::Ref
{
public:
	CREATE_FUNC(BitData);

	BitData();
	~BitData();

	virtual bool init();

	bool getBit(int bit);
	void setBit(int bit);

	int getTotalBit();
	void setTotalBit(int bit);
	bool isAllBitTrue();

private:
	std::vector<int> _vecData;
	int _totalBit;
};

#endif