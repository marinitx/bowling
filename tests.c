#include <stdio.h>
#include "bowling.h" // Incluir el archivo de cabecera del programa principal

void all_strikes(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    // Llenar automáticamente los valores con plenos en cada lanzamiento usando un bucle while
    while (i < NUM_ROUNDS - 1) {
        pinsknocked[i][0] = 10; // Primer lanzamiento
        pinsknocked[i][1] = 0;  // Segundo lanzamiento
        pinsknocked[i][2] = 0;  // Tercer lanzamiento (si es necesario)
        i++; // Incrementar el índice
    }
    pinsknocked[NUM_ROUNDS - 1][0] = 10;
    pinsknocked[NUM_ROUNDS - 1][1] = 10;
    pinsknocked[NUM_ROUNDS - 1][2] = 10;
}

void all_loses(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    // Llenar automáticamente los valores con plenos en cada lanzamiento usando un bucle while
    while (i < NUM_ROUNDS) {
        pinsknocked[i][0] = 0; // Primer lanzamiento
        pinsknocked[i][1] = 0;  // Segundo lanzamiento
        pinsknocked[i][2] = 0;  // Tercer lanzamiento (si es necesario)
        i++; // Incrementar el índice
    }
}

void always_one(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    // Llenar automáticamente los valores con plenos en cada lanzamiento usando un bucle while
    while (i < NUM_ROUNDS) {
        pinsknocked[i][0] = 1; // Primer lanzamiento
        pinsknocked[i][1] = 1;  // Segundo lanzamiento
        pinsknocked[i][2] = 0;  // Tercer lanzamiento (si es necesario)
        i++; // Incrementar el índice
    }
}

void ten_times_three(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    // Llenar automáticamente los valores con plenos en cada lanzamiento usando un bucle while
    while (i < 5) {
        pinsknocked[i][0] = 3; // Primer lanzamiento
        pinsknocked[i][1] = 3;  // Segundo lanzamiento
        pinsknocked[i][2] = 0;  // Tercer lanzamiento (si es necesario)
        i++; // Incrementar el índice
    }
    while (i < NUM_ROUNDS)
    {
        pinsknocked[i][0] = 0; // Primer lanzamiento
        pinsknocked[i][1] = 0;  // Segundo lanzamiento
        pinsknocked[i][2] = 0;  // Tercer lanzamiento (si es necesario)
        i++;
    }
}

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