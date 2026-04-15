//
// Created by nadys on 4/1/2026.
//

#ifndef INC_1__FELADAT___KINCSKERESO_FUNCTIONS_H
#define INC_1__FELADAT___KINCSKERESO_FUNCTIONS_H

#include <stdbool.h>

#define MERET 5

void kiir_palya(int palya[MERET][MERET]);

int keres(int palya[MERET][MERET], int latogatott[MERET][MERET], int sor, int oszlop, int gomba_db);

#endif //INC_1__FELADAT___KINCSKERESO_FUNCTIONS_H