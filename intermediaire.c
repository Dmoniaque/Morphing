#include <stdio.h>
#include <stdlib.h>
#include "lecture_ecriture.h"
#include "intermediaire.h"

void calcul_point_intermediaire(Stock I_depart, Stock I_arrive, Stock *I_inter, int k, int N){
    float alpha= (float)k/ (float)N;

    I_inter->largeur= I_depart.largeur;
    I_inter->hauteur= I_depart.hauteur;
    I_inter->nb_point= I_depart.nb_point;

    for (int n =0; n< I_depart.nb_point; n++){
        I_inter->point[n].x= (1.0 -alpha)* I_depart.point[n].x + alpha* I_arrive.point[n].x;
        I_inter->point[n].y= (1.0 -alpha)* I_depart.point[n].y + alpha* I_arrive.point[n].y;
    }
}

float signe(POINT p1, POINT p2, POINT p3){
    return (p1.x- p3.x) * (p2.y- p3.y) - (p2.x -p3.x)* (p1.y - p3.y);
}

int dedans_triangle(POINT p, POINT a, POINT b, POINT c){
    float g1, g2, g3;
    g1=signe(p, a, b);
    g2=signe(p, b, c);
    g3=signe(p, c, a);

    int negatif=(g1<0) && (g2<0) && (g3<0);
    int positif=(g1>0) && (g2>0) && (g3>0);

    if (negatif && positif) return 0;
    else return 1;
}

int trianguler_image_intermediaire(Stock *I){
    if (I-> nb_point<5){
        printf("erreur pas assez de point\n");
        return 1;
    }

    I->triangle[0]= (TRIANGLE){0, 1, 4};
    I->triangle[1]= (TRIANGLE){1, 2, 4};
    I->triangle[2]= (TRIANGLE){2, 3, 4};
    I->triangle[3]= (TRIANGLE){3, 0, 4};
    I->nb_triangle= 4;

    for (int i=5; i< I->nb_point; i++){
        POINT P= I->point[i];

        for (int j =0; j<I->nb_triangle; j++){
            int A= I->triangle[j].s1;
            int B= I->triangle[j].s2;
            int C= I->triangle[j].s3;

            if (dedans_triangle(P, I->point[A], I->point[B], I->point[C])){
                I->triangle[j]= I->triangle[I->nb_triangle -1];
                I->nb_triangle--;

                I->triangle[I->nb_triangle]= (TRIANGLE){A, B, i};
                I->nb_triangle++;

                I->triangle[I->nb_triangle]= (TRIANGLE){B, C, i};
                I->nb_triangle++;

                I->triangle[I->nb_triangle]= (TRIANGLE){C, A, i};
                I->nb_triangle++;

                break;
            }

        }
    }
    return 0;
}

void sauvegarder(Stock I_inter, int k){
    char nom_fichier[50];
    sprintf(nom_fichier, "morphing_%02d.ppm", k);
    ecrire_fichier(I_inter, nom_fichier);
}