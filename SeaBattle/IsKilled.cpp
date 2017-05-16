#include"Functions.h"

extern char map[row][col];

bool IsKilled(int beginY, int beginX, int currentY, int currentX)//Функция проверки убил/ранил (убил = true)
{
	bool begin = true;
	bool current = true;

	for (int i = beginY-1; i < beginY+2; i++)
	{
		for (int j = beginX-1; j < beginX+2; j++)
		{
			if (map[i][j] == '#') begin = false;
		}
	}

	if (currentY != beginY || currentX != beginX)
	{
		for (int i = currentY-1; i < currentY + 2; i++)
		{
			for (int j = currentX-1; j < currentX + 2; j++)
			{
				if (map[i][j] == '#') current = false;
			}
		}
	}
	return begin && current;
}