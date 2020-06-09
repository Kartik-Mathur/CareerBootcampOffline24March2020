// PlayingDirectedgraph
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

ll dist[505][505];

int main(){
	fastIO
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	ll n,m;
	cin>>n>>m;
	for(ll i = 1 ; i <= n ; i++){
		for(ll j = 1 ; j <= n ; j++){
			dist[i][j] = 1e9;
		}
		dist[i][i] = 0;
	}

	for(ll i = 0 ; i < m ; i++){
		ll u , v , w;
		cin>>u>>v>>w;
		dist[u][v] = w;
	}	

	for(ll k = 1 ; k <= n ; k++)
		for(ll i = 1 ; i <= n ; i++)
			for( ll j = 1 ; j<= n ;j++)
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);

	for(ll i = 1 ; i<= n ; i++){
		if(dist[i][i] < 0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(ll i = 1 ; i <= n ; i++){
		ll ans = 1e9;
		for(ll j = 1 ; j<=n ; j++){
			ans = min(ans,dist[i][j]);
		}
		if(i == n)
			cout<<ans<<endl;
		else
			cout<<ans<<" ";
	}

	return 0;
}





















