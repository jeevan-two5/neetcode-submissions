class Solution {
public:
   /* bool f(int ind, int target, vector<vector<int>>&dp, vector<int>&nums){

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
    } */

    bool canPartition(vector<int>&nums){
         int sum = 0, n = nums.size();
        for(auto c: nums) sum += c;
        int target = sum/2;
        if(sum%2 == 1) return false;
      //  if(target == 0) return true;
       
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        for(int ind = 0; ind < n; ind++) dp[ind][0]  =true;

        for(int k = 0; k<=target;k++)
            if(k == nums[0]) dp[0][k] = true;

        for(int ind =1; ind <n; ind++){
            for(int tar =0 ;tar <= target;tar++){
            int pick = false;
            if(nums[ind] <= tar) pick = dp[ind-1][tar-nums[ind]] ;

            int notpick = dp[ind-1][tar];

            dp[ind][tar] = pick|notpick;
            }
        }
        return dp[n-1][target];
    }



};
