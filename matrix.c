#include <stdlib.h>
#include <stdio.h>
#define N 2
#define M 3

int scorrimatrice(int n, int m, int a[n][m]) {
    if (m > n) { 
        int vecchiomaxindex = -1;

        for(int i = 0; i < n; i++) {
            int rigamax = a[i][0];
            int maxindex = 0;

            for(int j = 1; j < m; j++) {
                if (rigamax < a[i][j]) {
                    rigamax = a[i][j];
                    maxindex = j;
                }
            }

            if (maxindex <= vecchiomaxindex) {
                return 1;
            } 

            vecchiomaxindex = maxindex; 
        }
    } else printf("M è minore di N");

    return 0;
}

int main()
{
    int a[N][M] = {{4, 1, 2},
                   {1, 4, 2}};

    printf("%d", scorrimatrice(N, M, a)); 
    
    return 0;
}