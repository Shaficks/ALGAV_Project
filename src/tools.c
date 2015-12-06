/**
 * \file tools.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier tools du programme :
 *      - Implémentation des fonctions utilitaires du programme.
 */

/* Inclusion du Header du programme */
#include "../headers/main.h"

char graph[5000][20];


/********** VIII - Fonction utilitaires **********/

//Charge la liste des mots du fichier donné dans la liste de mots globale.
void chargerMots() {
  int i = -1;
  FILE* f = NULL;
  char mot[50];
  printf("Avant de charger\n");
  f = fopen("../files/Shakespeare/timon.txt","r+");
  if(f == NULL) {
    printf("é zebi o.O !!");
    return;
  }
  else printf("Chargement Réussi !!\n");

  do {
    i++;
    fgets(mot, sizeof base[i], f);
    printf("%s",mot);
  } while (i<20);
  fclose(f);

}

//Affiche la liste des mots du Tableau global contenant l'exemple de base
void afficheListeMots() {
  int i;
  for (i=0; i<30; i++)
    printf("%s\n",base[i]);
}

//Alloue de la memoire avec malloc mais quitte le programme en cas de probleme
void *my_malloc(size_t size) {
  void *p;
  p = malloc(size);
  if(p == NULL) {
    fprintf(stderr, "Erreur : impossible d'allouer la memoire\n");
    exit(-1);
  }
  return p;
}

//Retourne le reste d'un mot à partir de l'ième lettre incluse
char* resteMot(char mot[], int i) {
    char *res = malloc(sizeof(res));
    int j, n = strlen(mot);
    for(j = 0; i+j < n+1; j++) {
        //printf("\nReste Mot %d\n",j);
        res[j] = mot[i+j];
    }
    return res;
}

//Fonction qui retourne l'entier le plus grand entre a et b
int max2(int a, int b) {
    return (a>b)?a:b;
}

//Fonction qui retourne l'entier le plus grand entre a, b et c
int max3(int a, int b, int c) {
    if(a>b && a>c) return a;
    if(b>a && b>c) return b;
    return c;
}

//Fonction qui retourne l'entier le plus petit entre a, b et c
int min3(int a, int b, int c) {
    if(a<b && a<c) return a;
    if(b<a && b<c) return b;
    return c;
}

//Fonction qui, à partir d'une racine d'un arbre de la briandais, supprime tout l'arbre en libérant l'espace mémoire.
void freeBriandais(ArbreBriandais a) {
  ++nb_operations;
  if(!a) return;
  ArbreBriandais to_del = a;
  if(a->sibling) freeBriandais(a->sibling);
  if(a->child) freeBriandais(a->child);
  free(to_del);
}

//Fonction qui, à partir d'une racine d'un Trie Hybride, supprime tout le Trie en libérant l'espace mémoire.
void freeHybride(TrieHybride t) {
  ++nb_operations;
  if(!t) return;
  TrieHybride to_del = t;
  if(t->inferiorChild) freeHybride(t->inferiorChild);
  if(t->nextChild) freeHybride(t->nextChild);
  if(t->superiorChild) freeHybride(t->superiorChild);
  free(to_del);
}

//Sert à générer du Code GraphViz à partir du Trie t (N'est pas tout à fait au point)
void graphViz(TrieHybride t, int profondeur) {
    if(t) {
        graph[profondeur][0] = t->val; graph[profondeur][1] = ';';
        if(t->inferiorChild) {
            graph[++profondeur][0] = t->val;
            graph[profondeur][1] = '-';
            graph[profondeur][2] = '>';
            graph[profondeur][3] = t->inferiorChild->val;
            graph[profondeur][4] = ';';
            graphViz(t->inferiorChild, ++profondeur);
        }
        if(t->nextChild) {
            graph[++profondeur][0] = t->val;
            graph[profondeur][1] = '-';
            graph[profondeur][2] = '>';
            graph[profondeur][3] = t->nextChild->val;
            graph[profondeur][4] = ';';
            graphViz(t->nextChild, profondeur+4);
        }
        if(t->superiorChild) {
            graph[++profondeur][0] = t->val;
            graph[profondeur][1] = '-';
            graph[profondeur][2] = '>';
            graph[profondeur][3] = t->superiorChild->val;
            graph[profondeur][4] = ';';
            graphViz(t->superiorChild, profondeur+8);
        }
    }
}

