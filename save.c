#include<stdio.h>
#include<stdlib.h>
#include"save.h"
#include "filemanagement.h"


void saveGame(const char* partie) {
  FILE *file;
  recovertext(partie);

  remove("save.txt");//supprime le contenue du file
  file=fopen("save.txt","w");
     if (file == NULL) {
        printf("Could not open file.\n");
        exit(0);
    }
  fprintf(file, "%s", recovertext(partie));
  fclose(file);
  printf("Votre partie a bien ete enregistre!");
}

void restartGame(const char* partie){
  displayPart(partie);
}
