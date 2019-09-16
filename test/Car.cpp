#include "Car.h"


Car::Car()
{
	c_board = 0;
	c_number = 0;
	c_length = 0;
	c_option = 0;
	c_X = 0;
	c_Y = 0;
}


Car::~Car()
{
}
void Car::SetXY(int x, int y){
	c_X = x;
	c_Y = y;
}
void Car::SetOption(int number, int length, int option){
	c_number = number;
	c_length = length;
	c_option = option;
}
void Car::SetBoard(){ //탑승상태 변경
if(c_board == 0)
	c_board =1;
else
	c_board = 0;
}
void Car::MoveXY(int x,int y){
	c_X += x;
	c_Y += y;
}