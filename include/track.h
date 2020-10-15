#pragma once
#include <list>
#include "car.h"
#include "train.h"
#include "plane.h"

class Track {
	double cost;
	double time;
	int volume;
public:
	Track();
	Track(std::list<AbstractTransport>, int);
	double getCost();
	~Track();
};