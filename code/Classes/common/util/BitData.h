#ifndef __BIT_DATA_H__
#define __BIT_DATA_H__

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

	CC_SYNTHESIZE(int, _totalBit, TotalBit);
	void modifyTotalBit(int bit);
	bool isAllBitTrue();

private:
	std::vector<int> _vecData;

};

#endif