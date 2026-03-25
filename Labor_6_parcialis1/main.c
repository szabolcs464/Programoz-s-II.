#include <stdio.h>
#include <stdlib.h>

int n, m;
int matrix[205][205];
int visited[205][205];
int max_length = -1;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void backtrack(int x, int y, int length) {
    if (x == n && y == m) {
        if (length > max_length) {
            max_length = length;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
            if (!visited[nx][ny] && matrix[nx][ny] >= matrix[x][y]) {
                visited[nx][ny] = 1;
                backtrack(nx, ny, length + 1);
                visited[nx][ny] = 0;
            }
        }
    }
}

int main() {
    FILE *fin = fopen("bemenet.txt", "r");
    if (fin == NULL) {
        printf("Hiba a fajl megnyitasakor!\n");
        return 1;
    }
    if (fscanf(fin, "%d %d", &n, &m) != 2) {
        fclose(fin);
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }

    fclose(fin);

    visited[1][1] = 1;

    backtrack(1, 1, 1);

    if (max_length == -1) {
        printf("nincs megoldas\n");
    } else {
        printf("%d\n", max_length);
    }

    return 0;
}