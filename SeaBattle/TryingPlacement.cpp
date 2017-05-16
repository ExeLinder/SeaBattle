#include"Functions.h"

extern char map[row][col];

bool TryingPlacement(int deck, int dir, int x, int y)
{
	bool isset = 0;
	int shiftDown = 2;
	int shiftRight = 2;
	int placeFree = 0;

	if (dir == 0)//�� �����������
	{
		if (map[y + shiftDown][x + shiftRight] == '.')//���� � �������� ����������� ��� �������
		{
			for (int i = y + shiftDown - 1; i < y + shiftDown + 2; i++)
			{
				for (int j = x - 1 + shiftRight; j < x + shiftRight + deck + 1; j++)
				{
					if (map[i][j] != '#' && map[i][j] != '*') placeFree++;
					//ships[i][j] = '*';//��� ����������� ������ ��������
				}
			}

			if (placeFree == deck * 3 + 6)//������ ������ ���������� ��� ������ ��� ��������, 6 ��������� ��������
			{
				for (int i = 0; i < deck; i++)
				{
						map[y + shiftDown][x + i + shiftRight] = '#'; // ��������� �������
				}
				isset = 1;
			}
		}
	}

	else if (dir == 1) //�� ���������
	{
		if (map[y + shiftDown][x + shiftRight] == '.')//���� � �������� ����������� ��� �������
		{
			for (int i = y + shiftDown - 1; i < y + shiftDown + deck + 1; i++)
			{
				for (int j = x + shiftRight - 1; j < x + shiftRight + 2; j++)
				{
					if (map[i][j] != '#' && map[i][j] != '*') placeFree++;
					//ships[i][j] = '*';//��� ����������� ������ ��������
				}
			}
			if (placeFree == deck * 3 + 6)//������ ������ ���������� ��� ������ ��� ��������, 6 ��������� ��������
			{
				for (int i = 0; i < deck; i++)
				{
						map[y + i + shiftDown][x + shiftRight] = '#';  // ��������� �������
				}
				isset = 1;
			}
		}
	}
	return isset;
}
