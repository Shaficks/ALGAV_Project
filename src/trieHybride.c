/**
 * \file trieHybride.c
 * \brief Master 1 Informatique - Spécialité STL - 2015-2016 Semestre 1 - Algorithmique Avancée
 * \author Chafik NOUIRA
 * \date 24 octobre 2015
 * \version 1.0
 *
 * Projet ALGAV - Fichier test du programme :
 * Fichier contenant les implémentations des primitives et fonctions avancées des Tries Hybrides.
 */

#include "../headers/main.h"



/* IV - Liste des primitives de base d'un Trie Hybride */
//Retourne un Trie Hybride réduit à un noeud avec 3 liens vides.
TrieHybride trieVide() {
  TrieHybride t;
  t = my_malloc(sizeof(*t));
  // t->cle et t->val n'ont pas besoin d'initialisation car c'est la cellule sentinelle
  t->superiorChild = NULL;
  t->inferiorChild = NULL;
  t->nextChild = NULL;
  return t;
}

//Ajoute un mot au Trie t et retourne le Trie résultat.
void ajoutMotTrie(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return;
    }

    int i, option=3;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre à ajouter est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
            option = 1;
        }
        //Siinon si la lettre à ajouter est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
            option = 2;
        }
        //Sinon si la lettre à ajouter existe déjà. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            //Cas particulier : L'existence de toutes les lettres mais pas de la clé
            if(mot[i+1] == '\0') {
                if(it->cle == -1) {
                    //Incrémentation du nobmre de mots existants dans le Trie Hybirde
                    it->cle = ++nbMotsHybride;
                    return;
                }
            }
            prec = it;
            it = it->nextChild;
            if(!it) ++i;
            option = 3;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant.
	 Donc appel de la fonction d'ajout simple d'un mot.
	 Cette vérification gére aussi les Tries vides */

      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        ajoutSimpleTrie(prec, resteMot(mot,i), option);
        printf("\nMot \'%s\' ajouté avec succès.\n",mot);
        return;
      }
    }
    printf("\nLe mot \'%s\' existe déjà dans le Trie !!!\n",mot);
}

//Ajoute un mot au Trie t et retourne le Trie résultat.
//PS : L'entier option sert à préciser s'il s'agit d'une lettre supérieure, inférieure ou suivante
void ajoutSimpleTrie(TrieHybride t, char mot[], int option) {
    int i;
    TrieHybride it = t, noeud = my_malloc(sizeof(*noeud));
    noeud->cle = -1;
    noeud->val = mot[0];
    noeud->superiorChild = NULL;
    noeud->inferiorChild = NULL;
    noeud->nextChild = NULL;

    switch(option) {
    case 1 : //Inférieur
        it->inferiorChild = noeud;
        it = it->inferiorChild;
        break;

    case 2 : //Supérieur
        it->superiorChild = noeud;
        it = it->superiorChild;
        break;

    case 3 : //Suivant
        it->nextChild = noeud;
        it = it->nextChild;
        break;

    default : break; //Cas par défaut, il n'y en a pas.
    }

    for(i = 1; mot[i] != '\0'; i++) {
      noeud = my_malloc(sizeof(*noeud));
      noeud->cle = -1;
      noeud->val = mot[i];
      noeud->superiorChild = NULL;
      noeud->inferiorChild = NULL;
      noeud->nextChild = NULL;
      it->nextChild = noeud;
      it = it->nextChild;
    }
    //Incrémentation du nombre de clés présents dans le Trie Hybride
    it->cle = ++nbMotsHybride;
}

//Construit un Trie Hybride à partir d'un dictionnaire donné.
void constructTrieHybride(TrieHybride t, char** dictionnaire, int taille) {
    int i;
    for(i = 0; i < taille; i++)
      ajoutMotTrie(t, dictionnaire[i]);
}

//Retourne 1(VRAI) si le Trie est vide, 0(FAUX) sinon.
int estTrieVide(TrieHybride t) {
  return t->nextChild == NULL;
}

//Retourne VRAI si le noeud est une feuille, FAUX sinon.
int estFeuilleTrie(TrieHybride t) {
    if(!t) return FAUX;
    return (!t->nextChild && (!t->inferiorChild && !t->superiorChild))?VRAI:FAUX;
}

//Retourne le nombre de feuilles du Trie Hybride.
int comptageFeuillesTrie(TrieHybride t) {
    if(!t) return 0;
    if(estFeuilleTrie(t)) return 1;
    return comptageFeuillesTrie(t->nextChild) + comptageFeuillesTrie(t->inferiorChild) + comptageFeuillesTrie(t->superiorChild);
}

//Retourne la valeur de la racine du Trie.
char valTH(TrieHybride t) {
  return t->nextChild->val;
}

//Retourne une copie du i-ème sous arbre du Trie t. (1 =< i >= 3 car c'est un Trie Hybride) - Par défaut cette fonction retourne le sous-arbre gauche.
TrieHybride sousArbreTH(TrieHybride t, int i) {
  switch(i) {
  case 1 : return t->nextChild->inferiorChild;
    break;
  case 2 : return t->nextChild;
    break;
  case 3 : return t->nextChild->superiorChild;
    break;
  default : return t->nextChild->inferiorChild; break;
  }
}

//Retourne la liste des sous-arbres du Trie t privée du i-ème sous-arbre.
TrieHybride tousFilsSauf(TrieHybride t, int i); //On en a vraiment besoin ??

//Retourne le Trie formé avec T en i-ème sous arbre inséré dans la liste (1 <= i <= 3).
TrieHybride insertTrieHybride(TrieHybride t, TrieHybride ti, int i);



/* VI - Liste des fonctions avancées pour les Tries Hybrides */

//Retourne 1(VRAI) si le mot existe dans le Trie a, 0(FAUX) sinon.
int rechercheMotTrie(TrieHybride t, char mot[]) {
    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return FAUX;
    }
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return FAUX;
    }

    int i;
    TrieHybride it = t->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre à ajouter est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            it = it->inferiorChild;
        }
        //Siinon si la lettre à ajouter est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            it = it->superiorChild;
        }
        //Sinon si la lettre à ajouter existe déjà. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            //Cas particulier : L'existence de toutes les lettres mais pas de la clé
            if(mot[i+1] == '\0') {
                //Pas de clé, on retourner FAUX
                if(it->cle == -1) {
                    printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
                    return FAUX;
                }
            }
            it = it->nextChild;
            if(!it) ++i;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant.
	 Donc appel de la fonction d'ajout simple d'un mot.
	 Cette vérification gére aussi les Tries vides */

      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
        return FAUX;
      }
    }
    printf("\nLe mot \'%s\' existe dans le Trie !!!\n",mot);
    return VRAI;
}

//Retourne le nombre de mots présents dans le Trie t. Solution Simple | Complexité O(1)
long int comptageMotsTrie_V1() {
  return nbMotsHybride;
}

//Retourne le nombre de mots présents dans le Trie t. Solution Complexte | Appel récursif sur les noeuds du Trie Hybride.
int comptageMotsTrie_V2(TrieHybride t) {
  if(!t) return 0; //Si le noeud est NULL
  //Cas où le noeud représente une clé
  else if(t->cle != -1) return 1 + comptageMotsTrie_V2(t->nextChild) + comptageMotsTrie_V2(t->inferiorChild) + comptageMotsTrie_V2(t->superiorChild);
  return  comptageMotsTrie_V2(t->nextChild) + comptageMotsTrie_V2(t->inferiorChild) + comptageMotsTrie_V2(t->superiorChild); //Cas général
}

//Retourne la liste des mots présents dans le Trie t triés dans l'ordre alphabétique.
void listeMotsTrie(TrieHybride t, char mot[], int profondeur) {
  if(t) {
    mot[profondeur] = t->val;
    if(t->cle != -1) {
      mot[profondeur+1] = '\0';
      printf("\n%s",mot);
    }
    listeMotsTrie(t->inferiorChild,mot,profondeur);
    listeMotsTrie(t->nextChild,mot,profondeur+1);
    listeMotsTrie(t->superiorChild,mot,profondeur);
  }
}

//Retourne le nombre de pointeurs vers Nil présents dans le Trie t.
int comptageNilTrie(TrieHybride t) {
  if(!t) return 1; //Si le noeud est NULL
  return  comptageNilTrie(t->nextChild) + comptageNilTrie(t->inferiorChild) + comptageNilTrie(t->superiorChild); //Cas général
}

//Calcule et retourne la hauteur du Trie t.
int hauteurTrie(TrieHybride t) {
	if(!t) return 0;
    return max3(1+hauteurTrie(t->nextChild), 1+hauteurTrie(t->superiorChild), 1+hauteurTrie(t->inferiorChild));
}

int profondeurTotaleTrie(TrieHybride t, int n) {
    if(!t) return 0;
    if(estFeuilleTrie(t)) return n;
    return profondeurTotaleTrie(t->nextChild,n+1) + profondeurTotaleTrie(t->inferiorChild,n+1) + profondeurTotaleTrie(t->superiorChild,n+1);
}

//Calcule et retourne la profondeur moyenne des feuilles du Trie t
float profondeurMoyenneTrie(TrieHybride t) {
    if(!t) return 0.0;
    return ((float)profondeurTotaleTrie(t,0)/(float)comptageFeuillesTrie(t));
}

//Retourne le nombre de mots présents dans le Trie t pour lesquels le mot donné est préfixe et les affiche.
int prefixeTrie(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return 0;
    }
    //Au cas où le Trie est vide
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return 0;
    }

    int i;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre i est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
        }
        //Siinon si la lettre i est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
        }
        //Sinon si la lettre i est la même que celle du noeud. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
            prec = it;
            it = it->nextChild;
            if(!it) ++i;
            break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant - Donc le préfixe n'existe pas dans le Trie */
      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
        return 0;
      }
    }
    return comptageMotsTrie_V2(prec);
}

//Supprime un mot du Trie t et retourne le Trie résultat | Version Simple
void suppressionMotTrie_V1(TrieHybride t, char mot[]) {

    //Au cas où le mot est vide
    if(!strlen(mot)) {
        printf("Il faut un mot !\n");
        return;
    }
    //Au cas où le Trie est vide
    if(!t->nextChild) {
        printf("Le Trie est vide !\n");
        return;
    }

    int i;
    TrieHybride it = t, prec;
    prec = it;
    it = it->nextChild;

    for(i = 0; mot[i] != '\0'; i++) {
      while(it) {
        //Si la lettre i est inférieure à la lettre du noeud
        if(toupper(mot[i]) < toupper(it->val)) {
            prec = it;
            it = it->inferiorChild;
        }
        //Siinon si la lettre i est supérieure à la lettre du noeud
        else if(toupper(mot[i]) > toupper(it->val)) {
            prec = it;
            it = it->superiorChild;
        }
        //Sinon si la lettre i est la même que celle du noeud. On passe à la lettre suivante, d'où le break
        else if(toupper(mot[i]) == toupper(it->val)) {
	  //Cas particulier : L'existence de toutes les lettres mais pas de la clé
	  if(mot[i+1] == '\0') {
	    if(it->cle == -1) {
	      printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
	      return;
	    }
	  }
	  prec = it;
	  it = it->nextChild;
	  if(!it) ++i;
	  break;
        }
      }

      /* Si it est NULL, ça veut dire absence de la lettre dans le trie correspondant - Donc absence du mot dans le Trie - Pas de suppression possible */
      if(!it && (strlen(resteMot(mot,i)) >= 1)) {
	printf("\nLe mot \'%s\' n'existe pas dans le Trie.\n",mot);
        return;
      }
    }
    prec->cle = -1;
    --nbMotsHybride; //Décrémentation du nombre des mots
    printf("\nLe mot \'%s\' a été supprimé du Trie.\n",mot);
}

//Supprime un mot du Trie t et retourne le Trie résultat | Version Complexe
void suppressionMotTrie_V2(TrieHybride t, char mot[]);

/* Fonction qui affiche un aperçu visuel du Trie Hybride t */
void afficheStructureHybride(TrieHybride t, int profondeur) {

    int i;
    FILE* fichier = fopen("Trie.xml","w+");
    for (i=0; i < profondeur; i++)
    {
        fputs("|___ ", stdout);
    }

    if(t) {
        printf("[%c]", t->val);
        if(t->cle != -1) printf("[%ld]", t->cle);
        printf("\n");
    }
    if (t->inferiorChild) {
        fprintf(fichier,"<%c>\n",t->inferiorChild->val);
        afficheStructureHybride(t->inferiorChild, profondeur);
        fprintf(fichier,"</%c>\n",t->inferiorChild->val);
    }
    if (t->nextChild) {
        fprintf(fichier,"<%c>\n",t->nextChild->val);
        afficheStructureHybride(t->nextChild, profondeur+1);
        fprintf(fichier,"</%c>\n",t->nextChild->val);
    }
    if (t->superiorChild) {
        fprintf(fichier,"<%c>\n",t->superiorChild->val);
        afficheStructureHybride(t->superiorChild, profondeur);
        fprintf(fichier,"</%c>\n",t->superiorChild->val);
    }
    //fclose(fichier);
}

/*
void visualiseTrie(TrieHybride t) {
	char res[5000];
	FILE* fichier = fopen("trie.txt","w+");
	fprintf(fichier,"digraph G {\n");
	visualize_recTrie(t,fichier, res);
	fprintf(fichier,"%s",res);
	fprintf(fichier,"}");
	printf("\nFichier généré avec succès\n");
	fclose(fichier);
}



void visualize_recTrie(TrieHybride t, FILE* fichier, char res[]) {

        if (t) {
	    fprintf(fichier,"%d;",t);

	  if(t->inferiorChild) {
	    char tmp[50];
  	    sprintf(tmp,"%d-%d",t,t->inferiorChild);
	    strcat(res,tmp);
  	    fprintf(fichier,"%d - %d;",t,t->inferiorChild);
	    visualize_recTrie(t->inferiorChild,fichier,res);
          }
	  if(t->inferiorChild) {
	    char tmp[50];
  	    sprintf(tmp,"%d-%d",t,t->nextChild);
	    strcat(res,tmp);
  	    fprintf(fichier,"%d - %d;",t,t->nextChild);
	    visualize_recTrie(t->nextChild,fichier,res);
          }
	  if(t->inferiorChild) {
	    char tmp[50];
  	    sprintf(tmp,"%d-%d",t,t->superiorChild);
	    strcat(res,tmp);
  	    fprintf(fichier,"%d - %d;",t,t->superiorChild);
	    visualize_recTrie(t->superiorChild,fichier,res);
          }
        }
}
*/


