#ifndef BOWLING_H
#define BOWLING_H

#define NUM_ROUNDS 10

// Prototipo de la función para ingresar los datos de las rondas
void input_rounds(int pinsknocked[NUM_ROUNDS][3]);
// Prototipo de la función para calcular la puntuación
int calculate_score(int pinsknocked[NUM_ROUNDS][3]);
void all_strikes(int pinsknocked[NUM_ROUNDS][3]);
void all_loses(int pinsknocked[NUM_ROUNDS][3]);
void always_one(int pinsknocked[NUM_ROUNDS][3]);
void ten_times_three(int pinsknocked[NUM_ROUNDS][3]);
void random_rolls(int pinsknocked[NUM_ROUNDS][3]);

#endif
