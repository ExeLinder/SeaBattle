#pragma once

#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#pragma comment(lib, "winmm")

using namespace std;

const int row = 13;
const int col = 29;
const int tmpRow = 10;
const int tmpCol = 11;

void PrintMap(int mode);//�������� ������� ��������� �����
bool SetEnemyFleet();//�������� ������� ���������� (��������� ���������� �����)
bool SetPlayerFleetAuto();//�������� ������� ���������� (�������������� ��������� ����� ������)
bool SetPlayerFleetManual();//�������� ������� ���������� (������ ��������� ����� ������)
bool SetShipAuto(int deck, int player);//�������� ������� �������������� ��������� �������
bool SetShipManual(int deck);//�������� ������� ������ ��������� �������
bool TryingPlacement(int deck, int dir, int x, int y);//�������� ������� �������� ����������� ���������� ������� �� �������� �����������
bool IsKilled(int beginY, int beginX, int currentY, int currentX);//�������� ������� �������� ����/����� (���� = true)
void FreeZoneMarking(int beginY, int beginX, int endY, int endX, bool stage);//������� ���������� ��������� ������� ������ �������
bool PlayerAction();//�������� ������� ���� ������
bool EnemyAction();//�������� ������� ���� ����������
void SoundEffect(int effectNumber);//�������� ������� �������� ��������
void VoiceMessage(int messageNumber);//�������� ������� ��������� ���������
void Title();
