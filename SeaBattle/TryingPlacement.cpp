#include"Functions.h"

extern char map[row][col];

bool TryingPlacement(int deck, int dir, int x, int y)
{
	bool isset = 0;
	int shiftDown = 2;
	int shiftRight = 2;
	int placeFree = 0;

	if (dir == 0)//по горизонтали
	{
		if (map[y + shiftDown][x + shiftRight] == '.')//Если в выбраных координатах нет корабля
		{
			for (int i = y + shiftDown - 1; i < y + shiftDown + 2; i++)
			{
				for (int j = x - 1 + shiftRight; j < x + shiftRight + deck + 1; j++)
				{
					if (map[i][j] != '#' && map[i][j] != '*') placeFree++;
					//ships[i][j] = '*';//для отображения границ проверки
				}
			}

			if (placeFree == deck * 3 + 6)//Каждая палуба прибавляет три клетки для проверки, 6 стартовое значение
			{
				for (int i = 0; i < deck; i++)
				{
						map[y + shiftDown][x + i + shiftRight] = '#'; // размещаем корабль
				}
				isset = 1;
			}
		}
	}

	else if (dir == 1) //по вертикали
	{
		if (map[y + shiftDown][x + shiftRight] == '.')//Если в выбраных координатах нет корабля
		{
			for (int i = y + shiftDown - 1; i < y + shiftDown + deck + 1; i++)
			{
				for (int j = x + shiftRight - 1; j < x + shiftRight + 2; j++)
				{
					if (map[i][j] != '#' && map[i][j] != '*') placeFree++;
					//ships[i][j] = '*';//для отображения границ проверки
				}
			}
			if (placeFree == deck * 3 + 6)//Каждая палуба прибавляет три клетки для проверки, 6 стартовое значение
			{
				for (int i = 0; i < deck; i++)
				{
						map[y + i + shiftDown][x + shiftRight] = '#';  // размещаем корабль
				}
				isset = 1;
			}
		}
	}
	return isset;
}
