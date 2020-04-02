#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

char tablero[3][3][2];
int bot, Victoria;

int main()
{
    srand(time(NULL));
    char respuesta[3];
    int x=0, y=0, posicion=0;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
           strcpy(tablero[x][y]," ");
        }
    }
    while(1)
    {
      MostrarTablero();
    do
    {
        do
        {
        printf("Elija un lugar donde ingresar la X\n");
        scanf("%d",&posicion);
        }while(antirellenar(posicion));

    }while(jugadaX(posicion));
    system("cls");
    printf("Quiere seguir ingresando X?\n");
    scanf("%s",&respuesta);
    system("cls");
    if(strcmp(respuesta,"no")==0 || strcmp(respuesta,"NO")==0)
    {
        break;
    }
    }
    VictoriaJugador();
    while(1)
    {
        MostrarTablero();
    do
    {
        do
        {
        printf("Elija un lugar donde ingresar la O\n");
        scanf("%d",&posicion);
        }while(antirellenar(posicion));
    }while(jugadaO(posicion));
    system("cls");
    printf("Quiere seguir ingresando O?\n");
    scanf("%s",&respuesta);
    system("cls");
    if(strcmp(respuesta,"no")==0 || strcmp(respuesta,"NO")==0)
    {
        break;
    }
    } 
    // Aca llame a todas las funciones para que funcione el juego
    AtaqueMaquina();
    DefenderMaquina();
    RandomMaquina();
    VictoriaMaquina();
    MostrarTablero();
    return 0;
}
int jugadaX(int posicion) // Esta funcion sirve para que pueda verificar que la X este en un lugar valido
{
    if (posicion>=4 && posicion<7)
       {
           strcpy(tablero[1][posicion-4],"X");
           return 0;
       }
       if(posicion>=7 && posicion<=9)
       {
           strcpy(tablero[2][posicion-7],"X");
           return 0;
        }
       if(posicion<4 && posicion>0)
       {
           strcpy(tablero[0][posicion-1],"X");
           return 0;
        }
    printf("ERROR, Ingrese un valor valido\n");
    return 1;
}

int jugadaO(int posicion) // Esta funcion sirve para que pueda verificar que la O este en un lugar valido
{
    int fila=0, columna=0;
       if (posicion>=4 && posicion<7)
       {
           strcpy(tablero[1][posicion-4],"O");
           return 0;
       }
       if(posicion>=7 && posicion<=9)
       {
           strcpy(tablero[2][posicion-7],"O");
           return 0;
       }
       if(posicion<4 && posicion>0)
       {
           strcpy(tablero[0][posicion-1],"O");
           return 0;
       }
    printf("ERROR, Ingrese un valor valido\n");
    return 1;
}

int antirellenar(int posicion) // Esta funcion sirve para mostrar el tablero vacio
{
      if (posicion>=4 && posicion<7)
       {
           if(strcmp(tablero[1][posicion-4]," ")==0)
           {
               return 0;
           }
       }
       if(posicion>=7 && posicion<=9)
       {
           if(strcmp(tablero[2][posicion-7]," ")==0)
           {
               return 0;
           }
        }
       if(posicion<4 && posicion>0)
       {
           if(strcmp(tablero[0][posicion-1]," ")==0)
           {
               return 0;
           }
        }
    printf("ERROR, Ingrese un lugar que no este ocupado\n");
    return 1;
}

int AtaqueMaquina() // Esta funcion muestra las posibles victorias de la maquina
{
    int x=0;
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][0],"O")==0 && strcmp(tablero[x][1],"O")==0)
        {
            strcpy(tablero[x][2],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][2],"O")==0 && strcmp(tablero[x][1],"O")==0)
        {
            strcpy(tablero[x][0],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][0],"O")==0 && strcmp(tablero[x][2],"O")==0)
        {
            strcpy(tablero[x][1],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[0][x],"O")==0 && strcmp(tablero[1][x],"O")==0)
        {
            strcpy(tablero[2][x],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[2][x],"O")==0 && strcmp(tablero[1][x],"O")==0)
        {
            strcpy(tablero[0][x],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[0][x],"O")==0 && strcmp(tablero[2][x],"O")==0)
        {
            strcpy(tablero[1][x],"O");
        }
    }
    if(strcmp(tablero[0][0],"O")==0 && strcmp(tablero[1][1],"O")==0)
    {
        strcpy(tablero[2][2],"O");
    }
    if(strcmp(tablero[1][1],"O")==0 && strcmp(tablero[2][2],"O")==0)
    {
        strcpy(tablero[0][0],"O");
    }
    if(strcmp(tablero[2][2],"O")==0 && strcmp(tablero[2][2],"O")==0)
    {
        strcpy(tablero[1][1],"O");
    }
    if(strcmp(tablero[0][2],"O")==0 && strcmp(tablero[1][1],"O")==0)
    {
        strcpy(tablero[2][0],"O");
    }
    if(strcmp(tablero[1][1],"O")==0 && strcmp(tablero[2][0],"O")==0)
    {
        strcpy(tablero[0][2],"O");
    }
    if(strcmp(tablero[2][0],"O")==0 && strcmp(tablero[0][2],"O")==0)
    {
        strcpy(tablero[1][1],"O");
    }
}

int DefenderMaquina() // Funcion para que cuando se le de la oportunidad a la maquina que bloquee
{
    int x=0;
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][0],"X")==0 && strcmp(tablero[x][1],"X")==0)
        {
            strcpy(tablero[x][2],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][2],"X")==0 && strcmp(tablero[x][1],"X")==0)
        {
            strcpy(tablero[x][0],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[x][0],"X")==0 && strcmp(tablero[x][2],"X")==0)
        {
            strcpy(tablero[x][1],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[0][x],"X")==0 && strcmp(tablero[1][x],"X")==0)
        {
            strcpy(tablero[2][x],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[2][x],"X")==0 && strcmp(tablero[1][x],"X")==0)
        {
            strcpy(tablero[0][x],"O");
        }
    }
    for(x=0;x<3;x++)
    {
        if(strcmp(tablero[0][x],"X")==0 && strcmp(tablero[2][x],"X")==0)
        {
            strcpy(tablero[1][x],"O");
        }
    }
    if(strcmp(tablero[0][0],"X")==0 && strcmp(tablero[1][1],"X")==0)
    {
        strcpy(tablero[2][2],"O");
    }
    if(strcmp(tablero[1][1],"X")==0 && strcmp(tablero[2][2],"X")==0)
    {
        strcpy(tablero[0][0],"O");
    }
    if(strcmp(tablero[2][2],"X")==0 && strcmp(tablero[2][2],"X")==0)
    {
        strcpy(tablero[1][1],"O");
    }
    if(strcmp(tablero[0][2],"X")==0 && strcmp(tablero[1][1],"X")==0)
    {
        strcpy(tablero[2][0],"O");
    }
    if(strcmp(tablero[1][1],"X")==0 && strcmp(tablero[2][0],"X")==0)
    {
        strcpy(tablero[0][2],"O");
    }
    if(strcmp(tablero[2][0],"X")==0 && strcmp(tablero[0][2],"X")==0)
    {
        strcpy(tablero[1][1],"O");
    }
}

int RandomMaquina() // Esta funcion sirve para que el bot tire un numero random en cualquiera de las 9 posiciones del tablero
{
    bot=rand()% (9-1+1)+1;
}

int MostrarTablero() // En esta funcion muestra el tablero default
{
    printf("  %s   %c   %s   %c   %s\n",tablero[0][0],179,tablero[0][1],179,tablero[0][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s\n",tablero[1][0],179,tablero[1][1],179,tablero[1][2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,197,196,196,196,196,196,196,196,197,196,196,196,196,196,196);
    printf("  %s   %c   %s   %c   %s\n",tablero[2][0],179,tablero[2][1],179,tablero[2][2]);
}

int VictoriaJugador() // Aca es la funcion donde se verifica la victoria del jugador 1
{
    if(strcmp(tablero[0][0],tablero[0][1])==0 && strcmp(tablero[0][1],tablero[0][2])==0)
          {
              if(strcmp(tablero[0][0],"X")==0 && strcmp(tablero[0][1],"X")==0 && strcmp(tablero[0][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[1][0],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[1][2])==0)
          {
              if(strcmp(tablero[1][0],"X")==0 && strcmp(tablero[1][1],"X")==0 && strcmp(tablero[1][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[2][0],tablero[2][1])==0 && strcmp(tablero[2][1],tablero[2][2])==0)
          {
              if(strcmp(tablero[2][0],"X")==0 && strcmp(tablero[2][1],"X")==0 && strcmp(tablero[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][0],tablero[1][0])==0 && strcmp(tablero[1][0],tablero[2][0])==0)
          {
              if(strcmp(tablero[0][0],"X")==0 && strcmp(tablero[1][0],"X")==0 && strcmp(tablero[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][1],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][1])==0)
          {
              if(strcmp(tablero[0][1],"X")==0 && strcmp(tablero[1][1],"X")==0 && strcmp(tablero[2][1],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][2],tablero[1][2])==0 && strcmp(tablero[1][2],tablero[2][2])==0)
          {
              if(strcmp(tablero[0][2],"X")==0 && strcmp(tablero[1][2],"X")==0 && strcmp(tablero[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][0],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][2])==0)
          {
              if(strcmp(tablero[0][0],"X")==0 && strcmp(tablero[1][1],"X")==0 && strcmp(tablero[2][2],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][2],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][0])==0)
          {
              if(strcmp(tablero[0][2],"X")==0 && strcmp(tablero[1][1],"X")==0 && strcmp(tablero[2][0],"X")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó Jugador 1!!\n");
                  Victoria=1;
              }
          }
          return 0;
}

int VictoriaMaquina() // Esta funcion sirve para que verifique si la maquina gano
{
    if(strcmp(tablero[0][0],tablero[0][1])==0 && strcmp(tablero[0][1],tablero[0][2])==0)
          {
              if(strcmp(tablero[0][0],"O")==0 && strcmp(tablero[0][1],"O")==0 && strcmp(tablero[0][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[1][0],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[1][2])==0)
          {
              if(strcmp(tablero[1][0],"O")==0 && strcmp(tablero[1][1],"O")==0 && strcmp(tablero[1][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[2][0],tablero[2][1])==0 && strcmp(tablero[2][1],tablero[2][2])==0)
          {
              if(strcmp(tablero[2][0],"O")==0 && strcmp(tablero[2][1],"O")==0 && strcmp(tablero[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][0],tablero[1][0])==0 && strcmp(tablero[1][0],tablero[2][0])==0)
          {
              if(strcmp(tablero[0][0],"O")==0 && strcmp(tablero[1][0],"O")==0 && strcmp(tablero[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][1],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][1])==0)
          {
              if(strcmp(tablero[0][1],"O")==0 && strcmp(tablero[1][1],"O")==0 && strcmp(tablero[2][1],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][2],tablero[1][2])==0 && strcmp(tablero[1][2],tablero[2][2])==0)
          {
              if(strcmp(tablero[0][2],"O")==0 && strcmp(tablero[1][2],"O")==0 && strcmp(tablero[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][0],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][2])==0)
          {
              if(strcmp(tablero[0][0],"O")==0 && strcmp(tablero[1][1],"O")==0 && strcmp(tablero[2][2],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          if(strcmp(tablero[0][2],tablero[1][1])==0 && strcmp(tablero[1][1],tablero[2][0])==0)
          {
              if(strcmp(tablero[0][2],"O")==0 && strcmp(tablero[1][1],"O")==0 && strcmp(tablero[2][0],"O")==0)
              {
                  gotoxy(1,13);
                  printf("Ganó la Maquina\n");
                  Victoria=1;
              }
          }
          return 0;
}
