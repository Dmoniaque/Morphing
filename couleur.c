#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"
#include "intermediaire.h"
#include "couleur.h"

int calculer_inconnu(POINT P, POINT A, POINT B, POINT C, float *lambda, float *nu){     //calcul coordonnees barycentrique P=A+Lambda(B-A)+ nu(C-A)
    float denominateur= (float)((B.x- A.x)* (C.y-A.y) - (B.y -A.y)* (C.x -A.x)); 

    if (denominateur==0){  //evite un nombre qui vaut 0 PARCE QUE CEST IMPOSSIBLE UNE DIVISION PAR 0
        *lambda=0;
        *nu=0;
        return 1;
    }

    *lambda=(float)((P.x-A.x)* (C.y-A.y) - (P.y -A.y)* (C.x -A.x)) / denominateur;
    *nu= (float)((B.x-A.x)* (P.y-A.y) - (B.y -A.y)* (P.x -A.x))/ denominateur;
    
    return 0;
}

void final(Stock I_depart, Stock I_arrive, Stock *I_inter, int k, int N){  //fais l'image intermediaire 
    float alpha= (float)k/(float)N;   //on divise pour avoir un truc entre I et I2
    float L, M;  //L=lambda et M=nu j'ai pas mis N pour pas me melanger avec l'autre

    for (int y=0; y<I_inter->hauteur; y++){
        for (int x=0; x<I_inter->largeur; x++){
            POINT P= {x, y};

            for (int t=0; t<I_inter ->nb_triangle; t++){   //pour un pixel on parcourt les triangles
                int iA= I_inter->triangle[t].s1;
                int iB= I_inter->triangle[t].s2;
                int iC= I_inter->triangle[t].s3;

                if(dedans_triangle(P, I_inter->point[iA], I_inter->point[iB], I_inter->point[iC])){  //on regarde si le pixel appartient a un triangles, si ces coordonnes sont dedans
                    calculer_inconnu(P, I_inter->point[iA], I_inter->point[iB], I_inter->point[iC], &L, &M);

                    int x_depart=(int)(I_depart.point[iA].x + L*(I_depart.point[iB].x- I_depart.point[iA].x) +M* (I_depart.point[iC].x -I_depart.point[iA].x));     //on regarde les points de I_inter ils etaient ou dans I
                    int y_depart=(int)(I_depart.point[iA].y + L*(I_depart.point[iB].y- I_depart.point[iA].y) +M* (I_depart.point[iC].y -I_depart.point[iA].y));
                
                    int x_arrive=(int)(I_arrive.point[iA].x + L*(I_arrive.point[iB].x- I_arrive.point[iA].x) +M* (I_arrive.point[iC].x -I_arrive.point[iA].x));     //et on regarde ca serait ou dans I2
                    int y_arrive=(int)(I_arrive.point[iA].y + L*(I_arrive.point[iB].y- I_arrive.point[iA].y) +M* (I_arrive.point[iC].y -I_arrive.point[iA].y));
                   
                    if (x_depart<0) x_depart=0;                                     //evite les problemes si j'y avais pense avant j'aurais pas perdu max de temps avec une segfault (-_-)
                    if (x_depart>=I_depart.largeur) x_depart=I_depart.largeur-1;
                    if (y_depart<0) y_depart=0;
                    if (y_depart>=I_depart.hauteur) y_depart=I_depart.hauteur-1;

                    if (x_arrive<0) x_arrive=0;
                    if (x_arrive>=I_arrive.largeur) x_arrive=I_arrive.largeur-1;
                    if (y_arrive<0) y_arrive=0;
                    if (y_arrive>=I_arrive.hauteur) y_arrive=I_arrive.hauteur-1;

                    COULEUR cdepart= I_depart.pixels[y_depart][x_depart];  //on prend les couleurs des pixels de I et I2
                    COULEUR carrive= I_arrive.pixels[y_arrive][x_arrive];

                    int rd=(cdepart >>16) &0xFF;  //on les calcule pour recupe en RGB
                    int gd=(cdepart >>8) &0xFF;
                    int bd=cdepart &0xFF;

                    int ra=(carrive >>16) &0xFF;
                    int ga=(carrive >>8) &0xFF;
                    int ba=carrive &0xFF;

                    int rf=(int)((1.0-alpha)*rd +alpha*ra);  //on les melange
                    int gf=(int)((1.0-alpha)*gd +alpha*ga);
                    int bf=(int)((1.0-alpha)*bd +alpha*ba);

                    I_inter->pixels[y][x]= couleur_RGB_stock(rf, gf, bf); //et on les garde pour creer I_inter
                    break; //on stop le if ici parce que si on a trouve le bon triangle pas besoin de chercher encore parce que un pixel ca appartient a un triangle
                }
            }
        }
    }
}