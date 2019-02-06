//appel du fichier d'entête
#include "etatPartie.h"

//###########################################
//FONCTION getNumeroTour
//*****************************************************************************************************//
//
// DESCRIPTION Retourne le numéro du tour en fonction de létat de la partie
//
// ENTREE / La réfèrence du type tEtatPartie
//
// SORTIE / Le int correspondant à la valeur du numéro du tour
//
// NOTE -
//*****************************************************************************************************//
int getNumeroTour(tEtatPartie *pstEtatPartie){
    return pstEtatPartie->nNumeroTour;
}

//###########################################
//FONCTION getNbCelluleVivante
//*****************************************************************************************************//
//
// DESCRIPTION Retourne le numéro du tour en fonction de létat de la partie
//
// ENTREE / La réfèrence du type tEtatPartie
//
// SORTIE / Le int correspondant au NbCelluleVivante
//
// NOTE -
//*****************************************************************************************************//

int getNbCelluleVivante(tEtatPartie *pstEtatPartie){
    return pstEtatPartie->nNbCelluleVivante;
}
//###########################################
//FONCTION setNumeroTour
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la valeur du numéro du tour
//
// ENTREE / La réfèrence du type tEtatPartie, le Numéro du tour
//
// SORTIE / Le type etatPartie modifié
//
// NOTE -
//*****************************************************************************************************//
void setNumeroTour(tEtatPartie *pstEtatPartie, const int nNumeroTour){
    pstEtatPartie->nNumeroTour = nNumeroTour;
}

//###########################################
//FONCTION setNbCelluleVivante
//*****************************************************************************************************//
//
// DESCRIPTION Modifie la valeur du Nb de cellule vivante dans une varbale de type tEtatParti
//
// ENTREE / La réfèrence du type tEtatPartie, le Nb de cellule vivante
//
// SORTIE / Le type etatPartie modifié
//
// NOTE -
//*****************************************************************************************************//
void setNbCelluleVivante(tEtatPartie *pstEtatPartie, const int nNbCelluleVivante){
    pstEtatPartie->nNbCelluleVivante = nNbCelluleVivante;
}

//###########################################
//FONCTION getCelluleGrilleEtatPartie
//*****************************************************************************************************//
//
// DESCRIPTION Retourne l'état de la cellule à partir d'une variable tEtatPartie
//
// ENTREE / La réfèrence du type tEtatPartie, les index nX et nY
//
// SORTIE / Le tCellule correspondant à l'etat de la cellule.
//
// NOTE -
//*****************************************************************************************************//
tCellule getCelluleGrilleEtatPartie(tEtatPartie *pstEtatPartie, const int nX, const int nY){
    return getCelluleGrille(pstEtatPartie->stGrille,nX,nY);
}

//###########################################
//FONCTION setCelluleGrilleEtatPartie
//*****************************************************************************************************//
//
// DESCRIPTION Retourne l'état de la cellule à partir d'une variable tEtatPartie
//
// ENTREE / La réfèrence du type tEtatPartie, les index nX et nY, la référence du type cellule
//
// SORTIE / Le type cellule modifié
//
// NOTE -
//*****************************************************************************************************//
void setCelluleGrilleEtatPartie(tEtatPartie *pstEtatPartie, const int nX, const int nY, const tCellule nVal){
    setCelluleGrille(pstEtatPartie->stGrille,nX,nY,nVal);
}
