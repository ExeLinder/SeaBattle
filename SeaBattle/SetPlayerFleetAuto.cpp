#include"Functions.h"
extern bool soundOn;

bool SetPlayerFleetAuto()//������� ��������� (�������������� ��������� ����� ������)
{
	if (soundOn) VoiceMessage(1);

	SetShipAuto(4, 0);
	SetShipAuto(3, 0);
	SetShipAuto(3, 0);
	SetShipAuto(2, 0);
	SetShipAuto(2, 0);
	SetShipAuto(2, 0);
	SetShipAuto(1, 0);
	SetShipAuto(1, 0);
	SetShipAuto(1, 0);
	SetShipAuto(1, 0);
	return true;
}
