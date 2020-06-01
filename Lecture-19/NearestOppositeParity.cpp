// NearestOppositeParity
// Problem link : https://codeforces.com/contest/1272/problem/E
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
ll a[200005];
ll ans [200005];
class Graph{
	unordered_map<ll,list<ll> > h;
public:
	void addEdge(ll u, ll v){
		h[u].pb(v);
	}

	void bfs(){
		queue<ll> q;

		for(ll i = 1 ; i <= n ; i++){
			ans [i] = -1;
			ll x = i - a[i];
			if(x>=1 and ((a[x]&1) != (a[i]&1)))
				ans[i] = 1;
			x = i + a[i];
			if(x<=n && ((a[x]&1) != (a[i]&1)))
				ans[i] = 1;
			if(ans[i] == 1)
				q.push(i);
		}

		while(!q.empty()){
			ll node = q.front();
			q.pop();

			for(auto children:h[node]){
				if(ans[children] != -1)
					continue;
				ans[children] = ans[node] + 1;
				q.push(children);
			}
		}
		for(ll i = 1 ; i <= n ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
};
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin>>n;
	F1(a,n);
	Graph g;
	for(ll i = 1 ; i <= n ; i++){
		ll x = i - a[i];
		if(x>=1 and ((a[x]&1) == (a[i]&1)))
			g.addEdge(x,i);
		x = i + a[i];
		if(x<=n && ((a[x]&1) == (a[i]&1)))
			g.addEdge(x,i);
	}	

	g.bfs();

	return 0;
}