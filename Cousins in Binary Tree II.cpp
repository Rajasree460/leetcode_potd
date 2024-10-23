// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
// struct TreeNode* replaceValueInTree(struct TreeNode* root) {
//     struct TreeNode* queue[100000];
//     int front = 0, rear = 0;
//     int sum = -1 * root->val, prevSum;

//     queue[rear++] = root;
    
//     while(front < rear) {
//         prevSum = sum;
//         sum = 0;
//         int end = rear;
        
//         while(front < end) {
//             queue[front]->val += prevSum;
//             int childrenSum = 0;

//             if(queue[front]->left) {
//                 queue[rear++] = queue[front]->left;
//                 childrenSum -= queue[front]->left->val;
//             }
//             if(queue[front]->right) {
//                 queue[rear++] = queue[front]->right;
//                 childrenSum -= queue[front]->right->val;
//                 queue[front]->right->val = childrenSum;
//             }
//             if(queue[front]->left) queue[front]->left->val = childrenSum;
//             sum -= childrenSum;
//             front++;
//         }
//     }

//     return root;
// }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Helper function to calculate the sum of each layer in the tree.
void calculateLayerSums(struct TreeNode* root, int depth, int* layerSums) {
    if (!root) return;
    
    // Dynamically extend layerSums if needed
    layerSums[depth] += root->val;
    
    calculateLayerSums(root->left, depth + 1, layerSums);
    calculateLayerSums(root->right, depth + 1, layerSums);
}

// Helper function to replace the value of each node
void replaceNodeValues(struct TreeNode* root, int depth, int* layerSums) {
    if (!root) return;

    int sumChildren = 0;
    if (root->left) sumChildren += root->left->val;
    if (root->right) sumChildren += root->right->val;

    if (root->left) 
        root->left->val = layerSums[depth + 1] - sumChildren;
    if (root->right) 
        root->right->val = layerSums[depth + 1] - sumChildren;

    replaceNodeValues(root->left, depth + 1, layerSums);
    replaceNodeValues(root->right, depth + 1, layerSums);
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    if (!root) return NULL;

    // Maximum possible depth of the tree.
    int layerSums[100002] = {0}; // Assuming the tree depth won't exceed 1000.

    // Step 1: Calculate the sum of each layer
    calculateLayerSums(root, 0, layerSums);

    // Step 2: Replace the values of the nodes
    replaceNodeValues(root, 0, layerSums);
    root->val = 0;
    return root;
}
