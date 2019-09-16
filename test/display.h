#pragma once
#define DISPLAY_H
#include "character.h"
#include "Consola.h"
#include "map.h"
#include "Car.h"
#include <iostream>
#include <cstdlib> //랜덤함수
#include <ctime>

using namespace std;

class Display
{
private:
	Character *myC;
public:
	Display(Character *c);
	~Display(){};
	friend class Control;
	void ReturnC(int x, int y);
	void ShowC(int x,int y);
	void xyprint(int x,int y, char *ch);
	void ShowMap(int stage);
	void GetMap(int stage);
	void ShowScore(int *score);
	void ShowStage(int stage);
	void ShowTime(int *time);
	void ShowReset();
	void ShowExit();
	void Interface(int *score,int stage,int *time);
	void Startmain();
	void help();
	void reset();
	void FindCar(int *stage);
	void Draw(int state);
	Map _mymap;
	void ShowCar(int x,int y);
	void PrintSquare();
	void PrintMessage();
	void GameOver(); //게임오버 함수
	void ClearStage(int score, int stage);
	void Ending(int score);

	void main_sound();
	void stage_sound(int stage);
	void clear_sound();
	void stop_sound();
};