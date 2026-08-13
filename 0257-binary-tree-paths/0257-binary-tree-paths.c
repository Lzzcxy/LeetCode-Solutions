/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(struct TreeNode* node, int* path, int pathLen, char** result, int* returnSize) {
    if (node == NULL) return;
    path[pathLen++] = node->val;
    if (node->left == NULL && node->right == NULL) {
        char* buffer = (char*)malloc(sizeof(char) * (pathLen * 20));
        buffer[0] = '\0';  
        for (int i = 0; i < pathLen; i++) {
            char temp[12];
            sprintf(temp, "%d", path[i]);
            strcat(buffer, temp);
            if (i < pathLen - 1) {
                strcat(buffer, "->");
            }
        } 
        result[(*returnSize)++] = buffer;
        return;
    }
    dfs(node->left, path, pathLen, result, returnSize);
    dfs(node->right, path, pathLen, result, returnSize);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    char** result = (char**)malloc(sizeof(char*) * 1000);
    int path[1000];
    dfs(root, path, 0, result, returnSize);
    return result;
}