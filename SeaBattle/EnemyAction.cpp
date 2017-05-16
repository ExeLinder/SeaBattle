#include"Functions.h"

extern char map[row][col];
extern bool soundOn;
extern int enemyScore;//Очки противника
extern bool viewMode;//Режим отрисовки карты

bool EnemyAction()//Функция хода противника
{
	int shiftDown = 2;//Сдвиг вниз
	int shiftRight = 2;//Сдвиг вправо
	bool attempt = true;//Попытка хода
	static int destroyedTargetX = 0;//Координата X для слежения за подбитым кораблем
	static int destroyedTargetY = 0;//Координата Y для слежения за подбитым кораблем
	static int nextShot = 0;//Шаг хода алгоритма обстрела
	static int x = 0;//Координата хода X
	static int y = 0;//Координата хода Y
	bool outOfRange = false;//Защита от выхода за пределы поля


	cout << "\tХод противника >> ";

	if (soundOn) VoiceMessage(3);

	while (attempt)
	{
		
		Sleep(1000);

		attempt = false;//Сброс перед выстрелом
		outOfRange = false;

		//------------------------ Алгоритм выбора цели вне алгоритма поиска --------------------------
		if (nextShot == 0)
		{
			x = (rand() % 10) + shiftRight;
			y = (rand() % 10) + shiftDown;
		}
		//------------------------ Алгоритм выбора цели по алгоритму поиска ---------------------------
		if (nextShot == 1)
		{
			y -= 1; if (y < 2) outOfRange = true;
		}
		if (nextShot == 2)
		{
			y += 1; if (y > 11) outOfRange = true;
		}
		if (nextShot == 3)
		{
			x -= 1; if (x < 2) outOfRange = true;
		}
		if (nextShot == 4)
		{
			x += 1; if (x > 11) outOfRange = true;
		}
		//----------------------------------- Отбраковка цели ------------------------------------------
		if (map[y][x] == '*' || map[y][x] == 'X' || outOfRange == true)
		{
			if (nextShot > 0 && nextShot < 4)
			{
				x = destroyedTargetX;
				y = destroyedTargetY;

				nextShot++;
			}

			if (nextShot > 4) { nextShot = 0; cout << "\n\nАлгоритм вышел за пределы дозволенного!!!\n\n"; }

			attempt = true;
		}
		//----------------------------------- Обработка попадания ----------------------------------------
		else if (map[y][x] == '#')
		{
			enemyScore++;

			if (nextShot == 0)//Если первое попадание - запоминаем координаты первой уничтоженной цели
			{
				destroyedTargetX = x;
				destroyedTargetY = y;
				nextShot++;//Переходим к алгоритму обстрела
			}

			attempt = true;//Попытка удачная

			cout << (char)(x - 2 + 97) << " : " << y - 2;//Превод цифровых координат в буквенные

			Sleep(1000);

			if (soundOn)SoundEffect(0);

			map[y][x] = 'X';//Отмечаем место попадания

			cout << " - Попадание в цель";

			if (soundOn)SoundEffect(1);

			if (soundOn) VoiceMessage(4);

			//Если корабль уничтожен - выходим из алгоритма обстрела, если подбит - продолжаем обстреливать
			if (IsKilled(destroyedTargetY, destroyedTargetX, y, x))
			{
				cout << " - Убил\n\n";
				if (soundOn) VoiceMessage(5);
				FreeZoneMarking(destroyedTargetY, destroyedTargetX, y, x, 1);
				nextShot = 0;
			}
			else
			{
				cout << " - Ранил\n\n";
				if (soundOn) VoiceMessage(6);
				FreeZoneMarking(y, x, y, x, 0);
			}

			if (soundOn) SoundEffect(4); else Sleep(2500);

			PrintMap(viewMode);//Функция отрисовки карты

			if (enemyScore == 20) return true;

			cout << "\tДополнительный ход противника >> ";
			if (soundOn) VoiceMessage(7);
		}
		else
		//--------------------------------------- Обработка промаха -----------------------------------------
		{
			attempt = false;//Попытка неудачная

			cout << (char)(x - 2 + 97) << " : " << y - 2;//Превод цифровых координат в буквенные

			Sleep(1000);

			if (soundOn)SoundEffect(0);
			
			map[y][x] = '*';//Отмечаем место промаха
	
			cout << " - Промах!!!\n\n";

			if (soundOn)SoundEffect(2); else Sleep(2500);
			if (soundOn) VoiceMessage(8);

			PrintMap(viewMode);//Функция отрисовки карты

			if (soundOn)SoundEffect(6);

			if (nextShot > 0 && nextShot < 4)//Если пункт алгоритма промах - переходим к следующему
			{
				//За точку отсчета берем координаты первой уничтоженной цели
				x = destroyedTargetX;
				y = destroyedTargetY;
				nextShot++;
			}
			else if (nextShot == 4) nextShot = 0;
		}
		//--------------------------------------------------------------------------------------------------
	}
	return false;
}
