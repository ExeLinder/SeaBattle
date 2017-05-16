#include"Functions.h"

extern char map[row][col];

void FreeZoneMarking(int beginY, int beginX, int endY, int endX, bool stage)//Функция маркировки свободной области вокруг корабля
{
		//Отмечаем поля по диагонали от места попадания
		if (map[endY - 1][endX - 1] == '.') 
			map[endY - 1][endX - 1] = '*';//Левый верхний квадрат
		if (map[endY - 1][endX + 1] == '.') 
			map[endY - 1][endX + 1] = '*';//Правый верхний квадрат
		if (map[endY + 1][endX - 1] == '.') 
			map[endY + 1][endX - 1] = '*';//Левый нижний квадрат
		if (map[endY + 1][endX + 1] == '.')
			map[endY + 1][endX + 1] = '*';//Правый нижний квадрат

	if (stage == 1)//Если убит + маркировка по вертикали и горизонтали
	{
			int i = 0;

			for (i = endY; map[i][endX] == 'X'; i++);//Вниз
				if (map[i][endX] == '.') map[i][endX] = '*';
				
			for (i = endY; map[i][endX] == 'X'; i--);//Вверх
				if (map[i][endX] == '.') map[i][endX] = '*';

			for (i = endX; map[endY][i]=='X'; i++);//Вправо
				if (map[endY][i] == '.') map[endY][i] = '*';
		
			for (i = endX; map[endY][i]=='X'; i--);//Влево
				if (map[endY][i] == '.') map[endY][i] = '*';
	}
}