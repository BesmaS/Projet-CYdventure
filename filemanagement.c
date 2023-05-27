#include<stdio.h>
#include "filemanagement.h"

void displayLbyL(const char *chaine) {
    int i = 0;
    int length = strlen(chaine);
    for (i = 0; i < length; i++) {
        printf("%c", chaine[i]);
        fflush(stdout);
        usleep(60000); // Délai de 0,1 seconde entre chaque affichage
    }
}

char* recovertext(const char* partie){
 FILE *fichier;
    char text[MAX_LENGTH];
    long size_files;

    // Ouvrir le fichier en mode lecture binaire
    fichier = fopen(partie, "rb");

    // Vérifier si le fichier est ouvert avec succès
    if (fichier == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Obtenir la taille du fichier
    fseek(fichier, 0, SEEK_END);
    size_files = ftell(fichier);
    rewind(fichier);

    // Lire le contenu complet du fichier dans la variable 'text'
    if (size_files >= MAX_LENGTH) {
        printf("The file is too large to read in a variable.\n");
        return 1;
    }

    fread(text, sizeof(char), size_files, fichier);

    // Ajouter le caractère de fin de chaîne '\0'
    text[size_files] = '\0';

    // Fermer le fichier
    fclose(fichier);
  
  return text;
}


void recoverNextStep(const char *partie){
recovertext(partie);
  char str[100000];
  const char* part[SIZE];
  int choice;
  int nbr;
  nbr=0;
  int i;
  i=0;
strcpy(str,recovertext(partie));
    
    const char deli[] = "@";  
    const char deli1[] = "#";
    const char deli2[] = "%";
    char *token;

    token = strtok(str, deli); // Obtenir le premier token avant "%"
    token = strtok(NULL, deli);
  while (token!=NULL){ //récupère tout les choix jusqu'au dernier e rtmet les etapes suvantes dans un tableau
    token = strtok(NULL, deli1);
    printf("\n\n%d :",nbr);
    nbr= nbr+1;
    displayLbyL(token);
    token = strtok(NULL, deli2); // Obtenir le reste de la chaîne  en utilisant % comme délimiteur
    
    part[i]=token;
    i=i+1;
  }
  printf("Quel est votre choix?\n");
  do{
    scanf("%d",&choice);
    
  }while(choice!=0 && choice!=1 && choice!=2);  //test si la réponse est valide
  printf("\033[2J\033[H");
  displayPart(part[choice]);
}

  void displayPart(const char *partie){

recovertext(partie);
 char str[100000];
strcpy(str,recovertext(partie));
    
    const char deli[] = "@";  

    char *token;
 token = strtok(str, deli); // Obtenir le premier token avant "@"
   displayLbyL(token);
  
    token = strtok(NULL, deli); // Obtenir le reste de la chaîne le meme délimiteur
  displayLbyL(token);

  token = strtok(NULL, "");// Obtenir le reste de la chaîne  en utilisant NULL comme délimiteur
if(token==NULL){
    printf("\nFin");
  }
  else{
    recoverNextStep(partie);
 }
}