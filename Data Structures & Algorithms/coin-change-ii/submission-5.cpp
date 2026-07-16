class Solution {
/*
    int f(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
           else return 0;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notpick = f(ind-1,amount,coins,dp);

        int pick = 0;
        if(coins[ind] <= amount) pick = f(ind, amount-coins[ind], coins, dp);
        return dp[ind][amount] = pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    } */
public:
    int change(int amount, vector<int>&coins){
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int tar = 0; tar <= amount; tar++) {
                if(tar%coins[0] == 0)
                    dp[0][tar] = 1;
        }


        for(int ind = 1; ind <n; ind++){
            for(int tar = 0; tar <= amount;tar++){

                int notpick = dp[ind-1][tar];
                int pick = 0;
                if(coins[ind] <= tar)
                    pick = dp[ind][tar-coins[ind]];

                dp[ind][tar] = pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};
