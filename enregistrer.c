#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"
#include "selection.h"
#include "enregistrer.h"

void enregistrer(Stock I1, Stock I2, char *nom_fichier){   //ecrit dans un .txt les valeurs cliquées
    FILE *f;
    f=fopen(nom_fichier, "w");
   
    int L= I1.largeur;  
    int H=I1.hauteur;
// les deux premiers c'est x1 y1 et les deux derniers c'est x2 y2
//I1 et I2 ont les memes valeurs parce que j'ai force un resize a 500x500
    fprintf(f, "%d %d %d %d\n", 0, 0, 0, 0); //en haut a gauche
    fprintf(f, "%d %d %d %d\n", L-1, 0, L-1, 0); //en haut a droite
    fprintf(f, "%d %d %d %d\n", 0, H-1, 0, H-1); //en bas a gauche
    fprintf(f, "%d %d %d %d\n", L-1, H-1, L-1, H-1); //en bas a droite

    for (int i=0; i<I1.nb_point; i++){
        fprintf(f, "%d %d %d %d\n", I1.point[i].x, I1.point[i].y, I2.point[i].x, I2.point[i].y); //ecris les points choisis
    }
    fclose(f);
}