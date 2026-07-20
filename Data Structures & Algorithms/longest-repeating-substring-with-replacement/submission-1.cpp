class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int max_freq = 0,ans = 0;
        int r = 0, l = 0;
        for(int r = 0; r< s.size();r++){
            freq[s[r]]++;
            max_freq = max(max_freq,freq[s[r]]);

            while( (r-l+1) - max_freq > k ){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
