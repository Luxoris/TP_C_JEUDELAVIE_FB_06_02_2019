//appel du fichier d'ent�te
#include "etatPartie.h"

//###########################################
//FONCTION getNumeroTour
//*****************************************************************************************************//
//
// DESCRIPTION Retourne le num�ro du tour en fonction de l�tat de la partie
//
// ENTREE / La r�f�rence du type tEtatPartie
//
// SORTIE / Le int correspondant � la valeur du num�ro du tour
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
// DESCRIPTION Retourne le num�ro du tour en fonction de l�tat de la partie
//
// ENTREE / La r�f�rence du type tEtatPartie
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
// DESCRIPTION Modifie la valeur du num�ro du tour
//
// ENTREE / La r�f�rence du type tEtatPartie, le Num�ro du tour
//
// SORTIE / Le type etatPartie modifi�
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
// ENTREE / La r�f�rence du type tEtatPartie, le Nb de cellule vivante
//
// SORTIE / Le type etatPartie modifi�
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
// DESCRIPTION Retourne l'�tat de la cellule � partir d'une variable tEtatPartie
//
// ENTREE / La r�f�rence du type tEtatPartie, les index nX et nY
//
// SORTIE / Le tCellule correspondant � l'etat de la cellule.
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
// DESCRIPTION Retourne l'�tat de la cellule � partir d'une variable tEtatPartie
//
// ENTREE / La r�f�rence du type tEtatPartie, les index nX et nY, la r�f�rence du type cellule
//
// SORTIE / Le type cellule modifi�
//
// NOTE -
//*****************************************************************************************************//
void setCelluleGrilleEtatPartie(tEtatPartie *pstEtatPartie, const int nX, const int nY, const tCellule nVal){
    setCelluleGrille(pstEtatPartie->stGrille,nX,nY,nVal);
}
