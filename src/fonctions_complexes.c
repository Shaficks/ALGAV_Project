/**
 * \file fonctions_complexes.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier test du programme :
 * Fichier contenant les implémentations des fonctions complexes.
 */

#include "../headers/main.h"

/*
//Fusionne les Arbres a et b dans res.
void fusionBriandais(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res) {
    if(a)
        if(a->sibling) ArbreBriandais ita = a->sibling;
    if(b)
        if(b->sibling) ArbreBriandais itb = b->sibling;
    ArbreBriandais itres = res;

    while(ita && itb) {
        if(itres->sibling) {
            itres = itres->sibling;
            continue;
        }
        if(ita->val <= itb->val) {
            noeud = my_malloc(sizeof(*noeud));
            noeud->val = ita->val;
            noeud->sibling = NULL;
            noeud->child = NULL;
            itres->sibling = noeud;
        }
        else if(toupper(itb->val) < toupper(ita->val)) {

        }
    }
}
*/

//Convertit un Arbre de la Briandais en Trie Hybride et retourne ce dernier.
void BriandaisToTrieHybrideV1(ArbreBriandais a, TrieHybride t, char mot[], int profondeur) {
  if(a) {
    mot[profondeur] = a->val;
    if(a->val == '\0') {
      mot[profondeur] = a->val;
      ajoutMotTrie(t,mot);
    }
    BriandaisToTrieHybrideV1(a->child,t,mot,profondeur+1);
    BriandaisToTrieHybrideV1(a->sibling,t,mot,profondeur);
  }
}

//Convertit un Trie Hybride en Arbre de la Briandais et retourne ce dernier.
ArbreBriandais TrieHybrideToBriandais(TrieHybride t);

//Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]);
