class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(),points.end());  
      int Yc=points[0][1];
      int res=1;
      for(auto point:points){
          if(point[0]>Yc) {
              res++;
              Yc=point[1];
          }
          Yc=min(point[1],Yc);
      }
      return res;
    }
    //tc=O(nlogn)
    //sc=O(1)
};
