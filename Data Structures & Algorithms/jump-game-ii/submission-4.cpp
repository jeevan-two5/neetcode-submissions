class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        int l =0 , r=0, jumps =0,f =0;

        while(r < n-1){

            for(int i = l ; i <= r; i++){
                f = max(nums[i]+i, f);                
            }
            l = r+1;
            r = f;
            jumps++;
        }
        return jumps;
    }
};
