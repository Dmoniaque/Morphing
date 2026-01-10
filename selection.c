#include <stdio.h>
#include <stdlib.h>
#include "uvsqgraphics_2.h"
#include "lecture_ecriture.h"
#include "affichage.h"
#include "enregistrer.h"
#include "selection.h"

void selection(Stock *I1, Stock *I2){
    int espace =200;
    
    for (int j=0; j<12; j++){
        int i= I1->nb_point;
        POINT gauche= wait_clic();
        I1->point[i]= gauche;

        affiche_deux_images(*I1, *I2);
        draw_circle(gauche, 10, rouge);
        aff_int(i+1, 15, (POINT){gauche.x+15, gauche.y+15}, blanc);
        affiche_all();

        POINT droite= wait_clic();
        I2->point[i].x= droite.x - (I1->largeur+espace);
        I2->point[i].y= droite.y;

        affiche_deux_images(*I1, *I2);
        draw_circle(gauche, 10, rouge);
        aff_int(i+1, 15, (POINT){gauche.x+15, gauche.y+15}, blanc);
        draw_circle(droite, 10, rouge);
        aff_int(i+1, 15, (POINT){droite.x+15, droite.y+15}, blanc);
        affiche_all();

        I1->nb_point++;
        I2->nb_point++;
    }

    affiche_deux_images(*I1, *I2);
    for (int k=0; k<I1->nb_point; k++){
            draw_circle(I1->point[k], 10, rouge);
            POINT blabla={I2->point[k].x+I1->largeur + espace, I2->point[k].y};
            draw_circle(blabla, 10, rouge);

            aff_int(k+1, 15, (POINT){I1->point[k].x+15, I1->point[k].y+15}, blanc);
            aff_int(k+1, 15, (POINT){blabla.x+15, blabla.y+15}, blanc);

            int x_txt=I1->largeur+10;
            int y_txt=30+(k*30);
            aff_int(k+1, 15, (POINT){x_txt, y_txt}, blanc);
            aff_int(I1->point[k].x, 12, (POINT){x_txt+30, y_txt}, blanc);
            aff_int(I2->point[k].x, 12, (POINT){x_txt+110, y_txt}, blanc);
    }

    int h= I1->hauteur;
    int l= I1->largeur;
    POINT b1= {l +10, h-75};
    POINT b2= {l+190, h-45};
    draw_fill_rectangle(b1, b2, blanc);
    aff_pol("ENREGISTRER", 12, (POINT){b1.x + 45, b1.y +10}, noir);

    POINT d1= {l +10, h-35};
    POINT d2= {l+190, h-5};
    draw_fill_rectangle(d1, d2, rouge);
    aff_pol("QUITTER", 12, (POINT){d1.x + 65, d1.y +10}, blanc);    
    
    affiche_all();

    int fin=0;
    while (!fin){
        POINT clic=wait_clic();
        if (clic.x >= b1.x && clic.x <= b2.x && clic.y >= b1.y && clic.y <= b2.y){
            enregistrer(*I1, *I2, "point.txt");
            printf("Valeurs enregistrées\n");
        }

        if (clic.x >= d1.x && clic.x <= d2.x && clic.y >= d1.y && clic.y <= d2.y){
            printf("Quitter\n");
            fin=1;
        }
    }
    //exit(0);
}