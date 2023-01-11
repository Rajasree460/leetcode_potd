class Solution {
public:
    int dfs(vector<int> adj[], vector<bool> &apple,int s,int parent){
        // visited[s] = true;
        int cnt = 0;
        for(auto u : adj[s]){
            if(u != parent){
                int temp = dfs(adj,apple,u,s);
                if(apple[u]){
                    cnt += (2 + temp);
                    apple[s] = true;
                }
            }
        }
        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& apple) {
        vector<int> adj[n];
        // vector<bool> visited(n,false);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // int cnt = 0;
        int cnt = dfs(adj,apple,0,0);
        return cnt;
    }
};
