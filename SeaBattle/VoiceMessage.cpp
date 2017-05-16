#include"Functions.h"

void VoiceMessage(int messageNumber)//������� ��������� ���������
{

		switch (messageNumber)
		{
		case 0://�������� ������ ��������� ��������
		{
			PlaySound(TEXT("Message/ship_placement.wav"), NULL, SND_FILENAME);	
		}
		break;
		case 1://��������� ����� ������
		{
			PlaySound(TEXT("Message/player_fleet_set.wav"), NULL, SND_FILENAME);
		}
		break;
		case 2://��������� ����� ����������
		{
			PlaySound(TEXT("Message/enemy_fleet_set.wav"), NULL, SND_FILENAME);
		}
		break;
		case 3://��� ����������
		{
			PlaySound(TEXT("Message/enemy_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 4://��������� � ����
		{
			PlaySound(TEXT("Message/catch.wav"), NULL, SND_FILENAME);
		}
		break;
		case 5://����
		{
			PlaySound(TEXT("Message/kill.wav"), NULL, SND_FILENAME);
		}
		break;
		case 6://�����
		{
			PlaySound(TEXT("Message/wound.wav"), NULL, SND_FILENAME);
		}
		break;
		case 7://�������������� ��� ����������
		{
			PlaySound(TEXT("Message/bonus_enemy_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 8://������
		{
			PlaySound(TEXT("Message/fail.wav"), NULL, SND_FILENAME);
		}
		break;
		case 9://��� ���
		{
			PlaySound(TEXT("Message/your_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 10://������� ���������� ����
		{
			PlaySound(TEXT("Message/cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 11://� ��� ����� ��� ��������
		{
			PlaySound(TEXT("Message/old_cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 12://�������������� ��� ������
		{
			PlaySound(TEXT("Message/bonus_player_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 13://�� ������ ����������
		{
			PlaySound(TEXT("Message/wrong_cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 14://������
		{
			PlaySound(TEXT("Message/victory.wav"), NULL, SND_FILENAME);
		}
		break;
		case 15://���������
		{
			PlaySound(TEXT("Message/defeat.wav"), NULL, SND_FILENAME);
		}
		break;
		default:
			break;
		}
}
