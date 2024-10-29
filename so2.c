#include <stdio.h>
#include <stdlib.h>

long long totalCombinar(int n) {
    // C(n + 2, 2) = (n + 2)(n + 1) / 2
    return (long long)(n + 2) * (n + 1) / 2;
}

void combination(int N) {
    long long total = totalCombinar(N);
    
    // Alocar espaço para as combinações
    int (*combinations)[3] = malloc(total * sizeof(*combinations));
    if (combinations == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return;
    }

    long long index = 0;

    // Preencher o vetor com combinações possíveis de l, e, o
    for (int l = 0; l <= N; l++) {
        for (int e = 0; e <= N - l; e++) {
            int o = N - l - e;
            combinations[index][0] = l;
            combinations[index][1] = e;
            combinations[index][2] = o;
            index++;
        }
    }

    // Imprimir as combinações
    for (long long calcula = 0; calcula < index; calcula++) {
        printf("l = %d, e = %d, o = %d\n", combinations[calcula][0], combinations[calcula][1], combinations[calcula][2]);
    }

    free(combinations);
}

int main() {
    int N = 100; // Definindo N como 100
    combination(N);  
    return 0;
}
