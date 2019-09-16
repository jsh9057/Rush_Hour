#pragma once
class Car
{
private:
	int c_board; //0�̸� ž��x, 1�̸� ž�� ����
	int c_length; //�� ����
	int c_number; //�� ��ȣ
	int c_option; //�� ���μ��� �Ǵ�(0�� ����, 1�� ����)
	int c_X; //���� �迭�� X��ǥ
	int c_Y; //���� �迭�� Y��ǥ
public:
	Car();
	~Car();
	friend class Control;
	void SetXY(int x, int y);
	void SetOption(int number, int length, int option);
	void SetBoard();
	void MoveXY(int x,int y);
};