#include <stdio.h>
#include "function.h"

int main() {
    // Időpontok percekben kifejezve
    Koncert koncertek[] = {
        {600, 660}, // 10:00 - 11:00
        {630, 690}, // 10:30 - 11:30 (ütközik az elsővel)
        {660, 720}, // 11:00 - 12:00
        {700, 780}, // 11:40 - 13:00
        {720, 840}  // 12:00 - 14:00
    };
    int darab = 5;

    int eredmeny = maximum_koncert(koncertek, darab);

    printf("A szinpadra maximum %d koncert fer be.\n", eredmeny);

    return 0;
}