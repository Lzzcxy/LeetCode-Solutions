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
void helper(struct TreeNode* root, int* res, int* returnSize) {
    if (root == NULL) {
        return;
    }
    helper(root->left, res, returnSize);
    res[(*returnSize)++] = root->val;
    helper(root->right, res, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * 2000);
    helper(root, res, returnSize);
    return res;
}