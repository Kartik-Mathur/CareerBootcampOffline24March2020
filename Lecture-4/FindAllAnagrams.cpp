// https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
    bool compare(int *countp,int *counts){
        for(int i=0;i<26;i++){
            if(countp[i] != counts[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        int lp = p.length();
        int ls = s.length();
        vector<int> ans;
        if(lp>ls){
            return ans;
        }
        
        int countp[26]={0},counts[26]={0};
        
        for(int i=0;i<lp;i++){
            countp[p[i]-'a']++;
        }
        
        for(int i=0;i<ls;i++){
            counts[s[i]-'a']++;
            if(i >= lp){
                counts[s[i-lp] -'a']--;
            }   
            if(i>=lp-1){
                if(compare(countp,counts)==true){
                    ans.push_back(i-lp+1);
                }
            }
        }
        return ans;
    }
};