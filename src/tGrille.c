//appel des biblioth�ques et des fichiers d'en-t�te
#include "tGrille.h"

//###########################################
//FONCTION caseAppartientGrille
//*****************************************************************************************************//
//
// DESCRIPTION V�ifie si les coordonn�es en entr�e sont valide, cad qu'elles appartiennent � la grille
//
// ENTREE / La coordonn�e en X, la coordonn�e en Y
//
// SORTIE /Un bool�een (sert de r�ponse au test)
//
// NOTE -
//*****************************************************************************************************//
tBool caseAppartientGrille(const int nX, const int nY){
    if((nX>=INDEX_MIN_GRILLE&&nX<TAILLE_GRILLE)&&(nY>=INDEX_MIN_GRILLE&&nY<TAILLE_GRILLE)){
        return true;
    }else{
        return false;
    }
}

//###########################################
//FONCTION getCelluleGrille
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui renvoie la valeur correspondant � aux coordonn�es en X et Y du tableau de type tGrille.
//
// ENTREE / La coordonn�e en X, la coordonn�e en Y, la matrice de type grille
//
// SORTIE / L'�tat de la cellule
//
// NOTE -
//*****************************************************************************************************//
tCellule getCelluleGrille(const tGrille stGrille, const int nX, const int nY){
    return stGrille[nX][nY];
}

//###########################################
//FONCTION setCelluleGrille
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui modifie la valeur d'une cellule dans la grille
//
// ENTREE / La coordonn�e en X, la coordonn�e en Y, la matrice de type grille, la valeur affecter
//
// SORTIE / La grille modifi�
//
// NOTE -
//*****************************************************************************************************//
void setCelluleGrille(tGrille stGrille, const int nX, const int nY, const tCellule nVal){
    stGrille[nX][nY]=nVal;
}

//###########################################
//FONCTION copieGrille
//*****************************************************************************************************//
//
// DESCRIPTION Fonction qui copie les valeurs d'un type grille � un autre
//
// ENTREE /Les deux grilles
//
// SORTIE / La grille modifi�
//
// NOTE -
//*****************************************************************************************************//
void copieGrille(const tGrille stGrille, tGrille stGrilleCopie){
    int nI=INDEX_MIN_GRILLE,nJ=INDEX_MIN_GRILLE;
    for(nI=INDEX_MIN_GRILLE;nI<TAILLE_GRILLE;nI++){
       for(nJ=INDEX_MIN_GRILLE;nJ<TAILLE_GRILLE;nJ++){
            stGrilleCopie[nI][nJ]=stGrille[nI][nJ];
        }
    }
}
