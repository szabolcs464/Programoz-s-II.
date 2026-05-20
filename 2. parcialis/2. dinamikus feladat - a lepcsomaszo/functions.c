//
// Created by nadys on 5/13/2026.
//

#include "functions.h"

int modok_szama(int lepcsofokok) {
    int dp[100];
    int i;

    if (lepcsofokok == 1) {
        return 1;
    }
    if (lepcsofokok == 2) {
        return 2;
    }
    if (lepcsofokok == 3) {
        return 4;
    }

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // A 4. foktól kezdve egyszerűen összeadjuk az előző hármat
    for (i = 4; i <= lepcsofokok; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[lepcsofokok];
}