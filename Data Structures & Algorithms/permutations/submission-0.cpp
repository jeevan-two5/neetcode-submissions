class Solution {
private:
    void f(vector<int>&arr,vector<int>&map,vector<int>&ds,vector<vector<int>>&ans){
        if(ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i<arr.size();i++){
            if(!map[i]){
                ds.push_back(arr[i]);
                map[i] = 1;
                f(arr,map,ds,ans);
                map[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>map(n,0);
        vector<int>vis;
        f(nums,map,vis,ans);
        return ans;
    }
};
