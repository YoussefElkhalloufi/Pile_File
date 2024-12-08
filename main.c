#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element{
    int valeur;
    Element *suivant;
};

typedef struct Pile Pile;
struct Pile{
    int longueur;
    Element *tete;
};

typedef struct File File;
struct File{
    int longueur;
    Element *tete;
};


Pile *initialize(int valeur){
    Pile *pile = malloc(sizeof(Pile));
    Element *element = malloc(sizeof(Element));
    element->valeur = valeur;
    element->suivant = NULL;

    pile->tete = element;
    pile->longueur = 1;

    return pile;
}


void empiler(Pile *pile, int valeur){
    if(pile == NULL) return ;

    Element *element = malloc(sizeof(Element));
    element->valeur = valeur;
    element->suivant = pile->tete ;
    pile->tete = element;

    pile->longueur++;
}

int depiler(Pile *pile){
    if(pile == NULL || pile->tete == NULL) return ;

    int nbDepiler ;

        Element *a_depiler = pile->tete;
        nbDepiler = a_depiler->valeur;
        pile->tete = a_depiler->suivant;
        free(a_depiler);

        pile->longueur--;
    return nbDepiler;

}

void afficherPile(Pile *pile){
    if(pile == NULL) return;

    Element *tmp = pile->tete;
    while(tmp != NULL){
        printf(" %d -> ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}


//-------------------------------------------------------FILE----------------------------------------------------------------

File *initiliaze(int valeur){
    File *file = malloc(sizeof(File));
    Element *element = malloc(sizeof(Element));

    element->suivant= NULL;
    element->valeur= valeur;
    file ->tete= element;
    file->longueur = 1;
    return file;
}


void enfiler(File *file, int valeur){
    if(file == NULL) return ;

    Element *element = malloc(sizeof(Element));
    element->valeur=valeur;
    element->suivant = NULL;

    if(file->tete != NULL){
        Element *tmp = file->tete;
        while(tmp->suivant!=NULL){
            tmp = tmp->suivant;
        }
        tmp->suivant = element;
    }else{
        file->tete = element;
    }

    file->longueur++;
}


int defiler(File *file){
    if(file == NULL)return;

    int defiler ;

    Element *a_defiler = file->tete;
    defiler = a_defiler->valeur;
    file->tete = a_defiler->suivant;
    free(a_defiler);

    file->longueur--;
    return defiler;
}



void afficherFile(File *file){
    if(file == NULL) return;

    Element *tmp = file->tete;
    while(tmp != NULL){
        printf(" %d -> ", tmp->valeur);
        tmp = tmp->suivant;
    }
    printf("NULL\n");
}


int main(){

    Pile *pile = initialize(10);
    empiler(pile, 20);
    empiler(pile, 30);
    empiler(pile, 40);
    empiler(pile, 50);
    empiler(pile, 60);

    printf("Affichage apres empilation de 10, 20, 30, 40, 50 et 60 :\n\t");
    afficherPile(pile);
    printf("\tLa longueur de la pile est : %d", pile->longueur);


    printf("\n\nAffichage apres depilage de : %d\n\t", depiler(pile));
    afficherPile(pile);
    printf("\tLa longueur de la pile est : %d", pile->longueur);




    printf("\n\n---------------------------------------------------------------------------------------------\n\n");

    File *file = initialize(10);
    enfiler(file, 20);
    enfiler(file, 30);
    enfiler(file, 40);
    enfiler(file, 50);
    enfiler(file, 60);

    printf("Affichage apres enfilation de 10, 20, 30, 40, 50 et 60 :\n\t");
    afficherFile(file);
    printf("\tLa longueur de la file est : %d", file->longueur);

    printf("\n\nAffichage apres defilage de : %d\n\t", defiler(file));
    afficherFile(file);
    printf("\tLa longueur de la file est : %d", file->longueur);
}
