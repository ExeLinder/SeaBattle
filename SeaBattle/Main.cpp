#include"Functions.h"

char tmp[tmpRow][tmpCol];//��������������� ������ ��� ������ ��������� ��������

char map[row][col] = {//������ � ������
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

int difficulty = 0;//������� ��������� 0 - ���������� ���, 1 - ������� ���������� ����, 2 - � ���������� ������� ��������� ����/�����
bool viewMode = false;// 0 - ������� �����, 1 - ��������� �����(����������� �������� ����������), 2 - ������ ��������� ��������, 
bool soundOn = true;//��������/��������� �������� �������������
int enemyScore = 0;//���������� ����� ����������
int playerScore = 0;//���������� ����� ������
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
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//�����

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

	SetConsoleTitle(L"Sea Battle v1.18 Beta     ��/���/16/4     ������ ������ - ���������� ��� �������� ���");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Title();

	cout << "\t\t\t\t\t  ������� ���\n";

	if (soundOn) SoundEffect(7); else Sleep(2000);

	srand(time(NULL));

	while (1)//���� ������ ��������� ��������
	{
		char placement;//���������� ������

		PrintMap(viewMode);//������� ��������� �����

		cout << "\t�������� ������ ��������� ��������\n\n";

		cout << "\t(1) - ������ ���������\t\t\t\t"       << "(3) - ����\t "; if (soundOn)cout << "< ��� >\n"; else cout << "< ���� >\n";
		cout << "\t(2) - �������������� ���������\t\t\t" << "(4) - �������\t ";    if (viewMode)cout << "< ��� >\n"; else cout << "< ���� >\n";
		cout << "\t(0) - ���������� ������\t\t\t\t"		 << "(5) - ���������\t < " << difficulty << "    >\n";

		if (soundOn & oncePlay) { VoiceMessage(0); oncePlay = false; }

		placement = _getch();

		if (placement == '1')//������ ��������� ����� ������
		{
			SetPlayerFleetManual();//������� ��������� (������ ��������� ����� ������)
			break;
		}
		else if (placement == '2')//�������������� ��������� ����� ������
		{
			SetPlayerFleetAuto();//������� ��������� (�������������� ��������� ����� ������)
			break;
		}
		else if (placement == '0')//���������� ������
		{
			exit(0);//������� ���������� ����������
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
		else//���� ����� �� �� �����
		{
			cout << "\t�� ������ �����!!!\n"; Sleep(2000);
		}
	}

	PrintMap(viewMode);//������� ��������� �����

	SetEnemyFleet();//������� ��������� (��������� ���������� �����)

	PrintMap(viewMode);//������� ��������� �����

	if (rand()%2 == 0)//��������� ����� ������� ����
	{
		goto PlayerAction;//���� 0  ���� �������� �����
	}
	else 
	{
		goto EnemyAction;//���� 1 ���� �������� ���������
	}
	
	while (1)//���� ����
	{
	PlayerAction: if(PlayerAction()) break;//������� ���� ������ (���� �� ��������� goto)

	EnemyAction: if (EnemyAction()) break;//������� ���� ���������� (���� �� ��������� goto)
	}
	
	cout << "\n\t���� �������� �� - ";

	if (playerScore == 20) 
	{
		cout << "��������!!!";
		if (soundOn) VoiceMessage(14);
	}
	else
	{
		cout << "���������!!!\n";
		if (soundOn) VoiceMessage(15);
	}
	_getch();
}