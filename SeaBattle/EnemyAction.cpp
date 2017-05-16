#include"Functions.h"

extern char map[row][col];
extern bool soundOn;
extern int enemyScore;//���� ����������
extern bool viewMode;//����� ��������� �����

bool EnemyAction()//������� ���� ����������
{
	int shiftDown = 2;//����� ����
	int shiftRight = 2;//����� ������
	bool attempt = true;//������� ����
	static int destroyedTargetX = 0;//���������� X ��� �������� �� �������� ��������
	static int destroyedTargetY = 0;//���������� Y ��� �������� �� �������� ��������
	static int nextShot = 0;//��� ���� ��������� ��������
	static int x = 0;//���������� ���� X
	static int y = 0;//���������� ���� Y
	bool outOfRange = false;//������ �� ������ �� ������� ����


	cout << "\t��� ���������� >> ";

	if (soundOn) VoiceMessage(3);

	while (attempt)
	{
		
		Sleep(1000);

		attempt = false;//����� ����� ���������
		outOfRange = false;

		//------------------------ �������� ������ ���� ��� ��������� ������ --------------------------
		if (nextShot == 0)
		{
			x = (rand() % 10) + shiftRight;
			y = (rand() % 10) + shiftDown;
		}
		//------------------------ �������� ������ ���� �� ��������� ������ ---------------------------
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
		//----------------------------------- ���������� ���� ------------------------------------------
		if (map[y][x] == '*' || map[y][x] == 'X' || outOfRange == true)
		{
			if (nextShot > 0 && nextShot < 4)
			{
				x = destroyedTargetX;
				y = destroyedTargetY;

				nextShot++;
			}

			if (nextShot > 4) { nextShot = 0; cout << "\n\n�������� ����� �� ������� ������������!!!\n\n"; }

			attempt = true;
		}
		//----------------------------------- ��������� ��������� ----------------------------------------
		else if (map[y][x] == '#')
		{
			enemyScore++;

			if (nextShot == 0)//���� ������ ��������� - ���������� ���������� ������ ������������ ����
			{
				destroyedTargetX = x;
				destroyedTargetY = y;
				nextShot++;//��������� � ��������� ��������
			}

			attempt = true;//������� �������

			cout << (char)(x - 2 + 97) << " : " << y - 2;//������ �������� ��������� � ���������

			Sleep(1000);

			if (soundOn)SoundEffect(0);

			map[y][x] = 'X';//�������� ����� ���������

			cout << " - ��������� � ����";

			if (soundOn)SoundEffect(1);

			if (soundOn) VoiceMessage(4);

			//���� ������� ��������� - ������� �� ��������� ��������, ���� ������ - ���������� ������������
			if (IsKilled(destroyedTargetY, destroyedTargetX, y, x))
			{
				cout << " - ����\n\n";
				if (soundOn) VoiceMessage(5);
				FreeZoneMarking(destroyedTargetY, destroyedTargetX, y, x, 1);
				nextShot = 0;
			}
			else
			{
				cout << " - �����\n\n";
				if (soundOn) VoiceMessage(6);
				FreeZoneMarking(y, x, y, x, 0);
			}

			if (soundOn) SoundEffect(4); else Sleep(2500);

			PrintMap(viewMode);//������� ��������� �����

			if (enemyScore == 20) return true;

			cout << "\t�������������� ��� ���������� >> ";
			if (soundOn) VoiceMessage(7);
		}
		else
		//--------------------------------------- ��������� ������� -----------------------------------------
		{
			attempt = false;//������� ���������

			cout << (char)(x - 2 + 97) << " : " << y - 2;//������ �������� ��������� � ���������

			Sleep(1000);

			if (soundOn)SoundEffect(0);
			
			map[y][x] = '*';//�������� ����� �������
	
			cout << " - ������!!!\n\n";

			if (soundOn)SoundEffect(2); else Sleep(2500);
			if (soundOn) VoiceMessage(8);

			PrintMap(viewMode);//������� ��������� �����

			if (soundOn)SoundEffect(6);

			if (nextShot > 0 && nextShot < 4)//���� ����� ��������� ������ - ��������� � ����������
			{
				//�� ����� ������� ����� ���������� ������ ������������ ����
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
