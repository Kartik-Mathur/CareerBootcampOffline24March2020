// CircularPermutations
// leetcode.com/problems/circular-permutation-in-binary-representation/
class Solution {
    int findGray(int a){
        return a^(a>>1);
    }
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        
        for(int i=0;i<pow(2,n);i++){
            int x = findGray(i);
            ans.push_back(x);
        }
        
        int k ;
        for(int i=0;i<ans.size();i++){
            if(ans[i] == start){
                k = i;
                break;
            }
        }
        rotate(ans.begin(),ans.begin()+k,ans.end());
        return ans;
    }
};