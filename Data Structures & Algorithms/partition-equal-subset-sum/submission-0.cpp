class Solution {
public:
    bool f(int ind, int target, vector<vector<int>>&dp, vector<int>&nums){

        if(target == 0) return true;
        if(ind == 0) return target == nums[0];
        if(dp[ind][target] != -1) return dp[ind][target];
        int pick = false;
        if(nums[ind] <= target) pick = f(ind-1,target-nums[ind], dp,nums);

        int notpick = f(ind-1, target, dp,nums);

        return dp[ind][target] = pick|notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto c: nums) sum += c;
        int tar = sum/2;
        if(sum%2 == 1) return false;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,dp,nums);
    }
};
