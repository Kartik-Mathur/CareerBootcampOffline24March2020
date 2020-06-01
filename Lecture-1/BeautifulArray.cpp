// BeautifulArray
class Solution {
    
    void CreateBeautiful(int a,int d,vector<int> &ans,int n){
        if(n==1){
            ans.push_back(a);
            return;
        }
        if(n == 2){
            ans.push_back(a);
            ans.push_back(a+d);
            return;
        }
        // Ask recursion to create beautiful array for odd numbers
        CreateBeautiful(a,2*d,ans,(n+1)/2); // Pure assumption 
        
        // Create Array for even numbers now
        for(int i=0;i<(n+1)/2;i++){
            if(ans[i]+d<=a+(n-1)*d){
                ans.push_back(ans[i]+d);
            }
        }
    }
    
public:
    vector<int> beautifulArray(int N) {
        int a = 1;
        int d = 1;
        vector<int> ans;
        int n = N;
        CreateBeautiful(a,d,ans,n);
        
        return ans;
    }
};