#include "cellule.h"

//###########################################
//FONCTION celluleEstMorte
//*****************************************************************************************************//
//
// DESCRIPTION Vérifie l'état d'un type cellule et renvoie un booléen correpsondant à l'état de la cellule. true si morte
//
// ENTREE / La valeur de type tCellule
//
// SORTIE / Le Boolééen correspodnat au test
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
