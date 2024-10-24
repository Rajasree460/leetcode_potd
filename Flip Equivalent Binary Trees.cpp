/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Function to check if two trees are flip equivalent
bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2) {
    // If both nodes are NULL, they are trivially equivalent (empty trees)
    if(root1==NULL && root2==NULL){
        return true;
    }
    
    // If one node is NULL and the other isn't, they are not equivalent
    if(root1==NULL || root2==NULL){
        return false;
    }
    
    // If the values of the current nodes are not the same, trees aren't equivalent
    if(root1->val!=root2->val){
        return false;
    }

    // Check two possibilities:
    // 1. Compare left with left and right with right without flipping
    // 2. Compare left with right and right with left (flipping)

    // First, check if children are equivalent without flipping
    bool noFlip=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
    // Second, check if children are equivalent with flipping
   bool flip=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);

    // Return true if either of the possibilities results in equivalence
    return flip || noFlip;
}
