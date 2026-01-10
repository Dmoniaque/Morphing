#include <stdio.h>
#include <stdlib.h>
#include "transfo.h"
#include "lecture_ecriture.h"
#include "uvsqgraphics_2.h"
#include "affichage.h"
#include "selection.h"

int main(int argc, char * argv[]){
    char * nom=argv[1];
    transfo(nom);

    char * prenom=argv[2];
    transfo(prenom);

    Stock I = lire_fichier("Images/transformee/lion.ppm");   // lecture
    Stock I2 = lire_fichier("Images/transformee/chien.ppm"); 

    int largeur_totale = I.largeur + 200 + I2.largeur;
    int hauteur_max;
    if (I.hauteur > I2.hauteur) hauteur_max=I.hauteur;
    else hauteur_max=I2.hauteur;

    init_graphics(largeur_totale, hauteur_max);
    //set_mode_WINDOW();
    affiche_auto_off();
    
    affiche_deux_images(I, I2);
    affiche_all();
    selection(&I, &I2);
    wait_escape();

    ecrire_fichier(I,"Images/transformee/lion.ppm");
    ecrire_fichier(I2,"Images/transformee/chien.ppm");

    desaluer_pixels(I.pixels, I.hauteur);
    desaluer_pixels(I2.pixels, I2.hauteur);

    return 0;
}