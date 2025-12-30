#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"
#include "uvsqgraphics_2.h"

void affiche_deux_images(Stock I, Stock I2) {
    int espacement = 10; // espace entre les deux images

    // Parcours de la première image
    for (int y = 0; y < I.hauteur; y++) {
        for (int x = 0; x < I.largeur; x++) {
            if (I.pixels && I.pixels[y]) {
                draw_pixel((POINT){x, y}, I.pixels[y][x]);
            }
        }
    }

    // Parcours de la deuxième image (à droite avec espacement)
    for (int y = 0; y < I2.hauteur; y++) {
        for (int x = 0; x < I2.largeur; x++) {
            if (I2.pixels && I2.pixels[y]) {
                draw_pixel((POINT){x + I.largeur + espacement, y}, I2.pixels[y][x]);
            }
        }
    }

    // Affiche tout à la fin
    affiche_all();
}
