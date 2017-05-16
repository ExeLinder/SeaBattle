#include"Functions.h"

extern char map[row][col];
extern char tmp[tmpRow][tmpCol];
extern int enemyScore;//���� ����������
extern int playerScore;//���� ������

void PrintMap(int mode)//������� ��������� �����
{
	//mode 0 - ������� �����, 1 - ��������� ����� (����������� �������� ����������), 2 - ������ ��������� ��������,
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	cout << "\n\n\t\t      ����� - " << playerScore << "                                  ��������� - " << enemyScore << "\n";

	// ������������ ����� ������� map �� �����
	cout << "\n";
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		for (int j = 0; j < col - 1; j++)
		{
			if (map[i][j] == '#')//�������
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));//�������
			}
			else if (map[i][j] == '*')//������ ����� ���������
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));//�����
			}
			else if (map[i][j] == '.')//����
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));//�����
			}
			else if (map[i][j] == 'X')//��������
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));//�������
			}
			else if (map[i][j] == 43 || map[i][j] == 45 || map[i][j] == 124)//������� �����
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));//������
			}
			
			
			if (mode == 0 && j > 16 && map[i][j] == '#')//�� ������� ������� ����������
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 9));//�����
				cout << '.' << "  ";
			}
			else if (mode == 2 && i > 1 && i < 12 && j > 1 && j < 12 && tmp[i - 2][j - 2] == '#')//����� ������ ��������� ��������
			{
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));//������ ��������� ������� ���������

				for (int y = i - 1; y < i + 2; y++)
				{
					for (int x = j - 1; x < j + 2; x++)
					{
						if (map[y][x] == '#') SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 12));//������� ��������� ������� ���������
					}
				}
					cout << tmp[i - 2][j - 2] << "  ";
			}
			else
			{
				cout << map[i][j] << "  ";//������� �����
			}

			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//�����
		}
		cout << "\n\n";
	}
	
}
