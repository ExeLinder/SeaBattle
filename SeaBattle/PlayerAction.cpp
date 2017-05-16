#include"Functions.h"

extern char map[row][col];
extern bool soundOn;
extern int playerScore;//Очки игрока
extern bool viewMode;//Режим отрисовки карты
extern int difficulty;//Сложность

bool PlayerAction()//Функция хода игрока
{
	int shiftDown = 2;//Сдвиг вниз
	int shiftRight = 17;//Сдвиг на карту противника
	char hor;//Горизонтальная координата (a - j)(char)
	char ver;//Вертикальная координата (0 - 9)(char)
	bool attempt = true;//Попытка хода
	int x = 0;//Координата хода X
	int y = 0;//Координата хода Y
	static int destroyedTargetX = 0;//Координата X для слежения за подбитым кораблем
	static int destroyedTargetY = 0;//Координата Y для слежения за подбитым кораблем
	static int watching = false;//Слежение

	cout << "\tВаш ход\n";

	if (soundOn) VoiceMessage(9);

	while (attempt)
	{
		attempt = false;//Сброс перед выстрелом

		cout << "\tВведите координаты цели >> ";

		if (soundOn) VoiceMessage(10);

		hor = _getche();
		cout << " : ";
		ver = _getche();

		Sleep(500);

		x = ((int)hor) - 97;//Преобразование (char) к числу (0-9)
		y = ((int)ver) - 48;//Преобразование (char) к числу (0-9)

		if (x >= 0 && x <= 9 && y >= 0 && y <= 9)//Если координаты допустимые (0-9)
		{
			if (map[y + shiftDown][x + shiftRight] == '*' || map[y + shiftDown][x + shiftRight] == 'X')//Если уже стреляли сюда
			{
				attempt = true;

				cout << " - В это место уже стреляли!!!\n\n";

				if (soundOn) VoiceMessage(11);

				Sleep(2000);

				PrintMap(viewMode);//Функция отрисовки карты
			}
			else if (map[y + shiftDown][x + shiftRight] == '#')//Если попадание
			{
				if (!watching)
				{
					destroyedTargetX = x;
					destroyedTargetY = y;
					watching = true;
				}

				playerScore++;

				attempt = true;//Попытка удачная

				if (soundOn)SoundEffect(0);

				map[y + shiftDown][x + shiftRight] = 'X';//Отмечаем место попадания

				cout << " - Попадание в цель";

				if (soundOn) SoundEffect(1); else Sleep(2000);

				if (soundOn) VoiceMessage(4);

				if (difficulty < 2) //0 - отображает все, 1 - убирает маркировку поля, 2 - в дополнение убирает сообщения убил/ранил
				{
				if (IsKilled(destroyedTargetY + shiftDown, destroyedTargetX + shiftRight, y + shiftDown, x + shiftRight))
				{
					cout << " - Убил\n\n";
					if (soundOn) VoiceMessage(5);
					watching = false;
					if (difficulty!=1) FreeZoneMarking(destroyedTargetY + shiftDown, destroyedTargetX + shiftRight, y + shiftDown, x + shiftRight, 1);
				}
				else
				{
					cout << " - Ранил\n\n";
					if (soundOn) VoiceMessage(6);
					if (difficulty!=1) FreeZoneMarking( y + shiftDown, x + shiftRight, y + shiftDown, x + shiftRight, 0);
				}
				}
				
				PrintMap(viewMode);//Функция отрисовки карты

				if (soundOn)SoundEffect(3);

				if (playerScore == 20) return true;

				cout << "\tДополнительный ход\n\n";

				if (soundOn) VoiceMessage(12);
			}
			else//Если промах
			{
				attempt = false;//Попытка неудачная
				
				if (soundOn)SoundEffect(0);

				map[y + shiftDown][x + shiftRight] = '*';//Отмечаем место промаха

				cout << " - Промах!!!\n\n";

				if (soundOn)SoundEffect(2); else Sleep(2000);

				if (soundOn) VoiceMessage(8);

				PrintMap(viewMode);//Функция отрисовки карты

				if (soundOn)SoundEffect(5);
			}
		}
		else
		{
			attempt = true;//При неправильно введенных координатах  даем еще попытку
			cout << " - Не верные координаты!!!\n\n";
			if (soundOn) VoiceMessage(13);
		}
	}
	return false;
}