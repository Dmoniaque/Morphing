#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h" //besoin de Stock
#include "uvsqgraphics_2.h"

void affiche_deux_images(Stock I, Stock I2) {
    int espace = 200;

    for (int y = 0; y < I.hauteur; y++) {
        for (int x = 0; x < I.largeur; x++) {               //affiche image I
            draw_pixel((POINT){x, y}, I.pixels[y][x]); 
        }
    }

    for (int y = 0; y < I2.hauteur; y++) {
        for (int x = 0; x < I2.largeur; x++) {              //meme chose ici pour I2
            draw_pixel((POINT){x + I.largeur + espace, y}, I2.pixels[y][x]);        //sauf qu'on ajoute la largeur de I et l'espace pour ne pas que l'image soit sur l'autre
        }
    }

    // Affiche tout à la fin
    //affiche_all();  finalement on l'a mis dans le main sinon ca l'appeler trop de fois et on perdait les ronds rouges
}
