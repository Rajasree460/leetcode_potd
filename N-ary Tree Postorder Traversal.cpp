/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postorderHelper(struct Node* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {
        postorderHelper(root->children[i], result, returnSize);
    }
    result[(*returnSize)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(10000 * sizeof(int)); // Assuming a maximum of 10000 nodes
    postorderHelper(root, result, returnSize);
    return result;
}
