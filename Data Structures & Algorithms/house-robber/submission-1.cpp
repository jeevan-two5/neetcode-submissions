class Solution {
public:
    /*int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];

        for(int i = 1; i<n;i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notpick  = 0 + dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    } */

    int rob(vector<int>&nums){
        int n = nums.size();
        if(n==1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i = 2; i<n;i++){
            int pick = nums[i]+prev2;
            int notpick = prev1;
            int cur = max(pick,notpick);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
