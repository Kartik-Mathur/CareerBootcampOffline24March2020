// Problem link : https://atcoder.jp/contests/dp/tasks/dp_e
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
#define Size 100001
ll *weight,*price;
ll dp[101][Size];
ll n,capacity;

ll Knapsack2(ll max_profit){

	ll inf = 1e11;
	for(ll N = 0;N<=n;N++){
		for(ll Profit = 0;Profit<=max_profit;Profit++){
			if(N == 0 && Profit == 0){
				dp[N][Profit] = 0;
			}
			else if (N == 0) dp[N][Profit] = inf;
			else if(price[N-1]<=Profit){
				dp[N][Profit] = min(weight[N-1]+dp[N-1][Profit-price[N-1]],dp[N-1][Profit]);
			}	
			else{
				dp[N][Profit] = dp[N-1][Profit];
			}
		}
	}

	ll ans = 0;
	for(ll Profit=0;Profit<=max_profit;Profit++){
		if(dp[n][Profit]<=capacity) ans = Profit;
	}
	return ans;
}

int main(){
	cin>>n>>capacity;
	weight = new ll[n];
	price = new ll[n];
	ll max_profit = 0;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>price[i];
		max_profit += price[i];
	}

	cout<<Knapsack2(max_profit)<<endl;

	return 0;
}