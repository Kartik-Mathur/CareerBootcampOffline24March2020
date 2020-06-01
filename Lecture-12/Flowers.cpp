// Flowers
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[100005];
ll a,b;
ll pre[100005];
ll k;
ll Flowers(ll len, ll k){
	// Base case
	if(len == 0)
		return 1;
	if(dp[len] != -1)
		return dp[len];
	// Option 1 : Feed the Red Flower
	ll op1=0,op2=0;
	op1 = Flowers(len-1,k);
	// Option : Feed the White flower
	if(len>=k){
		op2 = Flowers(len-k,k);
	}
	return dp[len] = (op1 + op2)%mod;
}

void Precompute(){
	memset(dp,-1,sizeof dp);
	pre[0] = 0;
	for(int i=1;i<=100000;i++){
		pre[i] = pre[i-1] + Flowers(i,k);
		pre[i] %= mod;
	}
}

int main(){
	int t;
	cin>>t>>k;
	Precompute();
	while(t--){
		cin>>a>>b;
		cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
	}

	return 0;
}