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







int main(void) {


  int a = 5;
  int b = &a;

  printf("\nValeur de a : %d\n",a);
  printf("\nAdresse de a : %d\n",&a);
  printf("\nAdresse de a : %d\n",b);


/*

    if(1 == 1) printf("\nYes\n");
    else if(2 == 2) printf("\nFuck yeah\n");
    else printf("\nOh shit\n");

    printf("Chafik à partir de %d : %s\n",2,resteMot("Chafik",2));


    printf("New Test :\nA : %d | a : %d | Fin : %d\n", 'A', 'B', '\0');

*/
    return EXIT_SUCCESS;
}
