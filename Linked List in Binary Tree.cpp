/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkSubpath(struct TreeNode* root, struct ListNode* head){
    // this function checks if the linked list is there with a 
    // particular node with the same value as the head node 

    // this function needs to be recursive

    if(!head) return true; 
    if (!root) return false; 

    if (root->val == head->val){
        return checkSubpath(root->left, head->next) || checkSubpath(root->right, head->next);
    }
    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    // I could do pre-order traversal as well 
    if (!head) return false; 
    if (!root) return false; 

    if (root->val == head->val){
        if(checkSubpath(root, head)) return true; 
    }
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}
