#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

#define NUM_ROUNDS 10

void input_rounds(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0;

    printf("Por favor ingresa el número de bolos tirados en cada ronda:\n");

    // Entrada de datos de rondas 1 a 9
    while (i < NUM_ROUNDS - 1) 
    {
        printf("Ronda %d, lanzamiento 1: ", i + 1);
        while (scanf("%d", &pinsknocked[i][0]) != 1 || pinsknocked[i][0] < 0 || pinsknocked[i][0] > 10) 
        {
            printf("Por favor ingresa un número válido entre 0 y 10: ");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
        // PLENO
        if (pinsknocked[i][0] == 10)
            pinsknocked[i][1] = 0; // Si hay pleno en el primer lanzamiento, el segundo lanzamiento debe ser 0
        else 
        {
            printf("Ronda %d, lanzamiento 2: ", i + 1);
            while (scanf("%d", &pinsknocked[i][1]) != 1 || pinsknocked[i][1] < 0 || pinsknocked[i][1] > (10 - pinsknocked[i][0])) 
            {
                printf("Por favor ingresa un número válido entre 0 y %d: ", 10 - pinsknocked[i][0]);
                while(getchar() != '\n');
            }
            pinsknocked[i][2] = 0; // En otras rondas, la tercera tirada se inicializa a 0
        }
        i++;
    }
    

    // Ronda 10
    printf("Ronda %d, lanzamiento 1: ", NUM_ROUNDS);
    while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][0]) != 1 || pinsknocked[NUM_ROUNDS - 1][0] < 0 || pinsknocked[NUM_ROUNDS - 1][0] > 10) //Error para números negativos o mayores a 10
    {
        printf("Por favor ingresa un número válido entre 0 y 10: ");
        while(getchar() != '\n');
    }

    // PLENO en el primer lanzamiento de la ronda 10
    if (pinsknocked[NUM_ROUNDS - 1][0] == 10) 
    {
        printf("Ronda %d, lanzamiento 2: ", NUM_ROUNDS);
        while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][1]) != 1 || pinsknocked[NUM_ROUNDS - 1][1] < 0 || pinsknocked[NUM_ROUNDS - 1][1] > 10)
        {
            printf("Por favor ingresa un número válido entre 0 y 10: ");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
        printf("Ronda %d, lanzamiento 3: ", NUM_ROUNDS);
        while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][2]) != 1 || pinsknocked[NUM_ROUNDS - 1][2] < 0 || pinsknocked[NUM_ROUNDS - 1][2] > 10)
        {
            printf("Por favor ingresa un número válido entre 0 y 10: ");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
    }
    else
    { // No PLENO en el primer lanzamiento de la ronda 10
        printf("Ronda %d, lanzamiento 2: ", NUM_ROUNDS);
        while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][1]) != 1 || pinsknocked[NUM_ROUNDS - 1][1] < 0 || pinsknocked[NUM_ROUNDS - 1][1] > (10 - pinsknocked[NUM_ROUNDS - 1][0])) //Error negativos y mayores a los bolos restantes
        {
            printf("Por favor ingresa un número válido entre 0 y %d: ", 10 - pinsknocked[NUM_ROUNDS - 1][0]);
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
        
    }
}

//Función de cálculo de puntuaciones
int calculate_score(int pinsknocked[NUM_ROUNDS][3])
{
    int score = 0;
    int round = 0;

    // para rondas de 0 a 8 (1 a 9)
    while (round < NUM_ROUNDS - 1)
    {
        // PLENO
        if (pinsknocked[round][0] == 10) 
        {
            score += 10;
            if (pinsknocked[round + 1][0] == 10) // Si hay otro pleno en la siguiente ronda
            {
                if (round == NUM_ROUNDS - 2) //en el caso del round 8 (ronda 9) se iría fuera del array, asi que tengo que mirar el lanzamiento y no la ronda
                    score += 10 + pinsknocked[round + 1][1];
                else
                    score += 10 + pinsknocked[round + 2][0]; // Suma 10 más el primer lanzamiento de la siguiente ronda
            }
            else //Si no hay doble pleno
                score += pinsknocked[round + 1][0] + pinsknocked[round + 1][1]; // Suma los dos lanzamientos de la siguiente ronda
        }
        // SEMIPLENO
        else if (pinsknocked[round][0] + pinsknocked[round][1] == 10) 
            score += 10 + pinsknocked[round + 1][0]; // Suma el primer lanzamiento de la siguiente ronda
        // NI PLENO NI SEMIPLENO
        else
            score += pinsknocked[round][0] + pinsknocked[round][1]; // Suma el primer y el segundo lanzamiento
        round++;
        printf("Ronda %d: %d puntos\n", round, score);
    }

    //ROUND 9 and 8 = RONDA 10 y 9
    while (round == NUM_ROUNDS - 1 || round == NUM_ROUNDS - 2)
    {
        // PLENO
        if (pinsknocked[round][0] == 10) 
            score += 10 + pinsknocked[round][1] + pinsknocked[round][2];
        // SEMIPLENO
        else if (pinsknocked[round][0] + pinsknocked[round][1] == 10) 
            score += 10 + pinsknocked[round][2];
        // NI PLENO NI SEMIPLENO
        else
            score += pinsknocked[round][0] + pinsknocked[round][1]; // Suma el primer y el segundo lanzamiento
        round++;
        printf("Ronda 10: %d puntos\n", score);
    }
    return (score);
}

int main()
{
    int pinsknocked[NUM_ROUNDS][3];
    int score;
    int choice;
    int testnum;

    printf("¿Prefieres utilizar tests predefinidos (1) o elegir tus propias tiradas (2)?\n ");
    while (scanf("%d", &choice) != 1 || choice != 1 && choice != 2) //Dos opciones o 1 o 2
        {
            printf("Elección no válida, ingresa '1' o '2': ");
            while(getchar() != '\n');
        }
    if (choice == 1) //si elige 1 elige tests predefinidos del archivo tests.c
    {
        printf("Introduce el número de test: \n1. Todo plenos\n2.Todo 0\n3.Todo 1\n4.Diez veces 3\n5.Jugada aleatoria\n");
        while (scanf("%d", &testnum) != 1 || testnum < 1 || testnum > 5) 
        {
            printf("Ingresa un número del 1 al 5");
            while(getchar() != '\n');
        }
        if (testnum == 1) // todo plenos
            all_strikes(pinsknocked);
        if (testnum == 2) // todo fallos o ceros
            all_loses(pinsknocked);
        if (testnum == 3) // todo 1 bolo tirado
            always_one(pinsknocked);
        if (testnum == 4) // diez lanzamientos tirando 3, 10 lanzamientos tirando 0
            ten_times_three(pinsknocked);
        if (testnum == 5) // jugada aleatoria predefinida en tests.c
            random_rolls(pinsknocked);
    }
    else
        input_rounds(pinsknocked); // dejarle al usuario poner los lanzamientos que quiera
    score = calculate_score(pinsknocked);
    printf("\nResultado total: %d puntos.\n", score); // AÑADIR AQUÍ LA TABLA DE PUNTUACIONES
    return (0);
}