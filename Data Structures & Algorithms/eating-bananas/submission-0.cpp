class Solution {
public:
 bool canFinish(vector<int>&arr, int k , int s){
      long long total_hrs = 0;
      for(int pile : arr){
            total_hrs  += (long long)(pile + s -1)/s;    
      }
      return total_hrs <= k;
  }
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *std::max_element(arr.begin(),arr.end());
        int ans = high; 
        while(low <= high){
           int  mid = low + (high - low)/2;
            
            if(canFinish(arr,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low  = mid + 1;
            }
        }
        return ans;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        return kokoEat(piles,h);
    }
};
