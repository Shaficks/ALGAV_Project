#include <stdio.h>
#include <stdlib.h>







char* resteMot(char mot[], int i) {
    char *res = malloc(sizeof(res));
    int j;

    for(j = 0; mot[i+j] != '\0'; j++) {
        res[j] = mot[i+j];
    }
    return res;
}








int main(void) {


    printf("Chafik à partir de %d : %s\n",2,resteMot("Chafik",2));


    printf("New Test :\nA : %d | a : %d | Fin : %d\n", 'A', 'B', '\0');



    return EXIT_SUCCESS;
}
