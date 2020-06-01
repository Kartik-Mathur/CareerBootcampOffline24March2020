// Problem : https://leetcode.com/problems/di-string-match/
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        if(S.length() == 0) return ans;
        
        int greatest = S.length();
        int smallest = 0;
        
        for(int i=0;i<S.length();i++){
            if(S[i] == 'I'){
                ans.push_back(smallest++);
            }
            else ans.push_back(greatest--);
        }
        ans.push_back(smallest);
        return ans;
    }
};