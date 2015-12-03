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
      //while(strlen(tab[tailleTab]) == 0) tailleTab++;
      strcpy(tab[tailleTab++],t->mot);
    }
    if(t->inferiorChild)
        listeMotsTrieTab(t->inferiorChild);
    if(t->nextChild)
        listeMotsTrieTab(t->nextChild);
    if(t->superiorChild)
        listeMotsTrieTab(t->superiorChild);
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





/* Programme de recherche dichotomique d'un élément dans une liste d'entiers */
int reequilibrageDichotomique() {
  /* DECLARATION DES VARIABLES */
  int iTableau[]={1,2,3,5,6,8,9}; /* Tableau TRIE d’entiers */
  int iRecherche; /* Elément recherché */
  int iPremier; /* Indice du premier élément du sous-tableau analysé */
  int iDernier; /* Indice du dernier élément du sous-tableau analysé */
  int iMilieu; /* Indice de l'élément du milieu du sous-tableau analysé */
  int iTrouve; /* Booléen indiquant si l'élément est trouvé */
  int iFin=1; /* Indication de fin de saisie (0=fin) */
  /* Tant que l'utilisateur souhaite faire des recherches */
  while(iFin) {
    printf("Quel élément recherchez-vous ? ");
    scanf("%d",&iRecherche);
    /* Initialisation des variables*/
    iPremier=0;
    iDernier=6;
    iTrouve=0;
    /* Tant qu'on a pas trouve l'élément recherché ou que le sous-tableau */
    /* contient plus de 1 élément */
    while((iPremier <= iDernier)&&(iTrouve==0)) {
      /* Calcul de la position de l'élément du milieu */
      iMilieu=(iPremier+iDernier)/2;
      /* Si l'élément du milieu est l'élément recherché */
      if(iTableau[iMilieu]==iRecherche) iTrouve =1;
      else {
	/* Si la valeur recherchée est plus petite */
	/* que la valeur du l'élément du milieu */
	/* Alors on regarde le sous-tableau de gauche */
	if(iTableau[iMilieu]>iRecherche) iDernier = iMilieu -1;
	/* sinon on regarde le sous-tableau de droite*/
	else iPremier = iMilieu +1;
      }
    }
    if(!iTrouve) printf("Cette valeur n'appartient pas à la liste\n");
    else printf("Cette valeur appartient à la liste\n");
    printf("Voulez-vous continuer ? (Taper 0 pour sortir du programme) : ");
    scanf("%d",&iFin);
    /* Si l'utilisateur ne saisait pas un nombre, on sort du programme */
    if(!isalpha(iFin)) iFin=0;
    
    /* reprise d'une recherche */
    iTrouve=0;
  } /* Fin du while */
} /* Fin du main */






int main(void) {
  printf("\n\n");
  
  //Test rééquilibirage
  TrieHybride t = trieVide(), res = trieVide();
  constructTrieHybride(t,base,tailleBase);
  listeMotsTrieTab(t->nextChild);

  printf("\nTest 1\n");

  printf("\nListe Tab :");
  int i;
  for(i = 0; i < tailleTab; i++) {
    printf("\n%s",tab[i]);
  }
  
  //reequilibrageRec(res,tab,0,tailleTab-1);

  
  
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
