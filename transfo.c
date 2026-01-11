#include <stdio.h>
#include <stdlib.h>
#include "transfo.h"

void transfo(char * nom){
    char commande[256];
    snprintf(commande, sizeof(commande), "convert Images/originale/%s.jpg -resize 500x500^ -gravity center -extent 500x500 -compress none Images/transformee/%s.ppm", nom, nom);  
    system(commande);
    //system("convert Images/originale/.jpg -define ppm:format=ascii Images/transformee/%s.ppm");

}

/*magick convert image.ppm -resize 200x200 image_redim.ppm 
magick convert image.jpg image.ppm   
magick convert image.png image.ppm*/