class Solution {
public:

    int f(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        for(int i = 1; i<n;i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n== 1) return nums[0];
        vector<int>a1;
        vector<int>a2;
        int i = 0;
        while(i < n){
            if(i != 0) a1.push_back(nums[i]);
            if(i != n-1) a2.push_back(nums[i]);
            i++;
        }

        int ans1 = f(a1);
        int ans2 = f(a2);
        return max(ans1,ans2);
    }
};
