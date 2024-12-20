/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
#define swap(x, y) { int tmp=(x); (x)=(y); (y)=tmp; }
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    TreeNode* q[1<<14];
    int front=0, back=0;
    q[back++]=root;
    bool rev=0;
    while(front<back){
        int qz=back-front;
        TreeNode** arr=alloca(qz*sizeof(TreeNode*));
        for(int i=0; i<qz; i++){
            TreeNode* Node=q[front++];
            if (Node->left) q[back++]=Node->left;
            if (Node->right) q[back++]=Node->right;
            if (rev){
                arr[i]=Node;
                if (i>=qz/2)
                    swap(arr[i]->val, arr[qz-1-i]->val); 
            }
        }
        rev=!rev;
    }
    return root;
}
