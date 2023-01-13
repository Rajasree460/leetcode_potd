class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        map<int, vector<int>> mp;
        for(int i=1; i<s.size(); i++)
            mp[parent[i]].push_back(i);
            //int maxN{0};=faster
        int maxN{0}; //i.e,int maxN=0 
                findNodeMaxPath(mp, s, 0, maxN);
        return maxN;
    }
    int findNodeMaxPath(map<int, vector<int>>& mp, string& s, int node, int& maxN)
    {
        int large{0}, sed{0};
        for(auto p : mp[node]){
            int subMaxPath = findNodeMaxPath(mp, s, p, maxN);
            if(s[node] == s[p]) continue;
            if(subMaxPath >= large){
                sed = large;
               large = subMaxPath;
            }else
                sed = max(sed, subMaxPath);
        }
        maxN = max(maxN, 1 + large+ sed);
        return 1 + large;
    } 
    
};
