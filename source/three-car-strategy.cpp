#include "three-car-strategy.h"

ThreeCarStrategy::ThreeCarStrategy()
{
}

ThreeCarStrategy::~ThreeCarStrategy()
{
}

Track ThreeCarStrategy::GetBestTrack(int *path, int volume)
{
	Car car1 = Car();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[0]]))
		{
			car1 = Car(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
		}
	}

	Train train = Train();
	Plane plane = Plane();
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
		{
			train = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
		}
		if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
		{
			plane = Plane(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
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

	for (auto it = table.begin(); it != table.end(); it++)
	{
		if ((*it).first.find(points[path[3]]) && points[path[3]].find("AP"))
		{
			plane = Plane(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
		}
		if ((*it).first.find(points[path[3]]) && points[path[3]].find("TS"))
		{
			train = Train(tableCost[(*it).second * 3 + 1], matrixDist[path[3]][path[4]]);
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

	std::list<AbstractTransport> list = {};
	list.push_back(car1);
	list.push_back(car2);
	list.push_back(car3);
	list.push_back(train);
	list.push_back(plane);

	Track track = Track(list, volume);
	
	return track;
}