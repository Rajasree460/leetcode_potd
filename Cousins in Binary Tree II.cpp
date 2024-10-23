/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    struct TreeNode* queue[100000];
    int front = 0, rear = 0;
    int sum = -1 * root->val, prevSum;

    queue[rear++] = root;
    
    while(front < rear) {
        prevSum = sum;
        sum = 0;
        int end = rear;
        
        while(front < end) {
            queue[front]->val += prevSum;
            int childrenSum = 0;

            if(queue[front]->left) {
                queue[rear++] = queue[front]->left;
                childrenSum -= queue[front]->left->val;
            }
            if(queue[front]->right) {
                queue[rear++] = queue[front]->right;
                childrenSum -= queue[front]->right->val;
                queue[front]->right->val = childrenSum;
            }
            if(queue[front]->left) queue[front]->left->val = childrenSum;
            sum -= childrenSum;
            front++;
        }
    }

    return root;
}
