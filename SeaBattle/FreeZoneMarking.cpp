#include"Functions.h"

extern char map[row][col];

void FreeZoneMarking(int beginY, int beginX, int endY, int endX, bool stage)//������� ���������� ��������� ������� ������ �������
{
		//�������� ���� �� ��������� �� ����� ���������
		if (map[endY - 1][endX - 1] == '.') 
			map[endY - 1][endX - 1] = '*';//����� ������� �������
		if (map[endY - 1][endX + 1] == '.') 
			map[endY - 1][endX + 1] = '*';//������ ������� �������
		if (map[endY + 1][endX - 1] == '.') 
			map[endY + 1][endX - 1] = '*';//����� ������ �������
		if (map[endY + 1][endX + 1] == '.')
			map[endY + 1][endX + 1] = '*';//������ ������ �������

	if (stage == 1)//���� ���� + ���������� �� ��������� � �����������
	{
			int i = 0;

			for (i = endY; map[i][endX] == 'X'; i++);//����
				if (map[i][endX] == '.') map[i][endX] = '*';
				
			for (i = endY; map[i][endX] == 'X'; i--);//�����
				if (map[i][endX] == '.') map[i][endX] = '*';

			for (i = endX; map[endY][i]=='X'; i++);//������
				if (map[endY][i] == '.') map[endY][i] = '*';
		
			for (i = endX; map[endY][i]=='X'; i--);//�����
				if (map[endY][i] == '.') map[endY][i] = '*';
	}
}