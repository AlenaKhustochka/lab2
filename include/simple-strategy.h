#pragma once
#include "istrategy.h"

class SimpleStrategy : public IStrategy
{
public:
	SimpleStrategy();
	~SimpleStrategy() override;
	Track GetBestTrack(int *path, int volume) override;
};