#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef INTERMEDIAIRE
#define INTERMEDIAIRE

void calcul_point_intermediaire(Stock I_depart, Stock I_arrive, Stock *I_inter, int k, int N);
float signe(POINT p1, POINT p2, POINT p3);
int dedans_triangle(POINT p, POINT a, POINT b, POINT c);
int trianguler_image_intermediaire(Stock *I);
void sauvegarder(Stock I_inter, int k);

#endif