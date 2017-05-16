#include"Functions.h"

extern char map[row][col];
extern bool soundOn;
extern int playerScore;//���� ������
extern bool viewMode;//����� ��������� �����
extern int difficulty;//���������

bool PlayerAction()//������� ���� ������
{
	int shiftDown = 2;//����� ����
	int shiftRight = 17;//����� �� ����� ����������
	char hor;//�������������� ���������� (a - j)(char)
	char ver;//������������ ���������� (0 - 9)(char)
	bool attempt = true;//������� ����
	int x = 0;//���������� ���� X
	int y = 0;//���������� ���� Y
	static int destroyedTargetX = 0;//���������� X ��� �������� �� �������� ��������
	static int destroyedTargetY = 0;//���������� Y ��� �������� �� �������� ��������
	static int watching = false;//��������

	cout << "\t��� ���\n";

	if (soundOn) VoiceMessage(9);

	while (attempt)
	{
		attempt = false;//����� ����� ���������

		cout << "\t������� ���������� ���� >> ";

		if (soundOn) VoiceMessage(10);

		hor = _getche();
		cout << " : ";
		ver = _getche();

		Sleep(500);

		x = ((int)hor) - 97;//�������������� (char) � ����� (0-9)
		y = ((int)ver) - 48;//�������������� (char) � ����� (0-9)

		if (x >= 0 && x <= 9 && y >= 0 && y <= 9)//���� ���������� ���������� (0-9)
		{
			if (map[y + shiftDown][x + shiftRight] == '*' || map[y + shiftDown][x + shiftRight] == 'X')//���� ��� �������� ����
			{
				attempt = true;

				cout << " - � ��� ����� ��� ��������!!!\n\n";

				if (soundOn) VoiceMessage(11);

				Sleep(2000);

				PrintMap(viewMode);//������� ��������� �����
			}
			else if (map[y + shiftDown][x + shiftRight] == '#')//���� ���������
			{
				if (!watching)
				{
					destroyedTargetX = x;
					destroyedTargetY = y;
					watching = true;
				}

				playerScore++;

				attempt = true;//������� �������

				if (soundOn)SoundEffect(0);

				map[y + shiftDown][x + shiftRight] = 'X';//�������� ����� ���������

				cout << " - ��������� � ����";

				if (soundOn) SoundEffect(1); else Sleep(2000);

				if (soundOn) VoiceMessage(4);

				if (difficulty < 2) //0 - ���������� ���, 1 - ������� ���������� ����, 2 - � ���������� ������� ��������� ����/�����
				{
				if (IsKilled(destroyedTargetY + shiftDown, destroyedTargetX + shiftRight, y + shiftDown, x + shiftRight))
				{
					cout << " - ����\n\n";
					if (soundOn) VoiceMessage(5);
					watching = false;
					if (difficulty!=1) FreeZoneMarking(destroyedTargetY + shiftDown, destroyedTargetX + shiftRight, y + shiftDown, x + shiftRight, 1);
				}
				else
				{
					cout << " - �����\n\n";
					if (soundOn) VoiceMessage(6);
					if (difficulty!=1) FreeZoneMarking( y + shiftDown, x + shiftRight, y + shiftDown, x + shiftRight, 0);
				}
				}
				
				PrintMap(viewMode);//������� ��������� �����

				if (soundOn)SoundEffect(3);

				if (playerScore == 20) return true;

				cout << "\t�������������� ���\n\n";

				if (soundOn) VoiceMessage(12);
			}
			else//���� ������
			{
				attempt = false;//������� ���������
				
				if (soundOn)SoundEffect(0);

				map[y + shiftDown][x + shiftRight] = '*';//�������� ����� �������

				cout << " - ������!!!\n\n";

				if (soundOn)SoundEffect(2); else Sleep(2000);

				if (soundOn) VoiceMessage(8);

				PrintMap(viewMode);//������� ��������� �����

				if (soundOn)SoundEffect(5);
			}
		}
		else
		{
			attempt = true;//��� ����������� ��������� �����������  ���� ��� �������
			cout << " - �� ������ ����������!!!\n\n";
			if (soundOn) VoiceMessage(13);
		}
	}
	return false;
}