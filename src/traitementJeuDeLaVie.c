//appel des bibliothèques et des fichiers d'en-tête
#include "traitementjeuDeLaVie.h"
#include "define.h"
#include <time.h>
#include <stdlib.h>


//###########################################
//PROCEDURE initGrille
//*****************************************************************************************************//
//
// DESCRIPTION Initialise les valeurs de la grille en fonction d'une constante de probabilité, ressort le nombre de cellule vivante à l'initialisation
//
// ENTREE /La grille, la référence du NbCelluleVivante
//
// SORTIE / La grille modifié
//
// NOTE -
//*****************************************************************************************************//
void initGrille(tGrille stGrille, int *pNbCelluleVivante){
    int nI=INDEX_MIN_GRILLE,nJ=INDEX_MIN_GRILLE;
    int fNbAlea=INIT_VAR;
    *pNbCelluleVivante = INIT_VAR;

    srand(time(NULL));  //initialisation de la fonction random
    for(nI=INDEX_MIN_GRILLE;nI<TAILLE_GRILLE;nI++){
       for(nJ=INDEX_MIN_GRILLE;nJ<TAILLE_GRILLE;nJ++){
            fNbAlea = rand()%101;   //appel de la fonction random
            if(fNbAlea<=PROBABILITE_CREATION){
                setCelluleGrille(stGrille,nI,nJ,vivante);
                *pNbCelluleVivante=*pNbCelluleVivante +1;
            }else{
                setCelluleGrille(stGrille,nI,nJ,morte);
            }

        }
    }
}

//###########################################
//PROCEDURE NbCelluleVivanteAutour
//*****************************************************************************************************//
//
// DESCRIPTION Ressort le nb de cellules vivantes autour de la cellule cible, s'arrête si ce nb a dépassé NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE ou NB_CELLULE_AUTOUR_NAITRE
//
// ENTREE /La grille, les coor nX et nY la référence du NbCelluleVivanteVivanteAutour
//
// SORTIE / Le NbdeCelluleVivanteAutour
//
// NOTE -
//*****************************************************************************************************//
void NbCelluleVivanteAutour(const tGrille stGrille,const int nX, const int nY, int *pNbCelluleVivanteAutour){
    int nI=(COOR_CASE_RECHERCHE_X-PORTEE_ANALYSE),nJ=(COOR_CASE_RECHERCHE_Y-PORTEE_ANALYSE);
    *pNbCelluleVivanteAutour = INIT_VAR;
    do{
        nJ=(COOR_CASE_RECHERCHE_Y-PORTEE_ANALYSE);
        do{
            if((!((nI==COOR_CASE_RECHERCHE_X)&&(nJ==COOR_CASE_RECHERCHE_Y)))&&(caseAppartientGrille(nX+nI,nY+nJ))&&(!(celluleEstMorte(stGrille[nX+nI][nY+nJ])))){
                *pNbCelluleVivanteAutour = *pNbCelluleVivanteAutour + 1;
            }
            nJ++;
        }while(nJ<=(COOR_CASE_RECHERCHE_Y+PORTEE_ANALYSE)&&(((*pNbCelluleVivanteAutour)<=NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE)||((*pNbCelluleVivanteAutour)<=NB_CELLULE_AUTOUR_NAITRE)));
        nI++;
    }while(nI<=(COOR_CASE_RECHERCHE_X+PORTEE_ANALYSE)&&(((*pNbCelluleVivanteAutour)<=NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE)||((*pNbCelluleVivanteAutour)<=NB_CELLULE_AUTOUR_NAITRE)));
}

//###########################################
//PROCEDURE testNouvelleEtat
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui sort le nouvelle etat de la cellule en fonction de son état précédent et du nombre de cellules autour.
//
// ENTREE /L'état de la cellule, l'état suivant de la cellule et le nombre de cellule vivante autour
//
// SORTIE / Le bouvelle etat
//
// NOTE -
//*****************************************************************************************************//
void testNouvelleEtat(const tCellule stCellulePrecedent,tCellule *pstCelluleSuivant,const int nNbCelluleVivanteAutour){
    if(celluleEstMorte(stCellulePrecedent)){
        if(nNbCelluleVivanteAutour==NB_CELLULE_AUTOUR_NAITRE){
            *pstCelluleSuivant=vivante;
        }else{
            *pstCelluleSuivant=morte;
        }
    }else{
        if((nNbCelluleVivanteAutour>=NB_MIN_CELLULE_AUTOUR_RESTER_ENVIE)&&(nNbCelluleVivanteAutour<=NB_MAX_CELLULE_AUTOUR_RESTER_ENVIE)){
            *pstCelluleSuivant=vivante;
        }else{
            *pstCelluleSuivant=morte;
        }
    }
}

//###########################################
//PROCEDURE etapeSuivante
//*****************************************************************************************************//
//
// DESCRIPTION Procedure qui créer la nouvelle grille et copie la nouvelle grille dans l'ancienne.
//
// ENTREE /La Grille et le nombre de cellule vivante autour
//
// SORTIE / La grille modifié
//
// NOTE -
//*****************************************************************************************************//
void etapeSuivante(tGrille stGrille, int *pnNbCelluleVivante){

    int nX=INIT_VAR, nY=INIT_VAR, nNbCelluleVivanteAutour=INIT_VAR;
    tGrille stNouvelleGrille;
    tCellule stEtatNouvelleCellule;
    *pnNbCelluleVivante =INIT_VAR;  //initialisation du nombre de cellules vivantes à INIT_VAR

    for(nX=INDEX_MIN_GRILLE;nX<TAILLE_GRILLE;nX++){
       for(nY=INDEX_MIN_GRILLE;nY<TAILLE_GRILLE;nY++){
            NbCelluleVivanteAutour(stGrille,nX,nY,&nNbCelluleVivanteAutour);
            testNouvelleEtat(getCelluleGrille(stGrille,nX,nY),&stEtatNouvelleCellule,nNbCelluleVivanteAutour);
            setCelluleGrille(stNouvelleGrille,nX,nY,stEtatNouvelleCellule);
            if(!(celluleEstMorte(stEtatNouvelleCellule))){  //incrémente le nombre de cellule vivnate si la cellule est vivante
                *pnNbCelluleVivante = *pnNbCelluleVivante + 1;
            }
        }
    }

    copieGrille(stNouvelleGrille,stGrille);
}
