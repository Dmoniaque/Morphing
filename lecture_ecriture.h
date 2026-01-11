#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "uvsqgraphics_2.h"
#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

typedef uint32_t COULEUR;

typedef struct{  // idee de l'ia en gros ca dit de relier les points 1, 2, 3 entre eux pour avoir un triangle
    int s1, s2, s3;
}TRIANGLE;

typedef struct{
    int largeur;
    int hauteur;
    int range;
    POINT point[100]; //possede les coordonne des valeurs choisit
    int nb_point;
    TRIANGLE triangle[400]; //possede tous les triangle de l'image
    int nb_triangle;
    COULEUR** pixels;
}Stock;

COULEUR couleur_RGB_stock(int r, int g, int b);
COULEUR** allouer_pixel(int largeur, int hauteur);
Stock lire_fichier (char *nom);
void desaluer_pixels(COULEUR** pixels, int hauteur);
void ecrire_fichier(Stock I, char *nom);
void lire_points(Stock *I1, Stock *I2, char *nom_fichier);

#endif