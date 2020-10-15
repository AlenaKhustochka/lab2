#pragma once
#include <string>
#include "track.h"

enum Type { Turbo, Standart, Economy };

class Order {
private:
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;

	int** initMatrix(const int size);
	int* initPathArray(const int size);
	int getCountTransport(int *path, int size);

public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};