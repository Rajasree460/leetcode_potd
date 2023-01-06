class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        map<int,int>mp;
        for(int i:nums){
            ++mp[i];

        }
        for(auto it:mp){
            if(it.second>n/3){
                res.push_back(it.first);
            }



        }
        return res;
    }
};
