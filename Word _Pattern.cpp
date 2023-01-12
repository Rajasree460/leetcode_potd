class Solution {
public:
 bool wordPattern(string pattern, string s) {

        unordered_map<char,string>m;
        unordered_map<string,bool>visited;
        vector<string>wordList;

        // stringstream s
        stringstream st(s);

        string word;
        int ct = 0;

        while(st>>word){
            ct++;
            wordList.push_back(word);
        }


       if(pattern.size() != ct){
            return false;
        }else{
            for(int i=0;i<pattern.size();i++){


                 char c=pattern[i];

                //case1. if not visted for new letter eg: abba s[dog,dog,dog,dog] so dog is already assinged to 'a' so "dog" will be visited before it comes to the letter b.
                 if(m[c] == "" && visited[wordList[i]] == true ){
                     return false;
                 }

                //case 2 .if not visited we will make it visited and assign value as v[i]
                else if(m[c] == ""){
       m[c] = wordList[i];
                     visited[wordList[i]] =true;
                 }else{
                    //case 3. if value is already assigned so not equal to the v[i].
                     if(m[c] != wordList[i]) return false;
                 }

            }

        }

        return true;

    }
};
