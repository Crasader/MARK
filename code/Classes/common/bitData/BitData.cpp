#include "BitData.h"

BitData::BitData() : _totalBit(0)
{
}

BitData::~BitData()
{
	_totalBit = 0;
	_vecData.clear();
}

bool BitData::init()
{
	auto isInit = false;

	do
	{
		isInit = true;
	} while (0);

	return isInit;
}

bool BitData::getBit(int bit)
{
	setTotalBit(bit);

	auto lengthIntBit = sizeof(int) * 8;
	auto indexVecData = bit / lengthIntBit;
	return (_vecData[indexVecData] & (1 << (bit % lengthIntBit))) != 0;
}

void BitData::setBit(int bit)
{
	setTotalBit(bit);

	auto lengthIntBit = sizeof(int) * 8;
	auto indexVecData = bit / lengthIntBit;
	_vecData[indexVecData] |= (1 << (bit % lengthIntBit));
}

int BitData::getTotalBit()
{
	return _totalBit;
}

void BitData::setTotalBit(int bit)
{
	if (_totalBit < bit + 1)
	{
		_totalBit = bit + 1;
	}

	auto lengthIntBit = sizeof(int) * 8;
	auto indexVecData = bit / lengthIntBit;
	if ((int)_vecData.size() <= indexVecData)
	{
		_vecData.resize(indexVecData + 1);
	}
}

bool BitData::isAllBitTrue()
{
	auto bit = 0;
	auto lengthIntBit = sizeof(int) * 8;
	do
	{
		auto indexVecData = bit / lengthIntBit;
		auto isBitFlase = (_vecData[indexVecData] & (1 << (bit % lengthIntBit))) == 0;
		if (isBitFlase)
		{
			return false;
		}
	} while (++bit < _totalBit);
	return true;
}
