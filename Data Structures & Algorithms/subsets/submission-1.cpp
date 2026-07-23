class Solution {
public:
    void f(int index, vector<int>&nums,vector<int>&curr,vector<vector<int>>&res){
        if(index == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        f(index+1,nums,curr,res);
        curr.pop_back();
        f(index+1,nums,curr,res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
         f(0,nums,curr,res);
         return res;
    }
};
         
