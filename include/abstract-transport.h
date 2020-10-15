#pragma once
#include <tuple>

/*
 * паттрн абстрактная фабрика
 */
class AbstractTransport {
public:
	virtual ~AbstractTransport() {};

	virtual double sumCost(int, int) { return 0; };
	virtual double sumTime(int) { return 0; };
	virtual int getDistance() { return 0; };

	double getConst(int volume)
	{
		return sumCost(volume, getDistance());
	};

	double getTime()
	{
		return sumTime(getDistance());
	};
};
