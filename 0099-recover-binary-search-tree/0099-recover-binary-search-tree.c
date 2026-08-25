/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, struct TreeNode** prev, struct TreeNode** first, struct TreeNode** second) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, prev, first, second);
    if (*prev != NULL && root->val < (*prev)->val) {
        if (*first == NULL) {
            *first = *prev;
        }
        *second = root;
    }
    *prev = root;
    inorder(root->right, prev, first, second);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *first = NULL, *second = NULL, *prev = NULL;
    inorder(root, &prev, &first, &second);
    if (first != NULL && second != NULL) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}