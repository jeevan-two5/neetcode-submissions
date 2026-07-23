class Solution {
public:
    void backtrack(int index, vector<int>&nums,vector<int>&curr,vector<vector<int>>&res){
        res.push_back(curr);
        for(int i = index; i < nums.size();++i){
            if(i>index && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>curr;
        backtrack(0,nums,curr,res);
        return res;
    }
};
