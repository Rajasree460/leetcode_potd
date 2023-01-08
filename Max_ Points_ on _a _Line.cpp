class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n=points.size();
      cout<<n<<endl;
        if(n<2)  //cornercase or edgecase
        return n;
        int maxi=2;
        int count=2;
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                count=2;
                int x2=points[j][0];
                int y2=points[j][1];
                for(int k=0;k<n;k++)
                {
                    if(k!=i && k!=j)
                    {
                        int x3=points[k][0];
                        int y3=points[k][1];
                        if(((y2-y1)*(x1-x3))==((y1-y3)*(x2-x1)))
                        count++;
                    }
                }
                maxi=max(maxi,count);
            }
        } 
        return maxi;  
    }
};
