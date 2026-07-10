class Solution {
public:
    /* vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i = 0; i<nums.size();i++) freq[nums[i]]++;
        
        vector<pair<int, int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int>ans;
        for(int i = 0; i<k ;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    } */

    vector<int>topKFrequent(vector<int>&nums,int k){
        unordered_map<int,int>freq;
        for(int i = 0; i < nums.size();i++) freq[nums[i]]++;

        vector<vector<int>>bucket(nums.size()+1);

        for(auto &p : freq){
            bucket[p.second].push_back(p.first);
        }

        vector<int>ans;

        for(int i = bucket.size() -1; i >= 0 &&  ans.size() < k ;i--){
            for(int num : bucket[i]){
                 ans.push_back(num);
                 if(ans.size() == k) break;     
            }
        }
        return ans;
    }









};