#include"Functions.h"
extern bool soundOn;

bool SetPlayerFleetManual()//������� ��������� (������ ��������� ����� ������)
{
	if (soundOn) VoiceMessage(1);

	SetShipManual(4);
	SetShipManual(3);
	SetShipManual(3);
	SetShipManual(2);
	SetShipManual(2);
	SetShipManual(2);
	SetShipManual(1);
	SetShipManual(1);
	SetShipManual(1);
	SetShipManual(1);
	return true;
}


