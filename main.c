#include <stdio.h>
#include <stdlib.h>
#include "bowling.h"

#define NUM_ROUNDS 10

void input_rounds(int pinsknocked[NUM_ROUNDS][3])
{
    int i = 0; // Inicializamos el contador de rondas

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
                while(getchar() != '\n'); // Limpiar el buffer de entrada
            }
            pinsknocked[i][2] = 0; // En otras rondas, la tercera tirada se inicializa a 0
        }
        i++; // Incrementamos el contador de rondas
    }
    

    // Ronda 10
    printf("Ronda %d, lanzamiento 1: ", NUM_ROUNDS);
    while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][0]) != 1 || pinsknocked[NUM_ROUNDS - 1][0] < 0 || pinsknocked[NUM_ROUNDS - 1][0] > 10) 
    {
        printf("Por favor ingresa un número válido entre 0 y 10: ");
        while(getchar() != '\n'); // Limpiar el buffer de entrada
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
        while (scanf("%d", &pinsknocked[NUM_ROUNDS - 1][1]) != 1 || pinsknocked[NUM_ROUNDS - 1][1] < 0 || pinsknocked[NUM_ROUNDS - 1][1] > (10 - pinsknocked[NUM_ROUNDS - 1][0]))
        {
            printf("Por favor ingresa un número válido entre 0 y %d: ", 10 - pinsknocked[NUM_ROUNDS - 1][0]);
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
        
    }
}

int calculate_score(int pinsknocked[NUM_ROUNDS][3])
{
    int score = 0;
    int round = 0; // Inicializamos el contador de rondas

    // Cálculo de puntuación
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
        round++; // Incrementamos el contador de rondas
        printf("Ronda %d: %d puntos\n", round, score); // Ajuste: Imprime la puntuación después de calcularla
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
        round++; // Incrementamos el contador de rondas
        printf("Ronda 10: %d puntos\n", score); // Ajuste: Imprime la puntuación después de calcularla
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
    while (scanf("%d", &choice) != 1 || choice != 1 && choice != 2) 
        {
            printf("Elección no válida, ingresa '1' o '2': ");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
    if (choice == 1)
    {
        printf("Introduce el número de test: \n1. Todo plenos\n2.Todo 0\n3.Todo 1\n4.Diez veces 3\n5.Jugada aleatoria\n");
        while (scanf("%d", &testnum) != 1 || testnum < 1 || testnum > 5) 
        {
            printf("Ingresa un número del 1 al 5");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }
        if (testnum == 1)
            all_strikes(pinsknocked);
        if (testnum == 2)
            all_loses(pinsknocked);
        if (testnum == 3)
            always_one(pinsknocked);
        if (testnum == 4)
            ten_times_three(pinsknocked);
        if (testnum == 5)
            random_rolls(pinsknocked);
    }
    else
        input_rounds(pinsknocked);
    score = calculate_score(pinsknocked);
    printf("\nResultado total: %d puntos.\n", score);
    return (0);
}