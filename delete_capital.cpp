class Solution {
public:
    bool detectCapitalUse(string word) {
        int l=word.size();
        int lc=0,uc=0;
        for(int i=0;i<l;i++)
    {
        if(isupper(word[i]))
        {
            uc++;
        }
        else  lc++;
    }
    return l==uc||l==lc||(uc==1 && isupper(word[0]));
    }
};
