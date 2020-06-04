// Problem link : https://codeforces.com/problemset/problem/987/D
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
ll n , m , k , s;
ll cost[100001][101];
ll a[100001];
vector<ll> g[100001];
void Solve(){

	memset(cost,-1,sizeof cost);
	queue<ll> q;

	for(ll product = 1; product<=k ; product ++){
		// Yeh product kaunsi kaunsi state ke andar banta hai?
		for(ll i = 1 ; i <= n ; i++ )
			if(a[i] == product)
				cost[i][product] = 0,q.push(i);

		while(!q.empty()){
			ll node = q.front();
			q.pop();
			for(auto children:g[node]){
				if(cost[children][product] == -1){
					cost[children][product] = cost[node][product] + 1;
					q.push(children);
				}
			}
		}
	}	

	for(ll i = 1 ; i <= n ; i++){
		sort(cost[i]+1,cost[i]+1+k);
		ll ans = 0;
		for(ll j = 1 ; j<=s ; j++){
			ans += cost[i][j];
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m>>k>>s;
	F1(a,n);

	for(ll i = 0 ; i < m ; i++){
		ll u , v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	Solve();

	return 0;
}





















