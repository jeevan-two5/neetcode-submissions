class Solution {
public:

/* bool isAnagram(string s, string t) {
       // vector<int>vec(256,0);
       if(s.size() != t.size()) return false;
        vector<int>vec1(256,0);

        for(int i = 0 ; i<s.length() ; i++){
            vec1[s[i]]++;
        }

        for(int i=0;i<t.length();i++)
            vec1[t[i]]--;
        
        for(int i = 0; i<256;i++)
            if(vec1[i] != 0)  return false;
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        vector<bool>vis(strs.size(),false);
        for(int i = 0; i< strs.size();i++){
            vector<string>asl;

           if(!vis[i]){ 
                asl.push_back(strs[i]);
                for(int j = i+1; j<strs.size();j++){
                    if(!vis[j]){
                        if(isAnagram(strs[i],strs[j])){
                            vis[j] = true;
                            asl.push_back(strs[j]);
                        }
                    }
                }
            if(!asl.empty()) ans.push_back(asl);
           }
           else continue;
        }
        return ans;
    }*/

 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }


    
};