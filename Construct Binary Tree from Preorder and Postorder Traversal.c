/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;

void traverse(TreeNode *node, int nodeLength, int *preorder, int *preorderIndex, int *postorder, int *postorderIndex)
{
  int curPreIndex = (*preorderIndex), curPostIndex = (*postorderIndex);
  if (nodeLength <= curPreIndex || nodeLength <= curPostIndex)
    return; // all node are set

  if (postorder[curPostIndex] == node->val)
  {
    (*postorderIndex) = curPostIndex + 1;
    return;
  }

  // set next preorder node as left child
  node->left = (TreeNode *)calloc(1, sizeof(TreeNode));
  node->left->val = preorder[curPreIndex];
  (*preorderIndex) = curPreIndex + 1;
  traverse(node->left, nodeLength, preorder, preorderIndex, postorder, postorderIndex);

  curPreIndex = (*preorderIndex);
  curPostIndex = (*postorderIndex);
  if (nodeLength <= curPreIndex || nodeLength <= curPostIndex)
    return; // all node are set

  if (postorder[curPostIndex] != node->val)
  {
    // set next preorder node as right child
    node->right = (TreeNode *)calloc(1, sizeof(TreeNode));
    node->right->val = preorder[curPreIndex];
    (*preorderIndex) = curPreIndex + 1;
    traverse(node->right, nodeLength, preorder, preorderIndex, postorder, postorderIndex);

    if (nodeLength <= (*preorderIndex) || nodeLength <= (*postorderIndex))
      return; // all node are set
  }

  (*postorderIndex) = (*postorderIndex) + 1;
  return;
}

struct TreeNode *constructFromPrePost(int *preorder, int preorderSize, int *postorder, int postorderSize)
{
  int preorderIndex = 1, postorderIndex = 0;
  TreeNode *ans = (TreeNode *)calloc(1, sizeof(TreeNode));
  ans->val = preorder[0];

  traverse(ans, preorderSize, preorder, &preorderIndex, postorder, &postorderIndex);
  return ans;
}
