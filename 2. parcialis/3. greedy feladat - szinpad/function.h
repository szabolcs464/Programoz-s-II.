//
// Created by nadys on 5/13/2026.
//

#ifndef INC_3_GREEDY_FELADAT_SZINPAD_FUNCTION_H
#define INC_3_GREEDY_FELADAT_SZINPAD_FUNCTION_H

typedef struct {
    int kezd;
    int vege;
} Koncert;

void sorba_rendez_vege_szerint(Koncert koncertek[], int darab);
int maximum_koncert(Koncert koncertek[], int darab);

#endif //INC_3_GREEDY_FELADAT_SZINPAD_FUNCTION_H