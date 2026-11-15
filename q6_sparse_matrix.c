/* Q6: Sparse matrix using arrays (triplet representation) */
#include <stdio.h>

int main() {
    int r, c, a[10][10], t[100][3], k = 1;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) { t[k][0] = i; t[k][1] = j; t[k][2] = a[i][j]; k++; }
        }
    t[0][0] = r; t[0][1] = c; t[0][2] = k - 1;

    printf("\nSparse representation (row col value):\n");
    for (int i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);
    return 0;
}
