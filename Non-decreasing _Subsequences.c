class Solution {
public:
    // function to find all unique sub sequences
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans; // use a vector to store the unique sub sequences
        vector<int> path;
        dfs(nums, 0, path, ans);
        return ans;
    }

private:
    // function to find sub sequences recursively
    void dfs(vector<int>& nums, int s, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() > 1)
            ans.push_back(path);
        unordered_set<int> used;
        for (int i = s; i < nums.size(); ++i) {
            // check if the current element has been used before
            if (used.count(nums[i]) > 0)
                continue;
            // check if the path is empty or the current element is greater than or equal to the last element in the path
            if (path.empty() || nums[i] >= path.back()) {
                used.insert(nums[i]); // add the current element to the used
                path.push_back(nums[i]);
                dfs(nums, i + 1, path, ans); // recursively call dfs without adding the current element to the path
                path.pop_back(); // remove the last element from the path before returning
            }
        }
    }
};
