#include"Functions.h"

char tmp[tmpRow][tmpCol];//Вспомогательный массив для ручной установки кораблей

char map[row][col] = {//Массив с картой
	"  abcdefghij     abcdefghij ",
	" +----------+   +----------+",
	"0|..........|  0|..........|",
	"1|..........|  1|..........|",
	"2|..........|  2|..........|",
	"3|..........|  3|..........|",
	"4|..........|  4|..........|",
	"5|..........|  5|..........|",
	"6|..........|  6|..........|",
	"7|..........|  7|..........|",
	"8|..........|  8|..........|",
	"9|..........|  9|..........|",
	" +----------+   +----------+" };

int difficulty = 0;//Уровень сложности 0 - отображает все, 1 - убирает маркировку поля, 2 - в дополнение убирает сообщения убил/ранил
bool viewMode = false;// 0 - обычный режим, 1 - читерский режим(Отображение кораблей противника), 2 - ручная установка кораблей, 
bool soundOn = true;//Включить/выключить звуковое сопровождение
int enemyScore = 0;//Количество очков противника
int playerScore = 0;//Количество очков игрока
bool oncePlay = true;

void main()
{
	COORD crd = { 98, 37 };

	SMALL_RECT k;
	k.Left = 1;
	k.Top = 1;
	k.Right = 98;
	k.Bottom = 37;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//Белый

	SetConsoleScreenBufferSize(hConsole, crd);
	SetConsoleWindowInfo(hConsole, TRUE, &k);

	HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	if (hCon != INVALID_HANDLE_VALUE) 
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = 16;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = 400;
		wcscpy(cfi.FaceName, L"Lucida Console");
		SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
	}

	SetConsoleTitle(L"Sea Battle v1.18 Beta     ПС/РПО/16/4     Сергей Иванов - Специально для академии ШАГ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Title();

	cout << "\t\t\t\t\t  Морской бой\n";

	if (soundOn) SoundEffect(7); else Sleep(2000);

	srand(time(NULL));

	while (1)//Цикл выбора установки кораблей
	{
		char placement;//Переменная выбора

		PrintMap(viewMode);//Функция отрисовки карты

		cout << "\tВыберите способ установки кораблей\n\n";

		cout << "\t(1) - Ручная установка\t\t\t\t"       << "(3) - Звук\t "; if (soundOn)cout << "< ВКЛ >\n"; else cout << "< ВЫКЛ >\n";
		cout << "\t(2) - Автоматическая установка\t\t\t" << "(4) - Отладка\t ";    if (viewMode)cout << "< ВКЛ >\n"; else cout << "< ВЫКЛ >\n";
		cout << "\t(0) - Завершение работы\t\t\t\t"		 << "(5) - Сложность\t < " << difficulty << "    >\n";

		if (soundOn & oncePlay) { VoiceMessage(0); oncePlay = false; }

		placement = _getch();

		if (placement == '1')//Ручная установка флота игрока
		{
			SetPlayerFleetManual();//Функция контейнер (ручная установка флота игрока)
			break;
		}
		else if (placement == '2')//Автоматическая установка флота игрока
		{
			SetPlayerFleetAuto();//Функция контейнер (автоматическая установка флота игрока)
			break;
		}
		else if (placement == '0')//Завершение работы
		{
			exit(0);//Функция завершения приложения
		}
		else if (placement == '3')
		{
			soundOn = !soundOn;
		}
		else if (placement == '4')
		{
			viewMode = !viewMode;
		}
		else if (placement == '5')
		{
			difficulty++; if (difficulty == 3) difficulty = 0;
		}
		else//Если ввели не ту цифру
		{
			cout << "\tНе верный выбор!!!\n"; Sleep(2000);
		}
	}

	PrintMap(viewMode);//Функция отрисовки карты

	SetEnemyFleet();//Функция контейнер (установка вражеского флота)

	PrintMap(viewMode);//Функция отрисовки карты

	if (rand()%2 == 0)//Случайный выбор первого хода
	{
		goto PlayerAction;//Если 0  игру начинает игрок
	}
	else 
	{
		goto EnemyAction;//Если 1 игру начинает противник
	}
	
	while (1)//Цикл игры
	{
	PlayerAction: if(PlayerAction()) break;//Функция хода игрока (вход по указателю goto)

	EnemyAction: if (EnemyAction()) break;//Функция хода противника (вход по указателю goto)
	}
	
	cout << "\n\tИгра окончена вы - ";

	if (playerScore == 20) 
	{
		cout << "Выиграли!!!";
		if (soundOn) VoiceMessage(14);
	}
	else
	{
		cout << "Проиграли!!!\n";
		if (soundOn) VoiceMessage(15);
	}
	_getch();
}