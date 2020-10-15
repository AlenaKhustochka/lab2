#pragma once
#include "istrategy.h"

class ManyTransportStrategy : public IStrategy
{
public:
	ManyTransportStrategy();
	~ManyTransportStrategy() override;
	Track GetBestTrack(int *path, int volume) override;
};