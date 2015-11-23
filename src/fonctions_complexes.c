#include "../headers/main.h"


//Fusionne les Arbres a et b dans res.
/*
void fusionBriandais(ArbreBriandais a1, ArbreBriandais a2, ArbreBriandais res) {
if(a) ArbreBriandais ita = a;
if(b) ArbreBriandais itb = b;
ArbreBriandais itres = res;

for()



}
*/
//Convertit un Arbre de la Briandais en Trie Hybride et retourne ce dernier.
TrieHybride BriandaisToTrieHybride(ArbreBriandais a);

//Convertit un Trie Hybride en Arbre de la Briandais et retourne ce dernier.
ArbreBriandais TrieHybrideToBriandais(TrieHybride t);

//Ajout d'un mot dans un Trie suivi par un rééquilibrage si nécessaire.
TrieHybride ajoutAvecReequilibrage(TrieHybride t, char mot[]);
