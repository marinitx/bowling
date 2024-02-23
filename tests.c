#include "bowling.h"

//TODO PLENOS
void all_strikes(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    while (i < NUM_ROUNDS - 1) 
    {
        pinsknocked[i][0] = 10;
        pinsknocked[i][1] = 0;  
        pinsknocked[i][2] = 0;
        i++;
    }
    pinsknocked[NUM_ROUNDS - 1][0] = 10;
    pinsknocked[NUM_ROUNDS - 1][1] = 10;
    pinsknocked[NUM_ROUNDS - 1][2] = 10;
}

//TODO FALLOS O CEROS
void all_loses(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    while (i < NUM_ROUNDS) 
    {
        pinsknocked[i][0] = 0;
        pinsknocked[i][1] = 0;
        pinsknocked[i][2] = 0;
        i++;
    }
}

//SIEMPRE TIRA 1 BOLO
void always_one(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    while (i < NUM_ROUNDS) 
    {
        pinsknocked[i][0] = 1;
        pinsknocked[i][1] = 1;
        pinsknocked[i][2] = 0;
        i++;
    }
}

// TIRA 3 BOLOS EN 10 LANZAMIENTOS Y 0 BOLOS EN OTROS 10 LANZAMIENTOS
void ten_times_three(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    while (i < 5) 
    {
        pinsknocked[i][0] = 3;
        pinsknocked[i][1] = 3;  
        pinsknocked[i][2] = 0;
        i++;
    }
    while (i < NUM_ROUNDS)
    {
        pinsknocked[i][0] = 0;
        pinsknocked[i][1] = 0;  
        pinsknocked[i][2] = 0;
        i++;
    }
}

//JUGADA ALEATORIA PREDEFINIDA
void random_rolls(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    pinsknocked[0][0] = 10;
    pinsknocked[0][1] = 0;
    pinsknocked[0][2] = 0;
    pinsknocked[1][0] = 10;
    pinsknocked[1][1] = 0;
    pinsknocked[1][2] = 0;
    pinsknocked[2][0] = 10;
    pinsknocked[2][1] = 0;
    pinsknocked[2][2] = 0;
    pinsknocked[3][0] = 7;
    pinsknocked[3][1] = 2;
    pinsknocked[3][2] = 0;
    pinsknocked[4][0] = 8;
    pinsknocked[4][1] = 2;
    pinsknocked[4][2] = 0;
    pinsknocked[5][0] = 0;
    pinsknocked[5][1] = 9;
    pinsknocked[5][2] = 0;
    pinsknocked[6][0] = 10;
    pinsknocked[6][1] = 0;
    pinsknocked[6][2] = 0;
    pinsknocked[7][0] = 7;
    pinsknocked[7][1] = 3;
    pinsknocked[7][2] = 0;
    pinsknocked[8][0] = 9;
    pinsknocked[8][1] = 0;
    pinsknocked[8][2] = 0;
    pinsknocked[9][0] = 10;
    pinsknocked[9][1] = 10;
    pinsknocked[9][2] = 8;
}

void last_spare(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    while (i < (NUM_ROUNDS - 1)) 
    {
        pinsknocked[i][0] = 0;
        pinsknocked[i][1] = 0;  
        pinsknocked[i][2] = 0;
        i++;
    }
    while (i == (NUM_ROUNDS - 1))
    {
        pinsknocked[i][0] = 5;
        pinsknocked[i][1] = 5;  
        pinsknocked[i][2] = 1;
        i++;
    }
}