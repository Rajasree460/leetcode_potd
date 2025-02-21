/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int* ary;
} FindElements;

void Traverse(FindElements* Ele, struct TreeNode* root){
    if(root->left){
        root->left->val = root->val*2+1;
        Ele -> ary[root->left->val] = 1;
        Traverse(Ele , root->left);
    }
    if(root->right){
        root->right->val = root->val*2+2;
        Ele -> ary[root->right->val] = 1;
        Traverse(Ele , root->right);
    }
}

FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements* E = (FindElements*)malloc(sizeof(FindElements));
    E -> ary = (int*) calloc(1048576,sizeof(int)); // 2^20
    int i;
    E -> ary[0]=1;
    root->val=0;
    Traverse(E, root);
    return E;
}

bool findElementsFind(FindElements* obj, int target) {
    if(obj->ary[target]==1)return true;
    return false;
}

void findElementsFree(FindElements* obj) {
    free(obj->ary);
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
