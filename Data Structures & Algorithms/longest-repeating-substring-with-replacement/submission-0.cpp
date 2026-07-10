class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
         int l = 0, r=0,maxi = 0, maxlen = 0;
        for(int r=0 ;r < s.size();r++){

            freq[s[r]]++;
            maxi = max(maxi,freq[s[r]]);
            while( (r-l+1 - maxi)> k){
                freq[s[l]]--;
                l++;
            }
            maxlen= max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
