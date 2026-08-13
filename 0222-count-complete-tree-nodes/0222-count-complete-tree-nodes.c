/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = 0;
    struct TreeNode* l = root->left;
    while (l != NULL) {
        leftHeight++;
        l = l->left;
    }
    int rightHeight = 0;
    struct TreeNode* r = root->right;
    while (r != NULL) {
        rightHeight++;
        r = r->left;
    }
    if (leftHeight == rightHeight) {
        return (1 << leftHeight) + countNodes(root->right);
    } 
    else {
        return (1 << rightHeight) + countNodes(root->left);
    }
}