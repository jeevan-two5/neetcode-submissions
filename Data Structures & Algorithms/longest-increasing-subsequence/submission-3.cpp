template<typename T>
using V = vector<T>;
// using vector = V;
class Solution {
public:
    /* int memo(int ind,int prev_ind, V<V<int>>&dp,V<int>&nums){
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
    } */

    int lengthOfLIS(V<int>&nums){
        int n = nums.size();
        V<V<int>>dp(n+1,V<int>(n+1,0));
        for(int ind = n-1; ind >=0;ind--){
            for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--){
                int notpick = 0 + dp[ind+1][prev_ind+1];
                int pick = 0;
                if(prev_ind == -1 || nums[ind]>nums[prev_ind]) pick = 1 + dp[ind+1][ind+1];
                dp[ind][prev_ind+1]  = max(pick,notpick);
            }
        }
        return dp[0][0];
    }
};
