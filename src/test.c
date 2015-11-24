#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>







char* resteMot(char mot[], int i) {
    char *res = malloc(sizeof(res));
    int j;

    for(j = 0; mot[i+j] != '\0'; j++) {
        res[j] = mot[i+j];
    }
    return res;
}


int max2(int a, int b) {
    return (a>b)?a:b;
}


void chargerMots(char chemin[]) {
  FILE* f = NULL;
  char mot[50];  
  f = fopen(chemin,"r+");
  if(f == NULL) {
    printf("Chargement échoué...");
    return;
  }
  else printf("Chargement Réussi !!\n");

  
  do {
    fgets(mot, sizeof mot, f);
    printf("%s",mot);
  } while (!feof(f));
  fclose(f);

  printf("\nC'est fini !\n");
}




int main(void) {



  chargerMots("../files/Shakespeare/titus.txt");
  

/*

    if(1 == 1) printf("\nYes\n");
    else if(2 == 2) printf("\nFuck yeah\n");
    else printf("\nOh shit\n");

    printf("Chafik à partir de %d : %s\n",2,resteMot("Chafik",2));


    printf("New Test :\nA : %d | a : %d | Fin : %d\n", 'A', 'B', '\0');

*/
    return EXIT_SUCCESS;
}
