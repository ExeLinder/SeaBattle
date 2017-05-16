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

void PrintMap(int mode);//Прототип функции отрисовки карты
bool SetEnemyFleet();//Прототип функции контейнера (Установка вражеского флота)
bool SetPlayerFleetAuto();//Прототип функции контейнера (автоматическая установка флота игрока)
bool SetPlayerFleetManual();//Прототип функции контейнера (ручная установка флота игрока)
bool SetShipAuto(int deck, int player);//Прототип функции автоматической установки корабля
bool SetShipManual(int deck);//Прототип функции ручной установки корабля
bool TryingPlacement(int deck, int dir, int x, int y);//Прототип функции проверки возможности размещения корабля по заданным координатам
bool IsKilled(int beginY, int beginX, int currentY, int currentX);//Прототип функции проверки убил/ранил (убил = true)
void FreeZoneMarking(int beginY, int beginX, int endY, int endX, bool stage);//Функция маркировки свободной области вокруг корабля
bool PlayerAction();//Прототип функции хода игрока
bool EnemyAction();//Прототип функции хода противника
void SoundEffect(int effectNumber);//Прототип функции звуковых эффектов
void VoiceMessage(int messageNumber);//Прототип функции голосовых сообщений
void Title();
