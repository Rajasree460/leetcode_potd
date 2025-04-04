/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findDepth(struct TreeNode* root){
    if(!root)   return 0;
    int left=findDepth(root->left);
    int right=findDepth(root->right);
    return (left>right)?(left+1):(right+1);
}
struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    if(!root)   return root;
    int leftDepth=findDepth(root->left);
    int rightDepth=findDepth(root->right);
    if(leftDepth==rightDepth)   return root;
    return (leftDepth>rightDepth)?(lcaDeepestLeaves(root->left)):(lcaDeepestLeaves(root->right));
}
