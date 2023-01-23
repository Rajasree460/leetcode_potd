class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Create two vectors of size N+1
        vector<int> trusting(n+1);
        vector<int> trusted(n+1);
        // Iterate through trust array
        for (auto t : trust) {
            // Increment trusts count for person t[0]
            trusting[t[0]]++;
            // Increment trusted count for person t[1]
            trusted[t[1]]++;
        }

        // Iterate through N people
        for (int i = 1; i <= n; i++) {
            // If a person i is trusted by all but doesn't trust anyone
            if (trusted[i] == n - 1 && trusting[i] == 0) {
                return i;
            }
        }

        // Return -1 if no town judge found
        return -1;
    }
};
