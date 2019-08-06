class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for(int i=0;i<=len1;i++)
            dp[i][0] = i;
        for(int i=0;i<=len2;i++)
            dp[0][i] = i;
        
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int a = dp[i-1][j] + 1;
                int b = dp[i][j-1] + 1;
                int c = dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
                dp[i][j] = min(c, min(a, b));
            }
        }
        return dp[len1][len2];
    }
};