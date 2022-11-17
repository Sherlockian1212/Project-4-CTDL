#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum IN {
    // 13 is ASCII for carriage
    // return
    IN_BACK = 8,
    IN_RET = 13
};
const short cntHidePassword = 25;

void box(short x, short y, short w, short h, string text, bool lTop);
void gotoxy(short x, short y);
void takeInput(string& str, char inp, bool isPassword, short maxLengthShow = 20);