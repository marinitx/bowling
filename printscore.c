#include "bowling.h"

//Esta función imprime las rondas y las puntuaciones individuales
void printscore(int score1, int score2, int round) 
{
    printf("   %d  |", round + 1);
    if (score2 == -1 && score1 == 10) //pleno con el '-1' de prueba
    {
        if (round != 9) //ultima ronda
            printf("  %c  |", 'X');
    }
    else if ((score1 + score2) == 10) //semipleno
    {
        if (round != 9)
            printf("  %d %c |", score1, '/');
        else
            printf("  %d %c", score1, '/'); //en la última ronda quiero que no me imprima la columna porque tengo otro 3 lanzamiento que imprimiré justo al lado
    }
    else
        printf("  %d %d |", score1, score2);
}