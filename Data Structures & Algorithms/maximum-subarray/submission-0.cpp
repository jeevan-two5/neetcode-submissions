class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = nums[0] , osum = nums[0];

        for(int i = 1; i<n;i++){
            if(csum >=0){
                csum += nums[i];
                osum = max(csum,osum);
            }
            else{
                csum = nums[i];
                osum = max(csum,osum);
            }
        }

        return osum;
    }
};
