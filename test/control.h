#pragma once
#define CONTROL_H
#include "display.h"
#include <conio.h>

class Control{
public:
	Control(Character *C, Display *D);
	~Control(){};
	void delectCar(int x,int y);
	void MoveFunc ();
	void SetMCXY();
	void MoveMCXY(int x, int y);
	void delectC(int x, int y);
	void Map();
	void Interface(int *time);
	void Start_Main(); //게임시작
    void CreateCar();
	void FindCar(Car *_mycar);
	void ChangeC(int x,int y);
	void StartGame(); //PrintStart와 StartStage를 합친 함수
	void PrintCar(Car *_mycar);
	int BoardCar();
	void PrintStart(); //스테이지 출력화면
	void StartStage();
	void MoveCar(Car _mycar);
	void CarColor(Car _mycar);
	void ChangeMap(Car _mycar);
	void DelectMap(int x, int y);
	void OutCar(Car *_mycar);
	void AddMap(Car _mycar);
	void seemap(); //잘 변경되나 확인할라고 만듬
	void ClearMXY(); //무브펑션 마지막에 밑에 M_X,M_Y 변수 초기화 시켜주는 함수
	void AddMXY(int x, int y); //이건 무브카 움직이면서 저 ㅈ같은 변수 두개 1씩 더해주고 뺴주는거
	void SetMC(int x); //M_C 저거 차 지정해주는거
	void SetCarXY(); //위에 클리어랑 셋 합쳐준거 쉬발 코드 존나 더러워졌다 짜증난다 승현아ㅠㅠ
	void PrintOut(Car _mycar); //OutCar에서 나가고싶은 방향 표시
	void DelectOutMark(Car _mycar); //표시했던거 다시 지워줌
	void ResetScore();
	void MinusScore();
	void GameOver();
	void ClearStage();
private:
	Character *_C;
	Display *_D;
	Car _mycar[7]; //최대 차 갯수
	int MCX; //맵의 배열상 X좌표
	int MCY; //맵의 배열상 Y좌표
	int M_X; //맵상빠져나와도 mycar의 X좌표가 변경되지않아 MoveFunc에서 알맞는 차에 XY좌표를 지정해주기위해 만듬 ㅅㅂ
	int M_Y; //얘도
	int M_C; //이건 위에꺼 할라고 차 지정해주는 변수 쉬밤
	int _Stage;
	int _Score;
	int _FScore;
};