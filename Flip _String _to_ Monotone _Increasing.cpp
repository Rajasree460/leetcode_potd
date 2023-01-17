class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int ct_flip = 0, ct_one = 0;
        for (auto i : S)
        { 
 //keep track of all one (we will use count_one in else condition if we need)  
//if we want flip one into 0
            if (i == '1')
                ct_one++;
            else{
                ct_flip++;
            ct_flip = min(ct_flip, ct_one);
            }
        }
        return ct_flip;
    }
};
