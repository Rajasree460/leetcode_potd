class Solution {
public:
    TreeNode* helper(TreeNode* root, unordered_map<int, int> &toDel, unordered_map<TreeNode*, int> &mp){
        if(!root) return NULL;
        
        root->left = helper(root->left, toDel, mp);
        root->right = helper(root->right, toDel, mp);
        
        if(toDel.count(root->val)){
            if(mp.count(root)) mp.erase(root);
			
			//store roots of new components in map
            if(root->left) mp[root->left]++;
            if(root->right) mp[root->right]++;
            
            //return null to break the tree as root is deleted
            return NULL;
        } 
        
        //if root is not present in to_delete return root
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<TreeNode*, int>mp;
        unordered_map<int,int>toDel;
        vector<TreeNode*>ans;
        mp[root]++;
        
        //store nodes values to be deleted in map
        for(auto it : to_delete) toDel[it]++;
        
        helper(root, toDel, mp);
        
        for(auto it : mp) ans.push_back(it.first);
        
        return ans;
    }
};
