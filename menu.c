#include <stdio.h>
#include "menu.h"
#include "filemanagement.h"



int StartGame(void){
int choix;
 do {
        printf("Menu \n");
        printf("1. Nouvelle Partie\n");
        printf("2. Continuer\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        while(getchar()!='\n'){
          
        }
   

        switch (choix) {
            case 1:
                displayPart( "intro.txt");

                break;
            case 2:
                restartGame("save.txt");
              
                break;
               
            case 3:
                printf("Au revoir !\n");
                exit(0);
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
                break;
        }
    } while (choix!= 3 && choix!=2 && choix!=1 || getchar()!='\n');

    return 0;
}
