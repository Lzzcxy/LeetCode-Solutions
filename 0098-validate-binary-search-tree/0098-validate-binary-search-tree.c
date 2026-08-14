/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    struct TreeNode* stack[10000];
    int top = -1;
    struct TreeNode* curr = root;
    long long prevVal = -9223372036854775807LL - 1;
    bool isFirst = true;
    while (curr != NULL || top >= 0) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }      
        curr = stack[top--];        
        if (!isFirst && curr->val <= prevVal) {
            return false;
        }
        isFirst = false;
        prevVal = curr->val;
        curr = curr->right;
    }
    return true;
}