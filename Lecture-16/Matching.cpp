// Matching
// Problem link : https://atcoder.jp/contests/dp/tasks/dp_o
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

#define ll long long int
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
ll comp[ 25 ][ 25 ];
ll dp[ 25 ][ (1<<21) ];

ll Solve(ll i, ll womens){
	// Base case
	if(i == n){
		return womens == 0;
	}
	if(dp[i][womens] != -1)
		return dp[i][womens];
	// recursive case
	ll ans = 0;
	for(ll w = 0 ; w < n ; w ++){
		bool available = womens&(1<<w);
		if(available and comp[i][w]){
			ans = (ans + Solve(i+1,womens&(~(1<<w))))%mod;
		}
	}
	return dp[i][womens] = ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	NF(comp,n,n);
	memset(dp,-1,sizeof dp);
	cout<<Solve(0,(1<<n)-1)<<endl;

	return 0;
}





















