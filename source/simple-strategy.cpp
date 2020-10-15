#include"simple-strategy.h"

SimpleStrategy::SimpleStrategy()
{
}

SimpleStrategy::~SimpleStrategy()
{
}

Track SimpleStrategy::GetBestTrack(int *path, int volume)
{
	Car car = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[0]]))
		{
			car = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
		}
	}

	std::list<AbstractTransport> list = {};
	list.push_back(car);

	Track track = Track(list, volume);
	return track;
}