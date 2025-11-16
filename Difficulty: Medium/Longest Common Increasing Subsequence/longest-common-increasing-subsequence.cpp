class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        vector<int> dp(m, 0); 
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int currentBest = 0;

            for(int j = 0; j < m; j++) {

                if(a[i] > b[j])
                    currentBest = max(currentBest, dp[j]);

                else if(a[i] == b[j])
                    dp[j] = currentBest + 1;

                ans = max(ans, dp[j]);
            }
        }

        return ans;
    }
};
