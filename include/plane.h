#pragma once
#include "abstract-transport.h"

class Plane : public AbstractTransport
{
	int planeSpeed;
	int planeVolume;
	double planePrice;
	int distance;
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane() override;

	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};