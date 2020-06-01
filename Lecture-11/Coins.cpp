// Coins
#include <bits/stdc++.h>
using namespace std;
#define ll long long
double dp[3001][3001];
double p[3001];
ll n;

double Func(ll coins, ll heads){
	if(heads == 0) // if head becomes zero and we have some coins, so probability of atleast 0 heads -> 1
		return 1; // if i
	if(coins == 0) // heads required are greater than 0 and coins are zero, thus prob-> 0
		return 0; // this means heads are not zero and we dont have any coins, coins -> 0
	if(dp[coins][heads] > -1) return dp[coins][heads];

	double op1 = p[coins]*Func(coins-1,heads-1);
	double op2 = (1-p[coins])*Func(coins-1,heads);
	dp[coins][heads] = op1+op2;
	return op1+op2;
}

int main(){
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];

	cout<<fixed<<setprecision(10)<<Func(n,(n+1)/2)<<endl;
	
	return 0;
}