#include <stdio.h>
#include <stdlib.h>
#include "transfo.h"
#include "lecture_ecriture.h"
#include "uvsqgraphics_2.h"
#include "affichage.h"

int main(int argc, char * argv[]){
    char * nom=argv[1];
    transfo(nom);

    Stock I = lire_fichier("Images/transformee/chat_chien_1.ppm");   // lecture
    Stock I2 = lire_fichier("Images/transformee/chat_chien_2.ppm"); 

    int largeur_totale = I.largeur + 10 + I2.largeur;
    int hauteur_max;
    if (I.hauteur > I2.hauteur) hauteur_max=I.hauteur;
    else hauteur_max=I2.hauteur;

    init_graphics(largeur_totale, hauteur_max);
    affiche_auto_off();
    
    affiche_deux_images(I, I2);
    //affiche_all();
    wait_escape();

    ecrire_fichier(I,"Images/transformee/chat_chien_1.ppm");
    ecrire_fichier(I2,"Images/transformee/chat_chien_2.ppm");

    desaluer_pixels(I.pixels, I.hauteur);
    desaluer_pixels(I2.pixels, I2.hauteur);

    return 0;
}