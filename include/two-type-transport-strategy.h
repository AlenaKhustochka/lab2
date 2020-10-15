#pragma once
#include "istrategy.h"

class TwoTypeTransportStrategy : public IStrategy
{
public:
	TwoTypeTransportStrategy();
	~TwoTypeTransportStrategy() override;
	Track GetBestTrack(int *path, int volume) override;
};