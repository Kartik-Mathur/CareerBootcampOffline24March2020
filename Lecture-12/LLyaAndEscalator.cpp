// LLyaAndEscalator
#include <bits/stdc++.h>
using namespace std;
#define ll long long
double dp[2001][2001] = {0};
int n,t;
double p;

double Solve(){
	dp[0][0] = 1;
	for(int i = 1;i<=t; i++){
		for(int j = 0;j<=n;j++){
			if(j == n){
				dp[i][j] = p*dp[i-1][j-1] + dp[i-1][j];
			}
			else if(j == 0){ // This means there are no people on escalator at any time i
				dp[i][j] = (1-p)*dp[i-1][j];
			}
			else{
				dp[i][j] = p*dp[i-1][j-1] + (1-p)*dp[i-1][j];
			}
		}
	}
	double ans = 0;
	for(int i=0;i<=n;i++){
		ans += i*dp[t][i];
	}
	return ans;
}

int main(){
	
	cin>>n>>p>>t;

	cout<<fixed<<setprecision(8)<<Solve()<<endl;

	return 0;
}