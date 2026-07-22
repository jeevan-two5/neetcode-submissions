template<typename T>
using V = vector<T>;
// using vector = V;
class Solution {
public:
    int memo(int ind,int prev_ind, V<V<int>>&dp,V<int>&nums){
        int n = nums.size();
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int notpick = 0 + memo(ind+1,prev_ind,dp,nums);
        int pick =0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) pick = 1 + memo(ind+1,ind,dp,nums);
        return dp[ind][prev_ind+1] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        V<V<int>>dp(n,V<int>(n+1,-1));
        return memo(0,-1,dp,nums);
    }
};
