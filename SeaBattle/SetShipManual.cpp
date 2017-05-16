#include"Functions.h"

extern char tmp[tmpRow][tmpCol];

bool SetShipManual(int deck)//Функция ручной установки корабля
{
	int isset = 0;
	char choice;

	int yStart = 0;//Начальные координаты установки корабля (Y)
	int xStart = 0;//Начальные координаты установки корабля (X)
	int dir = 0;//Расположение корабля (горизонтальное/вертикальное)
	
	while (isset==0)
	{
	
	//Очистка массива (заполняется точками)
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
			//размещаем корабль по горизонтали
			tmp[yStart][xStart + i] = '#';
	}
	else if (dir == 1)
	{
		for (int i = 0; i < deck; i++)
			//размещаем корабль по вертикали
			tmp[yStart + i][xStart] = '#';
	}

		PrintMap(2);

		cout << "\t(W) - Вверх\t" << "\t(R) - Повернуть\n";
		cout << "\t(S) - Вниз\t" << "\t(I) - Установить\n";
		cout << "\t(A) - Влево\n";
		cout << "\t(D) - Вправо\n\n";
		cout << "\tКрасный - Запрещено  |" << "  Желтый  - Свободно  |" << "  Зеленый  - Установлен\n";

		choice = _getch();

		switch (choice)
		{
			//Перемещение вверх
		case 'w': if (yStart > 0) yStart--;
			break;
			//Перемещение вниз
		case 's': if (dir == 0 && yStart < tmpRow - 1) yStart++; else if (dir == 1 && yStart + deck < tmpRow) yStart++;
			break;
			//Перемещение влево
		case 'a': if (xStart > 0) xStart--;
			break;
			//Перемещение вправо
		case 'd': if (dir == 0 && xStart + deck < tmpCol - 1) xStart++; else if (dir == 1 && xStart < tmpCol - 2) xStart++;
			break;
			//Изменение расположения (горизонтальное/вертикальное)
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