//appel des biblioth�ques et des fichiers d'en-t�te
#include "fichier.h"
#include <stdlib.h>
#include <stdio.h>

//###########################################
//FONCTION sauvegardePartie
//*****************************************************************************************************//
//
// DESCRIPTION Sauvegarde l'�tat de la partie
//
// ENTREE / La r�f�rence du type tEtatPartie et la chaine de cract�re correspondant au fichier
//
// SORTIE / Le fichier binaire correspondant � la sauvegarde, le code (int) correspondant � la gestion des erreurs
//
// NOTE -
//*****************************************************************************************************//
int sauvegardePartie(const char cCheminFichier[],const tEtatPartie *pstEtatPartie){
    FILE *pFile;

    if((pFile = fopen(cCheminFichier,"wb"))==NULL){
        return -1;  //si �chec de modification du fichier, renvoie le code -1
    }else{
        fwrite(pstEtatPartie,sizeof(*pstEtatPartie),1,pFile);
        fclose(pFile);
        return 1; //code signifiant que la fonction s'est ex�cut� correctement
    }
}

//###########################################
//FONCTION chargementPartie
//*****************************************************************************************************//
//
// DESCRIPTION Charge l'etat de la partie
//
// ENTREE / La r�f�rence du type tEtatPartie et la chaine de cract�re correspondant au fichier, le fichier binaire correspondant au fichier de sauvegarde
//
// SORTIE / Le fichier binaire correspondant � la sauvegarde, le code (int) correspondant � la gestion des erreurs
//
// NOTE -
//*****************************************************************************************************//
int chargementPartie(const char cCheminFichier[],tEtatPartie *pstEtatPartie){
    FILE *pFile;

    if((pFile = fopen(cCheminFichier,"rb"))==NULL){
        return -2;  //retourne -2 si le fichier est introuvable.
    }else{
        fread(pstEtatPartie,sizeof(*pstEtatPartie),1,pFile);
        fclose(pFile);
        return 2; //code signifiant que la fonction s'est ex�cut� correctement
    }

}

//###########################################
//FONCTION ajoutFichierTexte
//*****************************************************************************************************//
//
// DESCRIPTION ajoute le num�ro de tour et le nb de cellule vivante correspondant
//
// ENTREE / La valeur du num�ro du tour, le nb de cellule la chaine correspondnat au chemin du fichier.
//
// SORTIE /Le fichier texte modifi�
//
// NOTE -
//*****************************************************************************************************//
int ajoutFichierTexte(const char cCheminFichier[],const int nNumeroTour,const int nNbCelluleVivante){
    FILE *pFile;

    if((pFile = fopen(cCheminFichier,"a"))==NULL){
        return -3;  //code correspondant � une erreur d'acc�s au fichier
    }else{
        fprintf(pFile," %d : %d ;",nNumeroTour,nNbCelluleVivante);
        fclose(pFile);
        return 3;   //code signifiant que la fonction s'est ex�cut� correctement
    }

}


//###########################################
//FONCTION copieFichierText
//*****************************************************************************************************//
//
// DESCRIPTION Copie le contenu d'un fichier texte dans un autre fichier texte.
//
// ENTREE / Les chemins des deux fichiers � modifi�, les fichier
//
// SORTIE /Le fichier texte mis � jour, le code erreur
//
// NOTE -
//*****************************************************************************************************//
extern int copieFichierText(const char cCheminFichierCopie[], const char cCheminFichier[]){
    FILE *pFileCopie, *pFile;
    char cString[255];;
    if((pFile = fopen(cCheminFichier,"r"))==NULL){
        return -61; //code correspondant � un fichier introuvable
        }else if((pFileCopie = fopen(cCheminFichierCopie,"w"))==NULL){
            return -62; //code correspondant � un acc�s impossible au fichier
        }else{
            while((fgets(cString,255,pFile))!=NULL){
                fputs(cString,pFileCopie);
                }
            fclose(pFileCopie);
            fclose(pFile);
            return 6;//code signifiant que la fonction s'est ex�cut� correctement
        }
}


//###########################################
//FONCTION supprimerFichier
//*****************************************************************************************************//
//
// DESCRIPTION Supprime un fichier
//
// ENTREE / Le chemin du fichier
//
// SORTIE /Le fichier supprimer
//
// NOTE -
//*****************************************************************************************************//
extern int supprimerFichier(const char cCheminFichier[]){
    if(remove(cCheminFichier)!= 0 ){
        return -5;  //code signifiant que la suppression est impossible
    }else{
        return 5;//code signifiant que la fonction s'est ex�cut� correctement
    }
}
