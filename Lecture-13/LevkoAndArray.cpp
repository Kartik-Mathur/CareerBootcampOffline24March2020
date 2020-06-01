// Problem link : 
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
ll n,k;
ll a[2001];


bool isPossible(ll x){	
	ll dp[2001]={0};
	for(ll i = 1; i<n ; i++){
		for(ll j =0; j<i ; j++){
			if(abs(a[i]-a[j])<=(i-j)*x){
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
	}

	ll max_transaction = 0;
	for(ll i = 0;i<n;i++){
		max_transaction = max(max_transaction,dp[i]);
	}
	ll min_transactions = (n-1)-max_transaction;
	return min_transactions<=k;
}

ll solve(){
	ll s = 0;
	ll e = 1e12; // will work in 40 iterations

	while(s<=e){
		ll mid = (s+e)/2;
		if(isPossible(mid)){
			// if mid == 2
			e = mid - 1;// if 2 ka distance ho toh we will check for 1 dist in
			// between the elements
		}
		else{
			s = mid + 1;
		}
	}
	return s;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin>>n>>k;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	cout<<solve()<<endl;
	return 0;
}