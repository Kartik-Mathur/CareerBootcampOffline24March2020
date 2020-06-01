// SleepingSchedule
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
#define AS 200001

ll n,l,h,r;
ll dp[2001][2001];
ll a[2001];

ll SleepingSchedule(ll sleep,ll waking_hour){
	// Base case
	if(sleep == n){
		return 0;
	}
	if(dp[sleep][waking_hour]!=-1) return dp[sleep][waking_hour];

	// Recursive case
	ll x = (waking_hour+a[sleep])%h;
	ll y = (waking_hour+a[sleep]-1)%h;

	ll op1 = SleepingSchedule(sleep+1,x) + (x>=l && x<=r);
	ll op2 = SleepingSchedule(sleep+1,y) + (y>=l && y<=r);
	dp[sleep][waking_hour] = max(op1,op2);
	return max(op1,op2);
}	

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>h>>l>>r;
	F(a,n);
	cout<<SleepingSchedule(0,0)<<endl;

	return 0;
}
