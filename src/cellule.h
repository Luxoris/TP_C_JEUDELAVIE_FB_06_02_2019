#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED
#pragma once

//inclusion des headers
#include "tBool.h"

//nouveau type enuméré correspondant à l'état d'une cellule
typedef enum tCellule{morte,vivante} tCellule;

//prototype de la méthode
extern tBool celluleEstMorte(const tCellule stCellule);

#endif // CELLULE_H_INCLUDED
