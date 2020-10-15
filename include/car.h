#pragma once
#include "abstract-transport.h"

class Car : public AbstractTransport
{
private:
	int carSpeed;
	int carVolume;
	double carPrice;
	int distance;

public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car() override;

	double sumCost(int, int) override;
	double sumTime(int) override;
	int getDistance() override;
};
