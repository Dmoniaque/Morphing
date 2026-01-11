#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"

COULEUR couleur_RGB_stock(int r, int g, int b){
        return ((r%256)<<16) + ((g%256)<<8)+ (b%256);
}

COULEUR** allouer_pixel(int largeur, int hauteur){
        COULEUR** pixels=(COULEUR**)malloc(hauteur*sizeof(COULEUR*));
        if (!pixels) exit(1);
        for(int i=0; i<hauteur; i++){
                pixels[i]=(COULEUR*)malloc(largeur*sizeof(COULEUR));
                if (!pixels[i]) exit (2);
        }
        return pixels;
}


Stock lire_fichier (char *nom){
        Stock valeur;
        valeur.nb_point=0;
        valeur.nb_triangle=0;

        FILE *F;
        F=fopen(nom, "r");

        int c;
        while ((c=fgetc(F)) !='\n'){}

        fscanf(F, "%d", &valeur.largeur);
        fscanf(F, "%d", &valeur.hauteur);
        fscanf(F, "%d", &valeur.range);
        valeur.pixels =allouer_pixel(valeur.largeur, valeur.hauteur);

        int r,g,b;
        for (int i=0; i<valeur.hauteur; i++){
                for (int j=0; j<valeur.largeur; j++){
                        fscanf(F, "%d %d %d ", &r, &g, &b);
                        valeur.pixels[i][j]= couleur_RGB_stock(r, g, b);
                }
        }
        fclose(F);
        return valeur;

}
void desaluer_pixels(COULEUR** pixels, int hauteur){
        for (int i=0; i<hauteur; i++){
                free(pixels[i]);
        }
        free(pixels);
}

void ecrire_fichier(Stock I, char *nom){
        FILE* F;
        F= fopen(nom, "w");
        if (!F){
                printf("Probleme d'ouverture fichier\n");
                exit(3);
        }
        fprintf(F, "P3\n");
        fprintf(F, "%d %d\n", I.largeur, I.hauteur);
        fprintf(F, "%d\n", I.range);

        for (int i=0; i<I.hauteur; i++){
                for (int j=0; j<I.largeur; j++){
                        COULEUR c=I.pixels[i][j];
                        int r= (c>>16) & 0xFF;
                        int g= (c>>8) & 0xFF;
                        int b= c & 0xFF;
                        fprintf(F, "%d %d %d ", r, g, b);
                }
                fprintf(F, "\n");
        }
        fclose(F);
}

void lire_points(Stock *I1, Stock *I2, char *nom_fichier){
        FILE *f= fopen(nom_fichier, "r");
        
         if (f == NULL) {
            printf("Erreur: impossible d'ouvrir %s\n", nom_fichier);
            I1->nb_point = 0;
            I2->nb_point = 0;
            return;
        }
        
        int x1, y1, x2, y2;
        I1->nb_point=0;
        I2->nb_point=0;

        while (fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2)==4){
                int i= I1->nb_point;
                I1->point[i]= (POINT){x1, y1};
                I2->point[i]= (POINT){x2, y2};
                I1->nb_point++;
                I2->nb_point++;
        }
        fclose(f);
}