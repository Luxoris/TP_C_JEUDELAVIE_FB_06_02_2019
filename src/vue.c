#include "vue.h"
#include <stdio.h>
#include <stdlib.h>


//###########################################
//PROCEDURE choix menu principal
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche l'invite de choix du joueur et renvoie un char correpondant à son choix.
//
// ENTREE /La reference du char
//
// SORTIE / Le char modifié
//
// NOTE -
//*****************************************************************************************************//
void choixMenuPrincipal(char *pcnMenu){
    char cMenu='\0';
    do{
        printf("'n' Nouvelle Partie\n'Entrer' Avancer\n's' Sauvegarder\n'c' Charger sauvegarde\n'l' Lire les etats de la partie\n\n'q' Quitter\n");
        fflush(stdin);
        scanf("%c",&cMenu);
    }while(cMenu!='a'&&cMenu!='n'&&cMenu!='q'&&cMenu!=10&&cMenu!='s'&&cMenu!='c'&&cMenu!='l');
    *pcnMenu = cMenu;
}

//###########################################
//PROCEDURE afficheGrille
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche la grille.
//
// ENTREE /La grille
// SORTIE / L'affichage
//
// NOTE -
//*****************************************************************************************************//
void afficheGrille(const tGrille stGrille){
    int nI=INDEX_MIN_GRILLE,nJ=INDEX_MIN_GRILLE;
    system("cls");
    for(nI=INDEX_MIN_GRILLE;nI<TAILLE_GRILLE;nI++){
       for(nJ=INDEX_MIN_GRILLE;nJ<TAILLE_GRILLE;nJ++){
            if(celluleEstMorte(getCelluleGrille(stGrille,nI,nJ))){
                putchar(' ');
            }else{
                putchar('o');
            }
            putchar('|');
        }
        putchar('\n');
    }
}

//###########################################
//PROCEDURE afficheEtatPartie
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche l'etat de la partie
//
// ENTREE /Le numero du tour, le nb de cellule
//
// SORTIE / L'affichage du nb de tour et du nb de cellule
//
// NOTE -
//*****************************************************************************************************//
void afficheEtatPartie(const int nNumeroTour,const int nNbCelluleVivante){
    printf("Tour n%d, nombre de cellules vivantes : %d\n",nNumeroTour,nNbCelluleVivante);
}

//###########################################
//PROCEDURE afficheEtatPartie
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche l'etat de la manipulation des fichiers
//
// ENTREE /Le code correspondant à l'etat de la manipulation
//
// SORTIE / L'affichage du message correspondant
//
// NOTE -
//*****************************************************************************************************//
void afficheEtatManipulationFichier(const int nCode){
    system("cls");
    switch(nCode){
    case -1: printf("Echec de création du fichier de sauvegarde #%d\n",nCode);
            system("pause");
            break;
    case -2: printf("Fichier de sauvegarde introuvable #%d\n",nCode);
            system("pause");
            break;
    case 1: printf("Sauvegarde terminee !\n");
            system("pause");
            break;
    case 2: printf("Chargement terminee !\n");
            system("pause");
            break;
    /*case 3: printf("Sauvegarde fichier texte réussi!\n");
            system("pause");
            break;*/
    case -3: printf("Fichier introuvable !\n");
            system("pause");
            break;
    case -61: printf("Fichier a copier introuvable !\n");
            system("pause");
            break;
    case -62: printf("Acces impossible en ecriture au fichier copie !\n");
            system("pause");
            break;
    case 6: printf("Copie fichier reussi!\n");
            system("pause");
            break;
    case -5: printf("Suppression impossible !\n");
            system("pause");
            break;
    /*case 5: printf("Suppression reussi!\n");
            system("pause");
            break;*/
    case -4: printf("Erreur lors de la lecture du fichier texte !\n");
            system("pause");
            break;
    /*case 4: printf("Affichage reussi!\n");
            system("pause");
            break;*/
    }

}

//###########################################
//FONCTION afficheEtatPartie
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui affiche a l'écran les données stocker dans le fichier texte
//
// ENTREE /Le chemin du fichier texte
//
// SORTIE / L'affichage des messages, le code d'erreur
//
// NOTE -
//*****************************************************************************************************//
int afficheFichierText(const char cCheminFichier[]){
    FILE *pFile;
    int nI=INIT_VAR, nNumeroTour=INIT_VAR, nNbCelluleVivante=INIT_VAR;
    char cChar='0';
    if((pFile = fopen(cCheminFichier,"r"))==NULL){
        return -4;
    }else{
        system("cls");
        printf("Lecture du fichier : \n");
        while(fgetc(pFile)!=EOF){
            fscanf(pFile,"%d",&nNumeroTour);
            cChar = fgetc(pFile);
            cChar = fgetc(pFile);
            fscanf(pFile,"%d",&nNbCelluleVivante);
            cChar = fgetc(pFile);
            cChar = fgetc(pFile);
            afficheEtatPartie(nNumeroTour,nNbCelluleVivante);
        nI++;
        }
        cChar = cChar+1;
        fclose(pFile);
        system("pause");
        return 4;
    }

}
