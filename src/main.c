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

int compteBriandais(ArbreBriandais a) {
    if(!a) return 0;
    return 1 + compteBriandais(a->child) + compteBriandais(a->sibling);
}

int compteHybride(TrieHybride t) {
    if(!t) return 0;
    return 1 + compteHybride(t->inferiorChild) + compteHybride(t->nextChild) + compteHybride(t->superiorChild);
}


int main(void) {



  testFusionBriandais();

  printf("\n\n");

  return EXIT_SUCCESS;
}
