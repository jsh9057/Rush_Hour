#pragma once
#define MAP_H
#include <iostream>
using namespace std;

class Map{
public:
	Map(){};
	~Map(){};
	friend class Car;
	void LoadM(int stage);
	int MapShap[3][8][12];
	
};
