// EditDistance https://leetcode.com/problems/edit-distance/

int minDistance(string a, string b) {
	
	int dp[1000][1000];
	int n=a.length();
	int m=b.length();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if( i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
		}
	}
	return dp[n][m];
}
