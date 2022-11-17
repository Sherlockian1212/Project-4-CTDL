#include "Display.h"

void gotoxy(short x, short y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

void box(short x, short y, short w = 20, short h = 1, string text = "text", bool lTop = false) {
    if (x < 0 || y < 0) return;
    for (short i = x + 1; i <= x + w - 1; i++) {
        gotoxy(i, y);
        cout << char(196);
        gotoxy(i, y + h + 1);
        cout << char(196);
    }
    for (short i = y + 1; i <= y + h; i++) {
        gotoxy(x, i);
        cout << char(179);
        gotoxy(x + w, i);
        cout << char(179);
    }
    gotoxy(x, y);
    if (!lTop) cout << char(218);
    else cout << char(195);
    gotoxy(x + w, y);
    if (!lTop) cout << char(191);
    else cout << char(180);
    gotoxy(x, y + h + 1); cout << char(192);
    gotoxy(x + w, y + h + 1); cout << char(217);

    gotoxy(x + 1, y + 1); cout << text;
}

void takeInput(string &str, char inp, bool isPassword, short maxLengthShow)
{
    if (inp == IN::IN_RET || inp == '\t') return;
    short length = str.length();
    if (inp == IN::IN_BACK && length > 0) {
        str.pop_back();
        if (length <= maxLengthShow)
            cout << "\b \b";
        return;
    }
    else if (inp == IN::IN_BACK && str.length() == 0) return;
    str.push_back(inp);
    if (length < maxLengthShow) {
        if (isPassword) cout << "*";
        else cout << inp;
    }
}