/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int maxCapacity = 150;
    int** result = (int**)malloc(maxCapacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCapacity * sizeof(int));
    *returnSize = 0;
    int path[10];
    int pathSize = 0;
    int cur = 1;
    int sum = 0;
    while (pathSize > 0 || cur <= 9) {
        if (pathSize == k) {
            if (sum == n) {
                result[*returnSize] = (int*)malloc(k * sizeof(int));
                for (int i = 0; i < k; i++) {
                    result[*returnSize][i] = path[i];
                }
                (*returnColumnSizes)[*returnSize] = k;
                (*returnSize)++;
            }
            sum -= path[--pathSize];
            cur = path[pathSize] + 1;
        } else if (cur <= 9 && sum + cur <= n && (9 - cur + 1) >= (k - pathSize)) {
            path[pathSize++] = cur;
            sum += cur;
            cur++;
        } else {
            if (pathSize == 0) break;
            sum -= path[--pathSize];
            cur = path[pathSize] + 1;
        }
    }
    return result;
}