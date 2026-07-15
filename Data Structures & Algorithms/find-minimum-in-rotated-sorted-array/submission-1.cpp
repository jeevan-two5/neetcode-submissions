class Solution {
public:
    int findMin(vector<int> &nums) {
      /*  int n = nums.size();
        int low = 0, high = nums.size()-1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[low] < nums[high]){
                ans = nums[low];
                low++;
            }
            else if(nums[low] > nums[high]){
                ans = nums[high];
                high--;
            }
            else {
                ans = nums[mid];
            }
        }
        return ans; */

        int low = 0, high = nums.size() - 1;
        int ans = nums[0]; 

        while (low <= high) {
            // If the current search space is already strictly sorted, 
            // the leftmost element is the minimum.
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;
            
            // Track the smallest element we've seen at mid
            ans = min(ans, nums[mid]); 

            // If the left part is sorted, the minimum must be in the right part
            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            } 
            // Otherwise, the right part is sorted, so the minimum is in the left part
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
