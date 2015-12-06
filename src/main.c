/**
 * \file main.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier main du programme :
 *      - Implémentation des Arbres de la Briandais et Tries Hybrides
 *      - Implémentation des Primitives de chaque structure
 *      - Implémentation de fonctions avancées pour chaque structure
 *      - Comparaison des résultats et efficacité
 */

/********** Inclusion du Header du programme **********/
#include "../headers/main.h"
#include "arbreBriandais.c"
#include "trieHybride.c"
#include "fonctions_complexes.c"
#include "tools.c"
#include "test.c"

/********** Main du Programme **********/
int main(void) {
  printf("\n");

  /********** Menu Principal **********/
  system("clear");
  int choix1 = -1, choix2 = -1;

  printf("1 : Arbre de la Briandais");
  printf("\n2 : Trie Hybride");
  while(choix1 != 1 && choix1 != 2) {
    printf("\nEntrez votre choix : ");
    scanf("%d",&choix1);
  }

    if(choix1 == 1) {
        system("clear");
        printf("1 : Test Shakespeare Briandais");
        printf("\n2 : Test Base Briandais");
        printf("\n3 : Test Fusion Shakespeare Briandais");
        printf("\n4 : Test Conversion Shakespeare Briandais to Trie Hybride");
        printf("\n5 : Test Affichage structure Exemple de base");
        while(!(choix2 >= 1 && choix2 <= 5)) {
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix2);
        }
        switch(choix2) {
        case 1 : system("clear"); testShakespeareBriandais(); break;
        case 2 : system("clear"); testBaseBriandais(); break;
        case 3 : system("clear"); testFusionBriandais(); break;
        case 4 : system("clear"); testConversionBriandais(); break;
        case 5 : system("clear"); testVisualizeBriandais(); break;
        default : break;
        }
    }
    else {
        system("clear");
        printf("1 : Test Shakespeare Trie Hybride");
        printf("\n2 : Test Base Trie Hybride");
        printf("\n3 : Test Conversion Shakespeare Trie Hybride to Briandais");
        printf("\n4 : Test Rééquilibrage Dichotomique - Exemple de Base");
        printf("\n5 : Test Vérification Déséquilibrage - Exemple de Base");
        while(!(choix2 >= 1 && choix2 <= 5)) {
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix2);
        }
        switch(choix2) {
        case 1 : system("clear"); testShakespeareTrieHybride(); break;
        case 2 : system("clear"); testBaseTrieHybride(); break;
        case 3 : system("clear"); testConversionTrieHybride(); break;
        case 4 : system("clear"); testReequilibrageDichotomiqueTrieHybride(); break;
        case 5 : system("clear"); testDesequilibreTrieHybride(); break;
        default : break;
        }
    }

  printf("\n\n");
  return EXIT_SUCCESS;
}
