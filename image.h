#ifndef IMAGE_H
#define IMAGE_H

typedef struct{
    int largeur;
    int hauteur;
    unsigned char *pixel;  //pour eviter les negatifs
    int *point;
    int *triangle;

}Stock;

#endif