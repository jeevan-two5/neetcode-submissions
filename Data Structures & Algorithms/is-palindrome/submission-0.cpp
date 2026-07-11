class Solution {
public:
    bool alphaNum(char c){
        if(c >= 'A' && c <= 'Z' ||
            c>='a' && c <= 'z' ||
            c >='0' && c <='9') {
                return true;
            }
            return false;
    }
        

    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l<r){
            while(l<r  && !alphaNum(s[l])) l++;
            while(l<r && !alphaNum(s[r])) r--;

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;r--;
        }
        return true;
    
    }
};
