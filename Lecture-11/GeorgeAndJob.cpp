// GeorgeAndJob
#include <iostream>
using namespace std;
#define ll long long
ll n,m,k;
ll dp[5005][5005];
ll a[5005];

ll GeorgeAndJob(ll i, ll count_k){
	if(i>n-m || count_k == k){
		return 0;
	}
	if(dp[i][count_k] != -1) return dp[i][count_k];

	ll op1 = 0,op2 = 0;
	for(ll k = i;k<i+m;k++){
		op1 += a[k];
	}

	op1 += GeorgeAndJob(i+m,count_k+1);
	op2 = GeorgeAndJob(i+1,count_k);
	dp[i][count_k] = max(op1,op2);
	return max(op1,op2);
}


int main(){
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<GeorgeAndJob(0,0);


	cout<<endl;
	return 0;
}