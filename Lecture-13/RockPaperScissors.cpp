#include <bits/stdc++.h>
using namespace std;
double dp[105][105][105];
#define ll long long 
ll r,s,p;

double solveR(ll r,ll s, ll p){
	if(s == 0 || r == 0)
		return 0.0;
	if(p == 0)
		return 1.0;
	if(dp[r][s][p] > -1.0)
		return dp[r][s][p];

	double ans = 0;
	double total = (r*s+s*p+r*p);

	ans += solveR(r-1,s,p)*((r*p)/total);
	ans += solveR(r,s-1,p)*((r*s)/total);
	ans += solveR(r,s,p-1)*((s*p)/total);
	return dp[r][s][p] = ans;
}

double solveS(ll r,ll s, ll p){
	if(p == 0 || s == 0)
		return 0.0;
	if(r == 0)
		return 1.0;
	if(dp[r][s][p] > -1.0)
		return dp[r][s][p];

	double ans = 0;
	double total = (r*s+s*p+r*p);
	
	ans += ((r*p)/total)*solveS(r-1,s,p);
	ans += ((r*s)/total)*solveS(r,s-1,p);
	ans += ((s*p)/total)*solveS(r,s,p-1);
	return dp[r][s][p] = ans;
}

double solveP(ll r,ll s, ll p){
	if(r == 0 || p == 0)
		return 0.0;
	if(s == 0)
		return 1.0;
	if(dp[r][s][p] > -1.0)
		return dp[r][s][p];

	double ans = 0;
	double total = (r*s+s*p+r*p);
	
	ans += ((r*p)/total)*solveP(r-1,s,p);
	ans += ((r*s)/total)*solveP(r,s-1,p);
	ans += ((s*p)/total)*solveP(r,s,p-1);
	return dp[r][s][p] = ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>r>>s>>p;

		memset(dp,-1,sizeof dp);
		cout<<fixed<<setprecision(9)<<solveR(r,s,p)<<" ";
		memset(dp,-1,sizeof dp);
		cout<<fixed<<setprecision(9)<<solveS(r,s,p)<<" ";
		memset(dp,-1,sizeof dp);
		cout<<fixed<<setprecision(9)<<solveP(r,s,p)<<" ";
		cout<<endl;
	}
	return 0;
}