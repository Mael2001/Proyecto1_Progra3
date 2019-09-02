#include "MyGame.h"

void MyGame::printing(){
    con.clearScreen();
    con.setCursor(0,0);
    con.setBackcolor(CColor::Black);
    con.setForecolor(CColor::White);
    for (int x = 0; x < 22; x++)
    {
        for (int i = 0; i < 30; i++)
        {
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
        con << "\n";
    }
    con.setCursor(60,10);
    con<<"Turnos:";
    con.setCursor(60,15);
    con<<Turnos;
    con<<"de 40";
    con.setCursor(60,20);
    con<<"Puntaje: ";
    con.setCursor(60,25);
    con<<Puntaje;
    con<<"de 200";
    con.refresh();
     
}
void MyGame::Final(){
    con.clearScreen();
    con.setCursor(40,20);
    con.setBackcolor(CColor::White);
    con.setForecolor(CColor::Black);
    con<<"Fin Del Juego";
    con.setCursor(45,20);
    con<<"Tu Puntuaje Fue: "<<Puntaje<<"/"<<"200";
    con.setCursor(60,20);
    if(Puntaje>=200){
        con<<"GANASTE";
    }else{
        con<<"Perdiste :v";
    }
}
void MyGame::combo(int row,int col){
    if(Turnos<=0){
        Final();
        return;
    }
    Turnos--;
    if(gemas[row][col]==gemas[row][col+1]==gemas[row][col+2]){
        Puntaje+=20;
        for (size_t i = row; i !=-1; i--)
        {   if(i=0){
            gemas[i][col]=2;  
            gemas[i][col+1]=2; 
            gemas[i][col+2]=2;
        }
            remplazo1=gemas[i-1][col];
            remplazo2=gemas[i-1][col+1];
            remplazo3=gemas[i-1][col+2]; 
            gemas[i][col]=remplazo1;  
            gemas[i][col+1]=remplazo2; 
            gemas[i][col+2]=remplazo3; 
        }
    }else if(gemas[row][col]==gemas[row][col-1]==gemas[row][col-2]){
        Puntaje+=20;
        for (size_t i = row; i !=0; i--)
        {
            if(i=0){
            gemas[0][col]=4;  
            gemas[0][col-1]=2; 
            gemas[0][col-2]=6;
        }
            remplazo1=gemas[i-1][col];
            remplazo2=gemas[i-1][col-1];
            remplazo3=gemas[i-1][col-2]; 
            gemas[i][col]=remplazo1;  
            gemas[i][col-1]=remplazo2; 
            gemas[i][col-2]=remplazo3; 
        }
    }else if(gemas[row][col]==gemas[row][col-1]==gemas[row][col+1]){
        Puntaje+=20;
        for (size_t i = row; i !=-1; i--)
        {
            if(i=0){
            gemas[0][col]=6;  
            gemas[0][col-1]=6; 
            gemas[0][col-2]=6;
        }
            remplazo1=gemas[i-1][col];
            remplazo2=gemas[i-1][col+1];
            remplazo3=gemas[i-1][col-1]; 
            gemas[i][col]=remplazo1;  
            gemas[i][col+1]=remplazo2; 
            gemas[i][col-1]=remplazo3; 
        }
    }else if(gemas[row][col]==gemas[row-1][col]==gemas[row+1][col]){
        Puntaje+=20;
    }else if(gemas[row][col]==gemas[row-1][col]==gemas[row-2][col]){
        Puntaje+=20;
    }else if(gemas[row][col]==gemas[row+1][col]==gemas[row+2][col]){
        Puntaje+=20;
    }
    printing();
}
void MyGame::seleccion(int Row, int Col)
{
    printing();
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
    con.setBackcolor(CColor::Black);
    con.setForecolor(CColor::White);
    int iRand = (rand() % 9) + 1;
    for (int x = 0; x < 22; x++)
    {
        for (size_t i = 0; i < 30; i++)
        {
            gemas[x][i] = iRand;
            iRand = (rand() % 9) + 1;
        }
    }
    printing();
    int x = 0, y = 0;
    seleccion(y, x);
    while (con.isActive())
    {
        uint32_t key = con.getKey();
        if (key != SDLK_UNKNOWN)
        {
            switch (key)
            {
            case SDLK_LEFT:
                if (x != 0)
                {
                    Turnos--;
                    con.refresh();
                    x -= 2;
                    seleccion(y, x);
                }
                break;
            case SDLK_RIGHT:
                if (x != 58)
                {
                    Turnos--;
                    con.refresh();
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
                if (y != 18)
                {
                    Turnos--;
                    y += 1;
                    seleccion(y, x);
                }
                break;
            case SDLK_KP_ENTER:
                con.refresh();
                combo(y,x);
                break;
            default:
                con << "No Soportado";
            }
            con.refresh();
        }
    }
}