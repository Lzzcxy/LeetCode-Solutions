/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NODES 2000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * MAX_NODES);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_NODES);
    struct TreeNode* queue[MAX_NODES];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    int levelIndex = 0;
    while (front < rear) {
        int count = rear - front;
        (*returnColumnSizes)[levelIndex] = count;
        res[levelIndex] = (int*)malloc(sizeof(int) * count);
        for (int i = 0; i < count; i++) {
            struct TreeNode* curr = queue[front++];
            res[levelIndex][i] = curr->val;
            if (curr->left != NULL)  queue[rear++] = curr->left;
            if (curr->right != NULL) queue[rear++] = curr->right;
        }
        levelIndex++;
    }
    *returnSize = levelIndex;
    return res;
}