#include"Functions.h"

extern char map[row][col];
extern char tmp[tmpRow][tmpCol];
extern int enemyScore;//Очки противника
extern int playerScore;//Очки игрока

void PrintMap(int mode)//Функция отрисовки карты
{
	//mode 0 - обычный режим, 1 - читерский режим (Отображение кораблей противника), 2 - ручная установка кораблей,
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	cout << "\n\n\t\t      Игрок - " << playerScore << "                                  Противник - " << enemyScore << "\n";

	// Посимвольный вывод массива map на экран
	cout << "\n";
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		for (int j = 0; j < col - 1; j++)
		{
			if (map[i][j] == '#')//Корабль
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));//Зеленый
			}
			else if (map[i][j] == '*')//Пустое место попадания
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));//Синий
			}
			else if (map[i][j] == '.')//Море
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));//Синий
			}
			else if (map[i][j] == 'X')//Подбитый
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));//Красный
			}
			else if (map[i][j] == 43 || map[i][j] == 45 || map[i][j] == 124)//Границы карты
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));//Желтый
			}
			
			
			if (mode == 0 && j > 16 && map[i][j] == '#')//не выводим корабли противника
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));//Синий
				cout << '.' << "  ";
			}
			else if (mode == 2 && i > 1 && i < 12 && j > 1 && j < 12 && tmp[i - 2][j - 2] == '#')//Режим ручной установки кораблей
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));//Желтый установка корабля разрешена

				for (int y = i - 1; y < i + 2; y++)
				{
					for (int x = j - 1; x < j + 2; x++)
					{
						if (map[y][x] == '#') SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));//Красный установка корабля запрещена
					}
				}
					cout << tmp[i - 2][j - 2] << "  ";
			}
			else
			{
				cout << map[i][j] << "  ";//Обычный режим
			}

			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//Белый
		}
		cout << "\n\n";
	}
	
}
