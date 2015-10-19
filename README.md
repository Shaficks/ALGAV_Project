# ALGAV_Project
Devoir de Programmation ALGAV
Auteur - Chafik NOUIRA

UPMC - Master 1 Informatique STL - Semestre 1 - 2015-2016
Devoir de Programmation ALGAV : 20% de la moyenne générale de l'UE.

I - Avancée globale du projet - [0%...]

1 - Implémentation de la structure des Arbres de la Briandais - [0%...]

2 - Implémentaiton de la structure des Tries Hybrides - [0%...]

3 - Implémentation des primitives de base des Arbres de la Briandais - [0%...]

4 - Implémentation des primitives de base des Tries Hybrides - [0%...]

5 - Implémentation de fonctions avancées pour chacune des structures - [0%...]
    5.1 - Arbres de la Briandais - [0%...]
    5.2 - Tries Hybrides - [0%...]
    
6 - Implémentation de fonctions complexes pour chacune des structures - [0%...]
    6.1 - Arbres de la Briandais - [0%...]
    6.2 - Tries Hybrides - [0%...]
    
7 - Complexité - [0%...]

8 - Étude Expérimentale - [0%...]


II - Avancée détaillée du projet (Avec réponses aux questions d'étude théorique):
Question 1.1 - Structure 1 : Arbres de la Briandais - [0%...]
1.1 - [0%...]
1.2 - Voir TD pour la liste des Primitives - [0%...]
1.3 - [0%...]
Question 1.2 - Structure 2 : Tries Hybrides - [0%...]
1.4 - Voir Cours pour la liste des Primitives - [0%...]
1.5 - [0%...]

Question 2 - Fonctions avancées pour chacune des structures - [0%...]
2.6 - [0%...]
  2.6.1 - Arbres de la Briandais - [0%...]
        a) Recherche(arbre,mot) --> boolean - [0%...]
        b) ComptageMots(arbre) --> entier - [0%...]
        c) ListeMots(arbre) --> liste|mots| - [0%...]
        d) ComptageNil(arbre) --> entier - [0%...]
        e) Hauteur(arbre) --> entier - [0%...]
        f) ProfondeurMoyenne(arbre) --> entier - [0%...]
        g) Prefixe(arbre,mot) --> entier - [0%...]
        h) Suppression(arbre,mot) --> arbre - [0%...]
  2.6.2 - Tries Hybrides - [0%...]
        a) Recherche(arbre,mot) --> boolean - [0%...]
        b) ComptageMots(arbre) --> entier - [0%...]
        c) ListeMots(arbre) --> liste|mots| - [0%...]
        d) ComptageNil(arbre) --> entier - [0%...]
        e) Hauteur(arbre) --> entier - [0%...]
        f) ProfondeurMoyenne(arbre) --> entier - [0%...]
        g) Prefixe(arbre,mot) --> entier - [0%...]
        h) Suppression(arbre,mot) --> arbre - [0%...]
        
Question 3 - Fonction complexes - [0%...]
3.7 - FusionBriandais(arbre1, arbre2) --> arbre - [0%...] (Expliquer les étapes importantes)
3.8 - Fonctions de conversion d'une structure d'arbre à l'autre - [0%...]
    a) BriandaisToTrieHybride(arbre) --> arbre- [0%...]
    (Prend en paramètres un Arbre de la Briandais et retourne un Trie Hybride) 
    b) TrieHybrideToBriandais(arbre) --> arbre - [0%...]
    (Prend en paramètres un Trie Hybride et retourne un Arbre de la Briandais)
3.9 - Trie Hybride (Question théorique - Voir énoncé) - [0%...]
- AjoutAvecReequilibrage(arbre,mot) --> arbre - [0%...]

Question 4 - Complexités (Question théorique - Voir énoncé) - [0%...]
4.10 - Voir énoncé.

Question 5 - Étude expérimentale - [0%...]
5.11 - Construire l'Arbre de la Briandais et le Trie Hybride en utilisant la base Shakespeare
Lien : http://www-apr.lip6.fr/~genitrini/doc_ens/Shakespeare.tar
     a) ChargerMots(ficher) --> liste|mots|
     b) ConstruireBriandais(liste|mots|) --> arbre
     c) ConstruireTrieHybride(liste|mots|) --> arbre
5.12 - Comparaisons à faire sur machine - Voir énoncé pour les détails
5.13 - Autres comparaisons - Voir énoncé
5.14 - Représenter graphiquement les arbres 
    a) AfficheBriandaisSDL(arbre)
    b) AfficheTrieHybrideSDL(arbre)
