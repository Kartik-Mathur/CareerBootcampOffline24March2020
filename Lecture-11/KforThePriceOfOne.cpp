// KforThePriceOfOne
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
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200010
ll n,p,k;

ll cost[AS];
ll Price(){
	ll dp[AS]={0};
	sort(cost,cost+n);
	ll ans = 0;

	for(ll i = 0;i<n;i++){
		if(i<k-1){
			dp[i] = cost[i] + (i==0?0:dp[i-1]);
		}
		else if(i == k-1){
			dp[i] = cost[i];
		}
		else{
			dp[i] = dp[i-k]+cost[i];
		}
		if(dp[i]<=p) ans = i+1;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		F(cost,n);
		cout<<Price()<<endl;
	}

	return 0;
}





















