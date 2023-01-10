class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true; //1st condition that both trees are empty
        if(p==NULL||q==NULL) return false;//2nd condition that one of them is empty
        return(p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
   
    }
};
