#include "cellule.h"

//###########################################
//FONCTION celluleEstMorte
//*****************************************************************************************************//
//
// DESCRIPTION V�rifie l'�tat d'un type cellule et renvoie un bool�en correpsondant � l'�tat de la cellule. true si morte
//
// ENTREE / La valeur de type tCellule
//
// SORTIE / Le Bool��en correspodnat au test
//
// NOTE -
//*****************************************************************************************************//

tBool celluleEstMorte(const tCellule stCellule){
    if(stCellule==vivante){
        return false;
    }else{
        return true;
    }
}
