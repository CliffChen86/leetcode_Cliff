class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = nums.size();
        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = -1;
        for(int i = 0; i < n; i++)
            if(dp[i] > res)
                res = dp[i];
        return res;
    }
};