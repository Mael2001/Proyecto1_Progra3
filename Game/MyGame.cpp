#include "MyGame.h"
#include <iostream>
using namespace std;
int x, y{0};
void MyGame::Menu(int num)
{
    con.setForecolor(CColor::White);
    con.setCursor(10, 35);
    con << "BEJEWELED";
    con.setCursor(11, 20);
    con << "Presione Cualquier Tecla Para empezar a Jugar";
    con.setCursor(12, 20);
    con << "Presione Esc Para Salir";
    con.refresh();
    if (num == 0)
    {
        cout<<"\n\n\n\n\n\n\n\n";
        seleccion(0, 0);
        con.clearScreen();
        printing();
    }
    else
    {
        int iRand = (rand() % 9) + 1;
        for (int x = 0; x < 15; x++)
        {
            for (size_t i = 0; i < 30; i++)
            {
                gemas[x][i] = iRand;
                iRand = (rand() % 9) + 1;
            }
        }
    }
}
void MyGame::printing()
{
    con.setCursor(0, 0);
    con.setBackcolor(CColor::Black);
    con.setForecolor(CColor::White);
    for (int x = 0; x < 15; x++)
    {
        for (int i = 0; i < 30; i++)
        {
            cout << "[" << gemas[x][i] << "]";
            switch (gemas[x][i])
            {
            case 1:
            case 2:
                gemas[x][i] = 2;
                con << "\x1";
                con << "\x2";
                break;

            case 3:
            case 4:
                gemas[x][i] = 4;
                con << "\x3";
                con << "\x4";
                break;

            case 5:
            case 6:
                gemas[x][i] = 6;
                con << "\x5";
                con << "\x6";
                break;

            case 7:
            case 8:
            default:
                gemas[x][i] = 8;
                con << "\x7";
                con << "\x8";
                break;
            }
        }
        cout << "\n";
        con << "\n";
        con.delayMs(100);
    }
    con.setCursor(2, 65);
    con << "Turnos:";
    con.setCursor(3, 65);
    con << Turnos;
    con << " de 90";
    con.setCursor(4, 65);
    con << "Puntaje: ";
    con.setCursor(5, 65);
    con << Puntaje;
    con << " de 200";
    con.setCursor(6, 62);
    con << "CopyRight Progra 3";
    con.refresh();
    con.delayMs(1000);
}
void MyGame::Final()
{
    con.setCursor(8, 30);
    con.setForecolor(CColor::White);
    con << "Fin Del Juego";
    con.setCursor(12, 25);
    con << "Tu Puntuaje Fue: " << Puntaje << "/"
        << "200";
    con.setCursor(15, 29);
    if (Puntaje >= 200)
    {
        con << "GANASTE";
    }
    else
    {
        con << "Perdiste :v";
    }
    con.refresh();
    con.delayMs(20000);
    exit(0);
}
void MyGame::combo(int row, int col)
{
    if (Turnos <= 0)
    {
        Final();
        return;
    }
    Turnos--;
    if (gemas[row][col] == gemas[row][col + 1] == gemas[row][col + 2])
    {
        Puntaje += 20;
        for (size_t i = row; i != -1; i--)
        {
            if (i = 0)
            {
                gemas[i][col] = 2;
                gemas[i][col + 1] = 2;
                gemas[i][col + 2] = 2;
            }
            remplazo1 = gemas[i - 1][col];
            remplazo2 = gemas[i - 1][col + 1];
            remplazo3 = gemas[i - 1][col + 2];
            gemas[i][col] = remplazo1;
            gemas[i][col + 1] = remplazo2;
            gemas[i][col + 2] = remplazo3;
        }
    }
    else if (gemas[row][col] == gemas[row][col - 1] == gemas[row][col - 2])
    {
        Puntaje += 20;
        for (size_t i = row; i != 0; i--)
        {
            if (i = 0)
            {
                gemas[0][col] = 4;
                gemas[0][col - 1] = 2;
                gemas[0][col - 2] = 6;
            }
            remplazo1 = gemas[i - 1][col];
            remplazo2 = gemas[i - 1][col - 1];
            remplazo3 = gemas[i - 1][col - 2];
            gemas[i][col] = remplazo1;
            gemas[i][col - 1] = remplazo2;
            gemas[i][col - 2] = remplazo3;
        }
    }
    else if (gemas[row][col] == gemas[row][col - 1] == gemas[row][col + 1])
    {
        Puntaje += 20;
        for (size_t i = row; i != -1; i--)
        {
            if (i = 0)
            {
                gemas[0][col] = 6;
                gemas[0][col - 1] = 6;
                gemas[0][col - 2] = 6;
            }
            remplazo1 = gemas[i - 1][col];
            remplazo2 = gemas[i - 1][col + 1];
            remplazo3 = gemas[i - 1][col - 1];
            gemas[i][col] = remplazo1;
            gemas[i][col + 1] = remplazo2;
            gemas[i][col - 1] = remplazo3;
        }
    }
    else if (gemas[row][col] == gemas[row - 1][col] == gemas[row + 1][col])
    {
        Puntaje += 20;
    }
    else if (gemas[row][col] == gemas[row - 1][col] == gemas[row - 2][col])
    {
        Puntaje += 20;
    }
    else if (gemas[row][col] == gemas[row + 1][col] == gemas[row + 2][col])
    {
        Puntaje += 20;
    }
    printing();
    seleccion(x, y);
}
void MyGame::seleccion(int Row, int Col)
{
    con.setForecolor(CColor::Red1);
    con.setCursor(Row, Col);
    switch (gemas[Row][Col])
    {
    case 1:
    case 2:
        con << "\x1";
        con << "\x2";
        break;

    case 3:
    case 4:
        con << "\x3";
        con << "\x4";
        break;

    case 5:
    case 6:
        con << "\x5";
        con << "\x6";
        break;

    case 7:
    case 8:
    default:
        con << "\x7";
        con << "\x8";
    }
};

void MyGame::run()
{
    Menu(1);
    con.setForecolor(CColor::White);
    /**/
    while (con.isActive())
    {
        uint32_t key = con.getKey();
        if (key != SDLK_UNKNOWN)
        {
            Menu(0);
            switch (key)
            {
            case SDLK_ESCAPE:
                exit(0);
                break;
            case SDLK_LEFT:
                if (x != 0)
                {
                    Turnos--;
                    x -= 2;
                    seleccion(y, x);
                }
                break;
            case SDLK_RIGHT:
                if (x != 58)
                {
                    Turnos--;
                    x += 2;
                    seleccion(y, x);
                }
                break;
            case SDLK_UP:
                if (y != 0)
                {
                    Turnos--;
                    y -= 1;
                    seleccion(y, x);
                }
                break;
            case SDLK_DOWN:
                if (y != 15)
                {
                    Turnos--;
                    y += 1;
                    seleccion(y, x);
                }
                break;
            case SDLK_RETURN:
                combo(y, x);
                break;
            default:
                seleccion(y, x);
                break;
            }
            con.refresh();
        }
    }
}