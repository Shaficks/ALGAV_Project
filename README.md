#ALGAV_Project<br/>

###TODO :<br/>
####ListeMotsBriandais<br/>
####ListeMorsTrie<br/>
####SuppressionMotBriandaisV2<br/>
####SuppressionMotTrieV2<br/>
####Correction de AjoutMotBriandais, RechercheMotBriandais avec le cas du mot Dactylographie<br/>
####Comparaison des structures + Captures d'écran<br/>
####Chargement d'une oeuvre de Shakespeare afin de faire des tests avec<br/>
####Affichage d'un aperçu visuel de la structure du Trie Hybride<br/>
####Implémentations des fonctions complexes<br/>

#####Devoir de Programmation ALGAV<br/>
#####Auteur - Chafik NOUIRA<br/><br/>

> UPMC - Master 1 Informatique STL - Semestre 1 - 2015-2016
Devoir de Programmation ALGAV : 20% de la moyenne générale de l'UE.

###I - Avancée globale du projet - [0%...]<br/>
1 - Implémentation de la structure des Arbres de la Briandais - [100%...]<br/>
2 - Implémentaiton de la structure des Tries Hybrides - [100%...]<br/>
3 - Implémentation des primitives de base des Arbres de la Briandais - [99%...]<br/>
4 - Implémentation des primitives de base des Tries Hybrides - [10%...]<br/>
5 - Implémentation de fonctions avancées pour chacune des structures - [0%...]<br/>
    5.1 - Arbres de la Briandais - [0%...]<br/>
    5.2 - Tries Hybrides - [0%...]<br/>
6 - Implémentation de fonctions complexes pour chacune des structures - [0%...]<br/>
    6.1 - Arbres de la Briandais - [0%...]<br/>
    6.2 - Tries Hybrides - [0%...]<br/>
7 - Complexité - [0%...]<br/>
8 - Étude Expérimentale - [0%...]<br/><br/>

###II - Avancée détaillée du projet (Avec réponses aux questions d'étude théorique):<br/>
#####Question 1.1 - Structure 1 : Arbres de la Briandais - [99%...]<br/>
1.1 - Le caractère indiquant la fin d'un mot est '\0'. C'est le caractère NULL représentant la fin d'un mot en langage C', Son code ASCII est 0. [100%]<br/>
1.2 - Voir TD pour la liste des Primitives - [99%...]<br/>
      a) arbreVide --> arbre - [100%]<br/>
      b) ajoutMotBriandais(arbre, mot) --> arbre - [100%]<br/>
      c) ajoutSimpleBriandais(arbre, mot) --> arbre - [100%]<br/>
      d) estArbreVide(arbre) --> entier - [100%...]<br/>
      e) valAB(arbre) --> char - [100%...]<br/>
      f) iemeArbre(arbre, entier) --> arbre - [100%...]<br/>
      g) tousFreresSauf(arbre, entier) --> arbre - [100%...]<br/>
      h) A_Briandais(entier, arbreI, arbre) --> arbre - [99%...]<br/>
1.3 - Construction de l'Arbre de la Briandais en utilisant l'exemple de base - [100%...]<br/>
      a) constructArbreBriandais(arbre, liste|mots|, taille) --> arbre - [100%...]<br/>
#####Question 1.2 - Structure 2 : Tries Hybrides - [0%...]<br/>
1.4 - Voir Cours pour la liste des Primitives - [0%...]<br/>
      a) trieVide() --> trie - [100%...]<br/>
      b) ajoutMotTrie(trie, mot) --> trie - [100%...]<br/>
      c) ajoutSimpleTrie(trie, mot) --> trie - [100%...]<br/>
      d) estTrieVide(trie) --> entier - [100%...]<br/>
      e) valTH(trie) --> char - [100%...]<br/>
      f) sousArbreTH(trie, entier) --> trie - [100%...]<br/>
      g) tousFilsSauf(trie, entier) --> trie - [0%...]<br/>
      h) insertTrieHybride(trie, trie_i, entier) - [0%...]<br/>
1.5 - Construction du Trie Hybride en utilisant l'exemple de base - [100%...]<br/><br/>
      d) constructTrieHybride(trie, liste|mots|, taille) --> arbre - [100%...]<br/>

#####Question 2 - Fonctions avancées pour chacune des structures - [70%...]<br/>
2.6 - [0%...]<br/>
  2.6.1 - Arbres de la Briandais - [70%...]<br/>
        a) Recherche(arbre,mot) --> boolean - [1000%...]<br/>
        b) ComptageMots(arbre) --> entier - [100%...]<br/>
        c) ListeMots(arbre) --> liste|mots| - [0%...]<br/>
        d) ComptageNil(arbre) --> entier - [100%...]<br/>
        e) Hauteur(arbre) --> entier - [0%...]<br/>
        f) ProfondeurMoyenne(arbre) --> entier - [0%...]<br/>
        g) Prefixe(arbre,mot) --> entier - [100%...]<br/>
        h) Suppression(arbre,mot) --> arbre - [50%...]<br/>
  2.6.2 - Tries Hybrides - [70%...]<br/>
        a) Recherche(arbre,mot) --> boolean - [100%...]<br/>
        b) ComptageMots(arbre) --> entier - [100%...]<br/>
        c) ListeMots(arbre) --> liste|mots| - [0%...]<br/>
        d) ComptageNil(arbre) --> entier - [100%...]<br/>
        e) Hauteur(arbre) --> entier - [0%...]<br/>
        f) ProfondeurMoyenne(arbre) --> entier - [0%...]<br/>
        g) Prefixe(arbre,mot) --> entier - [100%...]<br/>
        h) Suppression(arbre,mot) --> arbre - [50%...]<br/><br/>

#####Question 3 - Fonction complexes - [0%...]<br/><br/>
3.7 - FusionBriandais(arbre1, arbre2) --> arbre - [0%...]<br>
(Expliquer les étapes importantes)<br/>
3.8 - Fonctions de conversion d'une structure d'arbre à l'autre - [0%...]<br/>
    a) BriandaisToTrieHybride(arbre) --> arbre - [0%...]<br/>
    (Prend en paramètres un Arbre de la Briandais et retourne un Trie Hybride) <br/>
    b) TrieHybrideToBriandais(arbre) --> arbre - [0%...]<br/>
    (Prend en paramètres un Trie Hybride et retourne un Arbre de la Briandais)<br/>
3.9 - Trie Hybride (Question théorique - Voir énoncé) - [0%...]<br/>
- AjoutAvecReequilibrage(arbre,mot) --> arbre - [0%...]<br/><br/>

#####Question 4 - Complexités (Question théorique - Voir énoncé) - [0%...]<br/>
4.10 - Voir énoncé - [0%...]<br/><br/>

#####Question 5 - Étude expérimentale - [0%...]<br/>
5.11 - Construire l'Arbre de la Briandais et le Trie Hybride en utilisant la base Shakespeare - [0%...]<br/>
Lien : http://www-apr.lip6.fr/~genitrini/doc_ens/Shakespeare.tar<br/>
     a) ChargerMots(ficher) --> liste|mots| - [100%...]<br/>
     b) ConstruireBriandais(liste|mots|) --> arbre - [100%...]<br/>
     c) ConstruireTrieHybride(liste|mots|) --> arbre - [100%...]<br/>
5.12 - Comparaisons à faire sur machine - Voir énoncé pour les détails - [0%...]<br/>
5.13 - Autres comparaisons - Voir énoncé - [0%...]<br/>
5.14 - Représenter graphiquement les arbres - [0%...]<br/>
    a) AfficheBriandaisSDL(arbre) - [0%...]<br/>
    b) AfficheTrieHybrideSDL(arbre) - [0%...]<br/>
