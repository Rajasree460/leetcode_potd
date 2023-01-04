class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        map<int,int>mp;
        int ans=0;
        for(int i:tasks){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second==1) return -1;
            else if(i.second%3==0)  ans+=i.second/3;
            else ans+=i.second/3+1;

        }
        return ans;
    }
};
