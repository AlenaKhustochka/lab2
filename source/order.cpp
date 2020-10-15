#include <map>
#include "many-transport-strategy.h"
#include "three-car-strategy.h"
#include "two-type-transport-strategy.h"
#include"simple-strategy.h"
#include "order.h"

Order::Order()
{
	this->cost = 0;
	this->volume = 0;
	this->startPoint = "";
	this->finishPoint = "";
	this->track = Track();
	this->type = Type::Economy;
}

Order::Order(Type deliv, std::string startP, std::string finishP, int vol)
{
	this->startPoint = startP;
	this->finishPoint = finishP;
	this->type = deliv;
	this->track = best(startP, finishP, deliv, vol);
	this->cost = track.getCost();
	this->volume = vol;
}

Order::~Order()
{

}

int** Order::initMatrix(const int size)
{
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

int* Order::initPathArray(const int size)
{
	int* path = new int[size];
	for (int i = 0; i < size; i++)
	{
		path[i] = -1;
	}
	return path;
}

int Order::getCountTransport(int *path, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (path[i] != -1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

Track Order::best(std::string startP, std::string finishP, Type deliv, int volume)
{
	int start = decr(startP);
	int finish = decr(finishP);

	int** mat = initMatrix(SIZE);
	mat = matrixUpd(deliv);

	int* path = initPathArray(SIZE);
	path = optim(mat, start, finish);

	int count = getCountTransport(path, SIZE);

	switch (count)
	{
		case 1:
		{
			return SimpleStrategy().GetBestTrack(path, volume);
		}
		case 3:
		{
			return TwoTypeTransportStrategy().GetBestTrack(path, volume);
		}
		case 5:
		{
			return ThreeCarStrategy().GetBestTrack(path, volume);
		}
		case 7:
		{
			return ManyTransportStrategy().GetBestTrack(path, volume);
		}
		default:
		{
			return IStrategy().GetBestTrack(path, volume);
		}
	}
}

int** Order::matrixUpd(Type type)
{
	int** matrix = new int*[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i] = new int[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = matrixDist[i][j];
		}
	}
	switch (type)
	{
	case Economy:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("TS"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Standart:
		for (int i = 0; i < SIZE; i++)
		{
			if (points[i].find("AP"))
				for (int j = 0; j < SIZE; j++)
					matrix[i][j] = 99999;
		}
	case Turbo:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				if (matrix[i][j] == 0)
					matrix[i][j] = 99999;
		}
	}
	return matrix;
}

int* Order::optim(int** arr, int beginPoint, int endPoint)
{
	int* d = new int[SIZE];
	int* v = new int[SIZE];
	int temp, minindex, min;
	int begin_index = beginPoint;

	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 99999;
		v[i] = 1;
	}
	d[begin_index] = 0;

	do {
		minindex = 99999;
		min = 99999;
		for (int i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{
				min = d[i];
				minindex = i;
			}
		}

		if (minindex != 99999)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (arr[minindex][i] > 0)
				{
					temp = min + arr[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 99999);

	int* ver = new int[SIZE];
	int end = endPoint;
	ver[0] = end;
	int k = 1;
	int weight = d[end];

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++)
			if (arr[end][i] != 0)
			{
				int temp = weight - arr[end][i];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
	}
	for (int i = 0; i < k / 2; i++)
		std::swap(ver[i], ver[k - 1 - i]);
	delete[] d, v;
	return ver;
}

int Order::decr(std::string str)
{
	for (auto it = towns.begin(); it != towns.end(); it++)
	{
		if (str._Equal((*it).first))
			return (*it).second;
	}
	return -1;
}