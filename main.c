#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

int maxSqure(int n, int m, int (*a)[m])
{
    int b[n][m], maxL = 0, t;
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ",*(*(a + i) + j));
        }
        putchar('\n');
    }
    */
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            t = (*(*(a + i) + j)) ? 0 : min((i != 0) ? *(*(b + i - 1) + j) : 0, (j != 0) ? *(*(b + i) + j - 1) : 0, (i !=0 && j != 0) ? *(*(b + i - 1) + j - 1) : 0) + 1;
            *(*(b + i) + j) = t;
            if (t > maxL) maxL = t;
        }
    }
    /*
    putchar('\n');
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ",*(*(b + i) + j));
        }
        putchar('\n');
    }
    */
    return maxL * maxL;
}

int main()
{
    //freopen("map", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", (*(a+i)+j));

    printf("%d\n", maxSqure(n, m, a));
    return 0;
}
