#pragma once
#include "istrategy.h"

class ThreeCarStrategy : public IStrategy
{
public:
	ThreeCarStrategy();
	~ThreeCarStrategy() override;
	Track GetBestTrack(int *path, int volume) override;
};