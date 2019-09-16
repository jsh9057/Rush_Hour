#pragma once
#include <iostream>

class Character
{
public:
	Character();
	~Character();
	friend class Control;
	int GetCX();           //Character�� x��ǥ ��ȯ
	int GetCY();           //Character�� Y��ǥ ��ȯ
	int GetState();
	char* GetCharacter();   //Character�� ����ȯ
	void SetCXY(int, int);   //Character�� x,y���� ����
	void MoveC(int, int);   //Character�� ������
	void SetState(int x); //ĳ���Ͱ� �����ִ� ���� (0�� ��, 1�� ������, 2�� �Ʒ�, 3�� ����)
private:
	int _Cx;             //Character�� x��ǥ
	int _Cy;             //Character�� y��ǥ
	char *_CSign;       //Character�� ���
	int _State;
};
