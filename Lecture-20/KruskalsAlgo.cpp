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

class dsu{
	vector<ll> parent; 
	ll totalComponents;
public:
	dsu(ll n){
		parent.resize(n);
		// rank.resize(n);
		for(ll i = 0 ; i < n ; i++)
			parent[i] = i;
		totalComponents = n;
	}

	ll get(ll v){
		if(v == parent[v])
			return v;

		return parent[v] = get(parent[v]);
	}

	void union_set(ll a,ll b){
		ll superparenta = get(a);
		ll superparentb = get(b);
		if(superparentb != superparenta){
			parent[superparenta] = superparentb;
			totalComponents --;
		}
	}
};


ll n,m;

void Solve(){
	cin>>n>>m;
	vector<vector<ll> > edges(m);
	for(ll i = 0 ; i < m ; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		edges[i] = {w,u,v};
	}
	sort(edges.begin(),edges.end());
	dsu g(n+1);
	map<ll,list<ll> > mst;

	ll min_weight = 0;
	for(ll i = 0 ; i < m ; i++){
		ll u = edges[i][1];
		ll v = edges[i][2];
		ll w = edges[i][0];

		if(g.get(u) != g.get(v)){
			g.union_set(u,v);
			cout<<u<<" and "<<v<<" with weight "<<w<<endl;
			min_weight += w;
			mst[u].pb(v);
		}
	}
	cout<<"MST weight : "<<min_weight<<endl;
	for(auto node:mst){
		for(auto children:node.si){
			cout<<node.fi<<" is connected to "<<children<<endl;
		}
	}
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Solve();


	return 0;
}





















