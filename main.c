#include <stdio.h>
#include <stdlib.h>
#include "transfo.h"
#include "lecture_ecriture.h"
#include "uvsqgraphics_2.h"
#include "affichage.h"
#include "selection.h"
#include "enregistrer.h"
#include "intermediaire.h"
#include "couleur.h"

int main(int argc, char * argv[]){
    char * nom=argv[1];
    transfo(nom);

    char * prenom=argv[2];
    transfo(prenom);

    Stock I = lire_fichier("Images/transformee/macron.ppm");   // lecture
    Stock I2 = lire_fichier("Images/transformee/trump.ppm"); 

    //I.nb_point=0;
    //I2.nb_point=0;
    lire_points(&I, &I2, "point.txt");

    int largeur_totale = I.largeur + 200 + I2.largeur;
    int hauteur_max;
    if (I.hauteur > I2.hauteur) hauteur_max=I.hauteur;
    else hauteur_max=I2.hauteur;

    init_graphics(largeur_totale, hauteur_max);
    //set_mode_WINDOW();
    affiche_auto_off();

    affiche_deux_images(I, I2);
    affiche_all();
    //I.nb_point=0;
    //I2.nb_point=0;
    selection(&I, &I2);
   // wait_escape();

    ecrire_fichier(I,"Images/transformee/macron.ppm");
    ecrire_fichier(I2,"Images/transformee/trump.ppm");

    int N=30;
    printf("Debut du morphing\n");
    for (int k=0; k<=N; k++){
        Stock I_inter;
        I_inter.largeur = I.largeur;
        printf("Debut du morphing\n");
        I_inter.hauteur = I.hauteur;
        printf("Debut du morphing\n");
        I_inter.range = I.range;
        printf("Debut du morphing\n");
        I_inter.pixels=allouer_pixel(I_inter.largeur, I_inter.hauteur);
        printf("Debut du morphing\n");
        I_inter.nb_point=I.nb_point;
        calcul_point_intermediaire(I, I2, &I_inter, k, N);
        printf("Debut du morphing\n");
        trianguler_image_intermediaire(&I_inter);
        printf("Debut du morphing\n");
        printf("on a %d\n", k);
        final(I, I2, &I_inter, k, N);
        printf("Debut du morphing\n");
        sauvegarder(I_inter, k);
        printf("Debut du morphing\n");
        desaluer_pixels(I_inter.pixels, I_inter.hauteur);
        printf("Image %d %d calculée...\n", k, N);

    }

    printf("Creation de la video");
    system("ffmpeg -y -framerate 2 -i morphing_%02d.ppm -vcodec libx264 -pix_fmt yuv420p -crf 25 film_morphing.mp4");
    printf("Video termine! Vous pouvez maintenant quitter.\n");

    desaluer_pixels(I.pixels, I.hauteur);
    desaluer_pixels(I2.pixels, I2.hauteur);

    //free(I.point);
    //free(I2.point);

    return 0;
}