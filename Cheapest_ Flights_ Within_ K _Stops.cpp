class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> v(n);
        map<pair<int,int>,int> mp; // stores the prices of all routes
        for(int i=0;i<flights.size();i++){
            v[flights[i][0]].push_back(flights[i][1]);
            mp[{flights[i][0],flights[i][1]}] = flights[i][2];
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> vis(n,INT_MAX);
        vis[src] = 0;
        
        int dist = 0;
            while(!q.empty() and dist<k+1){
                int size = q.size();
                while(size--){
                    auto check = q.front();
                    q.pop();
                    for(auto i : v[check.first]){
                        int cost = mp[{check.first,i}];
                        cout<<cost<<endl;
                        int total = check.second+cost;
                        if(vis[i]>total){
                            vis[i] = total;
                            q.push({i,vis[i]});
                        }
                    }


                }
                dist++;
            }
        
        return vis[dst] == INT_MAX ? -1 : vis[dst];

    }
};
