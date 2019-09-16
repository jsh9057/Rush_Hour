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
	void Start_Main(); //���ӽ���
    void CreateCar();
	void FindCar(Car *_mycar);
	void ChangeC(int x,int y);
	void StartGame(); //PrintStart�� StartStage�� ��ģ �Լ�
	void PrintCar(Car *_mycar);
	int BoardCar();
	void PrintStart(); //�������� ���ȭ��
	void StartStage();
	void MoveCar(Car _mycar);
	void CarColor(Car _mycar);
	void ChangeMap(Car _mycar);
	void DelectMap(int x, int y);
	void OutCar(Car *_mycar);
	void AddMap(Car _mycar);
	void seemap(); //�� ����ǳ� Ȯ���Ҷ�� ����
	void ClearMXY(); //������� �������� �ؿ� M_X,M_Y ���� �ʱ�ȭ �����ִ� �Լ�
	void AddMXY(int x, int y); //�̰� ����ī �����̸鼭 �� ������ ���� �ΰ� 1�� �����ְ� ���ִ°�
	void SetMC(int x); //M_C ���� �� �������ִ°�
	void SetCarXY(); //���� Ŭ����� �� �����ذ� ���� �ڵ� ���� ���������� ¥������ �����ƤФ�
	void PrintOut(Car _mycar); //OutCar���� ��������� ���� ǥ��
	void DelectOutMark(Car _mycar); //ǥ���ߴ��� �ٽ� ������
	void ResetScore();
	void MinusScore();
	void GameOver();
	void ClearStage();
private:
	Character *_C;
	Display *_D;
	Car _mycar[7]; //�ִ� �� ����
	int MCX; //���� �迭�� X��ǥ
	int MCY; //���� �迭�� Y��ǥ
	int M_X; //�ʻ�������͵� mycar�� X��ǥ�� ��������ʾ� MoveFunc���� �˸´� ���� XY��ǥ�� �������ֱ����� ���� ����
	int M_Y; //�굵
	int M_C; //�̰� ������ �Ҷ�� �� �������ִ� ���� ����
	int _Stage;
	int _Score;
	int _FScore;
};