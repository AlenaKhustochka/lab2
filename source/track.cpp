#include"track.h"

Track::Track()
{
	this->cost = 0;
	this->time = 0;
	this->volume = 0;
}

Track::~Track()
{

}

Track::Track(std::list<AbstractTransport> list, int volume)
{
	cost = 0;
	time = 0;

	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		cost += iter->getConst(volume);
		time += iter->getTime();
	}
}

double Track::getCost()
{
	return this->cost;
}