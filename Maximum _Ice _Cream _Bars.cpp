class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
       sort(costs.begin(),costs.end());
       int sum=0,ct=0;
       for(int i=0;i<n;i++){
          if(costs[i]<=coins){
              coins=coins-costs[i];
              ct++;
          }
         else break;
       } 
       return ct;
    }
};
