#pragma once
class Car
{
private:
	int c_board; //0이면 탑승x, 1이면 탑승 상태
	int c_length; //차 길이
	int c_number; //차 번호
	int c_option; //차 가로세로 판단(0은 가로, 1은 세로)
	int c_X; //차의 배열상 X좌표
	int c_Y; //차의 배열상 Y좌표
public:
	Car();
	~Car();
	friend class Control;
	void SetXY(int x, int y);
	void SetOption(int number, int length, int option);
	void SetBoard();
	void MoveXY(int x,int y);
};