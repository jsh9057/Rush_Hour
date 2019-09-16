#include "character.h"
#include <iostream>
#include "Consola.h"
using namespace std;


Character::Character()
{
	_CSign= new char[sizeof(char)*3];
	strcpy(_CSign, "♥");
}
Character::~Character()
{
	delete _CSign;
}

int Character::GetCX() 
{
	return this->_Cx;
}

int Character::GetCY()
{
	return this->_Cy;
}

char* Character::GetCharacter() 
{
	return _CSign;
}

void Character::SetCXY(int x,int y)
{
	_Cx=x;
	_Cy=y;
}

void Character::MoveC(int addx,int addy)
{
	_Cx=_Cx+addx;
	_Cy=_Cy+addy;
}
void Character::SetState(int x){ //캐릭터가 보고있는 방향 (0은 위, 1은 오른쪽, 2는 아래, 3은 왼쪽)
	_State=x;
}