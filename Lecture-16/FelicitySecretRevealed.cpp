// Problem link : https://codeforces.com/problemset/problem/757/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
ll n;
string s;
ll dp[ 100 ][(1ll<<20)+1];

ll Solve(ll pos, ll mask){
	if(dp[pos][mask] != -1)
		return dp[pos][mask];

	ll ans = 0;

	if(mask>0)
		if(__builtin_popcount(mask+1) == 1)
			ans ++;
	

	ll decimalNo = 0;

	for(ll i = pos ; i < n ; i++){
		decimalNo *= 2;
		decimalNo += (s[i] - '0');
		if(decimalNo == 0)
			continue;
		if(decimalNo > 20)
			break;
		ans = (ans+Solve(i+1,mask|(1<<(decimalNo-1))))%mod;
	}
	return dp[pos][mask] = ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif	

	cin>>n>>s;
	ll ans = 0 ;
	memset(dp,-1,sizeof dp);
	for(ll i = 0 ; i < n ; i++){
		ans = (ans + Solve(i,0))%mod;
	}
	cout<<ans<<endl;

	return 0;
}





















