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
        FILE *F;
        F=fopen(nom, "r");

        int c;
        while ((c=fgetc(F)) !='\n'){}


        fscanf(F, "%d", &valeur.largeur);
        fscanf(F, "%d", &valeur.hauteur);
        fscanf(F, "%d", &valeur.range);
        valeur.pixels =allouer_pixel(valeur.largeur, valeur.hauteur);
        /*
        I.pixels[y]=couleur_RGB(ligne);
        I.pixels[x]=couleur_RGB(colonne);
        */
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
