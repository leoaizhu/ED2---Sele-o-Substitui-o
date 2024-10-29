#include <stdio.h>
#include <stdlib.h>
#define N 10

int fatorialFunc(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i; 
    }
    return result;
}

int totalCombinar(int n) {
    return fatorialFunc(n + 2) / (fatorialFunc(2) * fatorialFunc(n));
}

void combination() {
    int l, e, o;

    int total = totalCombinar(N);

    int (*combinations)[3] = malloc(total * sizeof(*combinations));
    if (combinations == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return;
    }

    int index = 0;

    for (l = 0; l <= N; l++) {
        for (e = 0; e <= N - l; e++) {
            o = N - l - e; // Calcula k diretamente
            combinations[index][0] = l;
            combinations[index][1] = e;
            combinations[index][2] = o;
            index++;
        }
    }

    for (int calcula = 0; calcula < index; calcula++) {
        printf("i = %d, j = %d, k = %d\n", combinations[calcula][0], combinations[calcula][1], combinations[calcula][2]);
    }

    free(combinations);
}


int main() {
    combination();  
    return 0;
}
