/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(char* s, int start, int len, bool dp[20][20], char** path, int pathLen, 
         char**** ans, int** colSizes, int* returnSize, int* capacity) {
    if (start == len) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *ans = realloc(*ans, sizeof(char**) * (*capacity));
            *colSizes = realloc(*colSizes, sizeof(int) * (*capacity));
        }
        char** copy = malloc(sizeof(char*) * pathLen);
        for (int i = 0; i < pathLen; i++) {
            copy[i] = strdup(path[i]);
        }
        (*ans)[*returnSize] = copy;
        (*colSizes)[(*returnSize)++] = pathLen;
        return;
    }
    for (int j = start; j < len; j++) {
        if (dp[start][j]) {
            int subLen = j - start + 1;
            char subStr[subLen + 1];
            strncpy(subStr, s + start, subLen);
            subStr[subLen] = '\0';

            path[pathLen] = subStr;
            dfs(s, j + 1, len, dp, path, pathLen + 1, ans, colSizes, returnSize, capacity);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s), capacity = 1000;
    bool dp[20][20] = {false};
    for (int j = 0; j < len; j++) {
        for (int i = 0; i <= j; i++) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
            }
        }
    }
    *returnSize = 0;
    char*** ans = malloc(sizeof(char**) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    char* path[len];
    dfs(s, 0, len, dp, path, 0, &ans, returnColumnSizes, returnSize, &capacity);
    return ans;
}