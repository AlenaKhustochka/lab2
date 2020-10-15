#include "two-type-transport-strategy.h"

TwoTypeTransportStrategy::TwoTypeTransportStrategy()
{
}

TwoTypeTransportStrategy::~TwoTypeTransportStrategy()
{
}

Track TwoTypeTransportStrategy::GetBestTrack(int *path, int volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
		}
	}

	Car car2 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[2]]))
		{
			car2 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
		}
	}

	Train train = Train();
	Plane plane = Plane();
	Track track = Track();

	std::list<AbstractTransport> list = {};
	list.push_back(car1);
	list.push_back(car2);

	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
		{
			train = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			list.push_back(train);
		}

		if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
		{
			plane = Plane(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
			list.push_back(plane);
		}
	}

	track = Track(list, volume);

	return track;
}