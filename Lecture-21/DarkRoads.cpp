// Problem link : https://www.spoj.com/problems/ULM09/
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
	vector<ll> parent,rank;
	ll totalComponents;
public:
	dsu(ll n){
		parent.resize(n);
		rank.resize(n);
		for(ll i = 0 ; i < n ; i++)
			parent[i] = i,rank[i] = 0;
		totalComponents = n;
	}

	ll get(ll a){
		if(a == parent[a])
			return a;
		return parent[a] = get(parent[a]); // get(parent[a]); -> this will get me the root node
	}

	void union_set(ll a,ll b){
		a = get(a); // get the root node of a
		b = get(b); // get the root node of b
		if(a != b){
			if(rank[a]<rank[b])
				swap(a,b);
			parent[b] = a;
			if(rank[a] == rank[b]) 
				rank[a]++;
			totalComponents--;
		}
	}
};


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m;
	cin>>n>>m;
	while(true){
		if(n == 0 and m == 0)
			break;
		
		vector<vector<ll> > edges(m);
		ll total = 0;
		for(ll i = 0 ; i < m ; i++){
			ll u,v,w;
			cin>>u>>v>>w;
			total += w;
			edges[i] = {w,u,v};
		}
		sort(edges.begin(),edges.end());
		ll ans = 0;
		dsu g(n+1);
		for(ll i = 0 ; i < m ; i++){
			ll u = edges[i][1];
			ll v = edges[i][2];
			ll w = edges[i][0];

			if(g.get(u) != g.get(v)){
				ans += w;
				g.union_set(u,v);
			}
		}
		cout<<total-ans<<endl;
		cin>>n>>m;
	}

	return 0;
}





















