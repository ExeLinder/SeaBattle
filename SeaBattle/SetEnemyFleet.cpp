#include"Functions.h"
extern bool soundOn;

bool SetEnemyFleet()//Функция контейнер (установка вражеского флота)
{
	if (soundOn) VoiceMessage(2);

	SetShipAuto(4, 1);
	SetShipAuto(3, 1);
	SetShipAuto(3, 1);
	SetShipAuto(2, 1);
	SetShipAuto(2, 1);
	SetShipAuto(2, 1);
	SetShipAuto(1, 1);
	SetShipAuto(1, 1);
	SetShipAuto(1, 1);
	SetShipAuto(1, 1);
	return true;
}
