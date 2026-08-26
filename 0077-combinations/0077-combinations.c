/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    long long total = 1;
    for (int i = 1; i <= k; i++) {
        total = total * (n - i + 1) / i;
    }
    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;
    int* path = (int*)malloc(k * sizeof(int));
    int pathSize = 0;
    int cur = 1;
    while (pathSize > 0 || cur <= n - k + 1) {
        if (pathSize == k) {
            result[*returnSize] = (int*)malloc(k * sizeof(int));
            for (int i = 0; i < k; i++) {
                result[*returnSize][i] = path[i];
            }
            (*returnColumnSizes)[*returnSize] = k;
            (*returnSize)++;
            cur = path[--pathSize] + 1;
        } else if (cur <= n - (k - pathSize) + 1) {
            path[pathSize++] = cur;
            cur++;
        } else {
            if (pathSize == 0) break;
            cur = path[--pathSize] + 1;
        }
    }
    free(path);
    return result;
}