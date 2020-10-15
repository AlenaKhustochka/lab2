#pragma once
#include "abstract-transport.h"

class Train : public AbstractTransport
{
	int trainSpeed;
	int trainVolume;
	double trainPrice;
	int distance;

public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train() override;

	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};