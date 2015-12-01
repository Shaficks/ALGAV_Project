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

/* Inclusion du Header du programme */
#include "../headers/main.h"
#include "arbreBriandais.c"
#include "trieHybride.c"
#include "fonctions_complexes.c"
#include "tools.c"
#include "test.c"


char tab[50000][50];
int tailleTab = 0;

int compteBriandais(ArbreBriandais a) {
    if(!a) return 0;
    return 1 + compteBriandais(a->child) + compteBriandais(a->sibling);
}

int compteHybride(TrieHybride t) {
    if(!t) return 0;
    return 1 + compteHybride(t->inferiorChild) + compteHybride(t->nextChild) + compteHybride(t->superiorChild);
}


//Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
void listeMotsTrieTab(TrieHybride t) {
  ++nb_operations;
  if(t) {
    if(t->cle != -1) {
      strcpy(tab[tailleTab++],t->mot);
    }
    if(t->inferiorChild)
        listeMotsTrie(t->inferiorChild);
    if(t->nextChild)
        listeMotsTrie(t->nextChild);
    if(t->superiorChild)
        listeMotsTrie(t->superiorChild);
  }
}


void reequilibrageRec(TrieHybride res, char tab[5000][50], int t_min, int t_max) {
  if(t_min >= t_max) return; 
       ajoutMotTrie(res,tab[t_min+((t_max-t_min)/2)]);
       reequilibrageRec(res,tab,t_min,((t_max-t_min)/2)-1);
       reequilibrageRec(res,tab,((t_max-t_min)/2)+1,t_max);
}


void suppressionListeBriandais(ArbreBriandais a, char** liste, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        suppressionMotBriandais_V1(a,liste[i]);
}


void suppressionListeHybride(TrieHybride t, char** liste, int taille) {
    int i;
    for(i = 0; i < taille; i++)
        suppressionMotTrie_V1(t,liste[i]);
}


int main(void) {
  printf("\n\n");
  
  //Test rééquilibirage
  TrieHybride t = trieVide(), res = trieVide();
  constructTrieHybride(t,base,tailleBase);
  listeMotsTrieTab(t);


  printf("\nListe Tab :");
  int i;
  for(i = 0; i < tailleTab; i++) {
    printf("\n%s",tab[i]);
  }
  
  reequilibrageRec(res,tab,0,tailleTab-1);

  
  
  listeMotsTrieTab(res);

  

/*
 //Test suppression d'une liste de mots
 ArbreBriandais a = arbreVide(); constructArbreBriandais(a,base,tailleBase);
 TrieHybride t = trieVide(); constructTrieHybride(t,base,tailleBase);


 ajoutMotBriandais(a,"premier"); ajoutMotBriandais(a,"deux"); ajoutMotBriandais(a,"trois");
 ajoutMotTrie(t,"premier"); ajoutMotTrie(t,"deux"); ajoutMotTrie(t,"trois");

 suppressionListeBriandais(a,base,tailleBase);
 suppressionListeHybride(t,base,tailleBase);

 printf("\nListe mots Briandais\n");
 char mot[50];
 listeMotsBriandais(a->sibling,mot,0);

 printf("\nListe mots Hybride\n");
 listeMotsTrie(t->nextChild);
*/





  /********** Menu Principal **********/
  /*system("clear");



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
        while(!(choix2 >= 1 && choix2 <= 3)) {
            printf("\nEntrez votre choix : ");
            scanf("%d",&choix2);
        }
        switch(choix2) {
        case 1 : system("clear"); testShakespeareTrieHybride(); break;
        case 2 : system("clear"); testBaseTrieHybride(); break;
        case 3 : system("clear"); testConversionTrieHybride(); break;
        default : break;
        }
    }
  */
  printf("\n\n");
  return EXIT_SUCCESS;
}
