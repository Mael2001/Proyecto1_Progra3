#ifndef __GAME_H__
#define __GAME_H__
#include "TextConsole.h"

class MyGame : public CClient
{
public:
    MyGame(TextConsole &con) : CClient(con) {}

    void run() override;

    int gemas [22][30];
    int Puntaje = 0;
    int Turnos = 40;
    int remplazo1,remplazo2,remplazo3;

private:
    void seleccion(int Row, int Col);
    void Final();
    void combo (int row, int col);
    void printing();
};

#endif