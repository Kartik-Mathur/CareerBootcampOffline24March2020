// BuyAndSellStockIV.cpp
int maxProfit(int K, vector<int>& prices) {
    if(K==0 || prices.size() <=1) return 0;
    int n = prices.size();
    if(K>=prices.size()/2){
        int ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1])
                ans += prices[i]-prices[i-1];
        }
        return ans;
    }
    
    int dp[1001][1001]={0};
    for(int k = 1;k<=K;k++){
        for(int i = 1; i<n;i++){
            int ans = 0;
            for(int j = 0;j<i;j++){
                if(prices[i]>prices[j])
                    ans = max(prices[i]-prices[j]+dp[k-1][j],ans);
            }
            dp[k][i] = max(ans,dp[k][i-1]);
        }
    }
    return dp[K][n-1];
}