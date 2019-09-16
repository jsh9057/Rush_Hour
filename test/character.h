#pragma once
#include <iostream>

class Character
{
public:
	Character();
	~Character();
	friend class Control;
	int GetCX();           //Character의 x좌표 반환
	int GetCY();           //Character의 Y좌표 반환
	int GetState();
	char* GetCharacter();   //Character의 모양반환
	void SetCXY(int, int);   //Character의 x,y값을 지정
	void MoveC(int, int);   //Character의 움직임
	void SetState(int x); //캐릭터가 보고있는 방향 (0은 위, 1은 오른쪽, 2는 아래, 3은 왼쪽)
private:
	int _Cx;             //Character의 x좌표
	int _Cy;             //Character의 y좌표
	char *_CSign;       //Character의 모양
	int _State;
};
