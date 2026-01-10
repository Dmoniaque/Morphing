#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "intermediaire.h"
#include "lecture_ecriture.h"

#ifndef COULEUR__H
#define COULEUR__H

int calculer_inconnu(POINT P, POINT A, POINT B, POINT C, float *lambda, float *nu);
void final(Stock I_depart, Stock I_arrive, Stock *I_inter, int k, int N);

#endif