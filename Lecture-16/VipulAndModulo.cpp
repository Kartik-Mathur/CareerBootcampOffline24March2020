// Problem link : https://hack.codingblocks.com/app/contests/1496/512/problem
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

ll dp[ (1<<18)+1 ][ 100 ];
string s;
ll MOD;

ll Solve(ll mask, ll m){
	if(mask == ((1<<s.length())-1))
		return m == 0;
	if(dp[mask][m] != -1)
		return dp[mask][m];
	bool ch[10] = {0};
	ll ans = 0;
	for( ll i = 0 ; i < s.length() ; i++){
		if(mask == 0 and s[i] == '0') // This will prevent leading zeros
			continue;
		if( !ch[s[i] - '0'] and !((1<<i)&mask)){
			ch[s[i] - '0'] = true;
			ans += Solve(mask|(1<<i),(m*10 + (s[i]-'0'))%MOD );
		}
	}
	return dp[mask][m] = ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin>>s;
		cin>>MOD;
		cout<<Solve(0,0)<<endl;
	}

	return 0;
}





















