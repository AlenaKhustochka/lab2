#include "many-transport-strategy.h"

ManyTransportStrategy::ManyTransportStrategy()
{
}

ManyTransportStrategy::~ManyTransportStrategy()
{
}

Track ManyTransportStrategy::GetBestTrack(int *path, int volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
		}
	}

	Train train1 = Train();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[1]]))
		{
			train1 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
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

	Plane plane = Plane();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[3]]))
		{
			plane = Plane(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
		}
	}

	Car car3 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[4]]))
		{
			car3 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
		}
	}

	Train train2 = Train();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[5]]))
		{
			train2 = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[5]][path[6]]);
		}
	}

	Car car4 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[6]]))
		{
			car4 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[6]][path[7]]);
		}
	}

	std::list<AbstractTransport> list = {};
	list.push_back(car1);
	list.push_back(car2);
	list.push_back(car3);
	list.push_back(car4);
	list.push_back(train1);
	list.push_back(train2);
	list.push_back(plane);

	Track track = Track(list, volume);

	return track;
}