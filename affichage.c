#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"
#include "uvsqgraphics_2.h"

void affiche_deux_images(Stock I, Stock I2) {
    int espace = 200;
    //float pas=0.5;
    //int decalage= I.largeur *pas + espace;

    for (int y = 0; y < I.hauteur; y++) {
        for (int x = 0; x < I.largeur; x++) {
            if (I.pixels && I.pixels[y]) {
                draw_pixel((POINT){x, y}, I.pixels[y][x]);
            }
        }
    }

    for (int y = 0; y < I2.hauteur; y++) {
        for (int x = 0; x < I2.largeur; x++) {
            if (I2.pixels && I2.pixels[y]) {
                draw_pixel((POINT){x + I.largeur + espace, y}, I2.pixels[y][x]);
            }
        }
    }

    // Affiche tout à la fin
    //affiche_all();
}
