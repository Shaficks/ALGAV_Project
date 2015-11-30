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

//Fusionne les Arbres a et b dans res.
void fusionBriandais(ArbreBriandais a, ArbreBriandais b, ArbreBriandais res, ArbreBriandais parent) {
    if(a) ArbreBriandais ita = a;
    if(b) ArbreBriandais itb = b;
    ArbreBriandais prec = res, itres = res;

    //On commence par parcourir les noeuds de la forêt lexicographique de a
    while(ita) {
        while(itres) {
            if(toupper(itres->val) < toupper(ita->value)) {
                prec = itres;
                itres = itres->sibling;
                break;
            }
        }

        //Si itres est NULL, c'est qu'on a atteint la fin de la liste ça veut dire que le noeud n'existe pas, on l'insère donc entièrement !
        if(itres == NULL) {
            prec->sibling = ita;
        }

        //Sinon, si on s'est arrêté au milieu de la liste ou au début
        else {
            if(toupper(itres->val) > toupper(ita->val)) {
                //S'il s'agit du fils direct du parent
                if(parent->child == itres) {
                    ArbreBriandais noeud = my_malloc(sizeof(*noeud));
                    noeud->val = ita->val;
                    noeud->sibling = itres;
                    noeud->child = ita->child;
                    parent->child = noeud;
                }
                //S'il s'agit d'un fils se trouvant pas directement en dessous du parent
                else {
                    ArbreBriandais noeud = my_malloc(sizeof(*noeud));
                    noeud->val = ita->val;
                    noeud->sibling = prec->sibling;
                    noeud->child = ita->child;
                    prec->sibling = noeud;
                }
            }
            else if(toupper(itres->val) == toupper(itra->val)) {
                fusionBriandais(ita->child,NULL,itres->child,itres);
            }

        }
    }
}










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
