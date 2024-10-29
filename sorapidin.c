#include <stdio.h>
#define N 100

void combination(int N) {
    for (int l = 0; l <= N; l++) {
        for (int e = 0; e <= N - l; e++) {
            int o = N - l - e;
            printf("l = %d, e = %d, o = %d\n", l, e, o);
        }
    }
}

int main() {
    
    combination(N);  
    return 0;
}
