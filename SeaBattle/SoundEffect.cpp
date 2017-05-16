#include"Functions.h"

void SoundEffect(int effectNumber)//Функция звуковых эффектов
{
	switch (effectNumber)
	{
	case 0://Звук выстрела и полета снаряда
	{
		PlaySound(TEXT("Sound/Shot.wav"), NULL, SND_FILENAME);
		PlaySound(TEXT("Sound/mortar_incoming.wav"), NULL, SND_FILENAME);
	}
		break;
	case 1:
	{
		PlaySound(TEXT("Sound/BigExplosion.wav"), NULL, SND_FILENAME);//Звук взрыва
	}
		break;
	case 2:
	{
		PlaySound(TEXT("Sound/plongeon.wav"), NULL, SND_FILENAME);//Звук попадания в воду
	}
		break;
	case 3:
	{
		PlaySound(TEXT("Sound/KORB5.wav"), NULL, SND_FILENAME);//Звук 
		PlaySound(TEXT("Sound/cheering.wav"), NULL, SND_FILENAME);//Звук 
	}
		break;
	case 4 :
	{
		PlaySound(TEXT("Sound/KORB5.wav"), NULL, SND_FILENAME);
		PlaySound(TEXT("Sound/WAAH.wav"), NULL, SND_FILENAME);
	}
		break;
	case 5 :
	{
		PlaySound(TEXT("Sound/boo.wav"), NULL, SND_FILENAME);
	}
		break;
	case 6 :
	{
		PlaySound(TEXT("Sound/LAUGH.wav"), NULL, SND_FILENAME);
	}
		break;
	case 7:
	{
		PlaySound(TEXT("Sound/HeyPirates.wav"), NULL, SND_FILENAME);
	}
	break;

	default:
		break;
	}
}