#include <stdio.h>
#include <stdlib.h>

#ifndef BOWLING_H
#define BOWLING_H

#define NUM_ROUNDS 10

void input_rounds(int pinsknocked[NUM_ROUNDS][3]);
int calculate_score(int pinsknocked[NUM_ROUNDS][3]);
void all_strikes(int pinsknocked[NUM_ROUNDS][3]);
void all_loses(int pinsknocked[NUM_ROUNDS][3]);
void always_one(int pinsknocked[NUM_ROUNDS][3]);
void ten_times_three(int pinsknocked[NUM_ROUNDS][3]);
void random_rolls(int pinsknocked[NUM_ROUNDS][3]);
void printscore(int score1, int score2, int round);
void last_spare(int pinsknocked[NUM_ROUNDS][3]);

#endif