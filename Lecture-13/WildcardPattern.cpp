// https://leetcode.com/problems/wildcard-matching/
#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
	int n = p.size();
	int m = s.size();

	bool dp[2001][2001] = {0};
	dp[0][0] = 1;

	for(int i = 1;i<=n;i++){
		if(p[i-1] == '*')
			dp[i][0] = (true&&dp[i-1][0]);
	}

	for(int i = 1; i<=n ; i++){
		int j = 1;
		if(p[i-1] == '*'){
			while(j<=m){
				if(dp[i-1][j-1] || dp[i-1][j]){
					while(j<=m){
						dp[i][j++] = true;	
					}
				}
				j++;
			}
		}
		else if(p[i-1] == '?'){
			while(j<=m){
				dp[i][j] = dp[i-1][j-1];
				j++;
			}
		}
		else{
			while(j<=m){
				if(s[j-1] == p[i-1]){
					dp[i][j] = (true&&dp[i-1][j-1]);
				}
				j++;
			}
		}
	}
    return dp[n][m];  
}

int main(){
	


	cout<<endl;
	return 0;
}
