#include"Functions.h"

void VoiceMessage(int messageNumber)//Функция голосовых сообщений
{

		switch (messageNumber)
		{
		case 0://Выберите способ установки кораблей
		{
			PlaySound(TEXT("Message/ship_placement.wav"), NULL, SND_FILENAME);	
		}
		break;
		case 1://Установка флота игрока
		{
			PlaySound(TEXT("Message/player_fleet_set.wav"), NULL, SND_FILENAME);
		}
		break;
		case 2://Установка флота противника
		{
			PlaySound(TEXT("Message/enemy_fleet_set.wav"), NULL, SND_FILENAME);
		}
		break;
		case 3://Ход противника
		{
			PlaySound(TEXT("Message/enemy_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 4://Попадание в цель
		{
			PlaySound(TEXT("Message/catch.wav"), NULL, SND_FILENAME);
		}
		break;
		case 5://Убил
		{
			PlaySound(TEXT("Message/kill.wav"), NULL, SND_FILENAME);
		}
		break;
		case 6://Ранил
		{
			PlaySound(TEXT("Message/wound.wav"), NULL, SND_FILENAME);
		}
		break;
		case 7://Дополнительный ход противника
		{
			PlaySound(TEXT("Message/bonus_enemy_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 8://Промах
		{
			PlaySound(TEXT("Message/fail.wav"), NULL, SND_FILENAME);
		}
		break;
		case 9://Ваш ход
		{
			PlaySound(TEXT("Message/your_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 10://Введите координаты цели
		{
			PlaySound(TEXT("Message/cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 11://В это место уже стреляли
		{
			PlaySound(TEXT("Message/old_cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 12://Дополнительный ход игрока
		{
			PlaySound(TEXT("Message/bonus_player_step.wav"), NULL, SND_FILENAME);
		}
		break;
		case 13://Не верные координаты
		{
			PlaySound(TEXT("Message/wrong_cordinates.wav"), NULL, SND_FILENAME);
		}
		break;
		case 14://Победа
		{
			PlaySound(TEXT("Message/victory.wav"), NULL, SND_FILENAME);
		}
		break;
		case 15://Поражение
		{
			PlaySound(TEXT("Message/defeat.wav"), NULL, SND_FILENAME);
		}
		break;
		default:
			break;
		}
}
