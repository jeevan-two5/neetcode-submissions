class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        set<vector<int>>uniqueSet;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2;i++){
            int li = i+1, ri = n-1;

            int nt = 0 - nums[i];
            while(li < ri){
                int sum = nums[li] + nums[ri];
                if(sum < nt) li++;
                else if(sum > nt) ri--;
                else{
                    vector<int>triplet = {nums[i],nums[li],nums[ri]};
                    li++;ri--;
                    uniqueSet.insert(triplet);
                }
            }
        }

        for(auto& triplet : uniqueSet) res.push_back(triplet);

        return res;
    }
};
