#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "uvsqgraphics_2.h"
#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

typedef uint32_t COULEUR;

typedef struct{
    int largeur;
    int hauteur;
    int range;
    POINT point[100];
    int nb_point;
    int *triangle;
    COULEUR** pixels;
}Stock;

COULEUR couleur_RGB_stock(int r, int g, int b);
COULEUR** allouer_pixel(int largeur, int hauteur);
Stock lire_fichier (char *nom);
void desaluer_pixels(COULEUR** pixels, int hauteur);
void ecrire_fichier(Stock I, char *nom);

#endif