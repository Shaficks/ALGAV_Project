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
TrieHybride BriandaisToTrieHybride(ArbreBriandais a);

//Convertit un Trie Hybride en Arbre de la Briandais et retourne ce dernier.
ArbreBriandais TrieHybrideToBriandais(TrieHybride t);

//Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]);
