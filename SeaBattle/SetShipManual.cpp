#include"Functions.h"

extern char tmp[tmpRow][tmpCol];

bool SetShipManual(int deck)//������� ������ ��������� �������
{
	int isset = 0;
	char choice;

	int yStart = 0;//��������� ���������� ��������� ������� (Y)
	int xStart = 0;//��������� ���������� ��������� ������� (X)
	int dir = 0;//������������ ������� (��������������/������������)
	
	while (isset==0)
	{
	
	//������� ������� (����������� �������)
	for (int i = 0; i < tmpRow; i++)
	{
		for (int j = 0; j < tmpCol - 1; j++)
		{
			tmp[i][j] = '.';
		}
	}

	if (dir == 0)
	{
		for (int i = 0; i < deck; i++)
			//��������� ������� �� �����������
			tmp[yStart][xStart + i] = '#';
	}
	else if (dir == 1)
	{
		for (int i = 0; i < deck; i++)
			//��������� ������� �� ���������
			tmp[yStart + i][xStart] = '#';
	}

		PrintMap(2);

		cout << "\t(W) - �����\t" << "\t(R) - ���������\n";
		cout << "\t(S) - ����\t" << "\t(I) - ����������\n";
		cout << "\t(A) - �����\n";
		cout << "\t(D) - ������\n\n";
		cout << "\t������� - ���������  |" << "  ������  - ��������  |" << "  �������  - ����������\n";

		choice = _getch();

		switch (choice)
		{
			//����������� �����
		case 'w': if (yStart > 0) yStart--;
			break;
			//����������� ����
		case 's': if (dir == 0 && yStart < tmpRow - 1) yStart++; else if (dir == 1 && yStart + deck < tmpRow) yStart++;
			break;
			//����������� �����
		case 'a': if (xStart > 0) xStart--;
			break;
			//����������� ������
		case 'd': if (dir == 0 && xStart + deck < tmpCol - 1) xStart++; else if (dir == 1 && xStart < tmpCol - 2) xStart++;
			break;
			//��������� ������������ (��������������/������������)
		case 'r': dir = !dir; xStart = 0; yStart = 0;
			break;
		case 'i':  isset = TryingPlacement(deck, dir, xStart, yStart);
			break;
		default:
			break;
		}
	}
	return true;
}