// Problem link : https://codeforces.com/problemset/problem/981/D
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
ll n , k;
ll a[ 55 ];
ll sum[ 55 ];
ll dp[ 55 ][ 55 ];
ll isPossible(ll i, ll k, ll mask){
	// Base case 
	if(i == n+1)
		return k == 0;
	if(k == 0)
		return 0;
	if(dp[i][k] != -1)
		return dp[i][k];

	// Recursive case
	for(ll j = i ; j<=n ; j++){
		if(((sum[j] - sum[i-1])&mask) == mask)
			if(isPossible(j+1,k-1,mask))
				return dp[i][k] = 1; 
	}
	return dp[i][k] = 0;
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++)
		cin>>a[i];

	// Calculate the Prefix sum
	sum[0] = 0;
	for(ll i = 1; i<= n ; i++)
		sum[i] = sum[i-1] + a[i-1];

	ll ans = 0 ;
	for(ll bits = 60 ; bits>=0 ; bits--){
		memset(dp,-1,sizeof dp);
		if(isPossible(1,k,ans|(1ll<<bits)))
			ans |= (1ll<<bits);
	}
	cout<<ans<<endl;

	return 0;
}





















