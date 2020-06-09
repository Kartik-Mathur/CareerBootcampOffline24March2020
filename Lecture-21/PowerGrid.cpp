// Problem link : https://codeforces.com/problemset/problem/1245/D
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
#define pii pair<ll,ll>

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

class graph{

public:
	ll u,v,w;
	graph(){

	}
	graph(ll u,ll v,ll w){
		this->u = u;
		this->v = v;
		this->w = w;
	}	
};


ll x[ 2005 ],y[ 2005 ],c[ 2005 ],k[ 2005 ];
ll n;
vector<ll> PowerStations;
vector<pii> Cities;
graph edges[5100000];
ll it = 0;


void kruskal(){
	sort(edges,edges+it,[=](graph a,graph b){
		return a.w<b.w;
	});

	dsu g(it);

	ll ans = 0;
	ll count_edges = 0;
	for(ll i = 0 ; i < it ; i++){
		ll u = edges[i].u;
		ll v = edges[i].v;
		ll w = edges[i].w;
		count_edges++;
		if(g.get(u) != g.get(v)){
			ans += w;
			if(!u)
				PowerStations.pb(v);
			else if(!v)
				PowerStations.pb(u);
			else
				Cities.pb({u,v});
			g.union_set(u,v);
			if(count_edges == n)
				break;
		}	
	}
	cout<<ans<<endl;
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin>>n;
	for(ll i = 1 ; i <= n ; i++)
		cin>>x[i]>>y[i];
	F1(c,n);
	F1(k,n);
	// Connect every node with the zero node and weight is ci
	for(ll i = 1 ; i<= n ; i++)
		edges[it++] = graph(0,i,c[i]);

	for(ll i = 1 ; i <= n ; i++)
		for(ll j = 1; j<= n ; j++){
			ll w = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			edges[it++] = graph(i,j,w*(k[i]+k[j]));
		}

	kruskal();
	cout<<PowerStations.size()<<endl;
	for(ll i = 0 ; i < PowerStations.size() ; i++){
		cout<<PowerStations[i]<<" ";
	}
	cout<<endl;

	cout<<Cities.size()<<endl;
	for(ll i = 0 ; i < Cities.size() ; i++){
		cout<<Cities[i].fi<<" "<<Cities[i].si<<endl;
	}
	cout<<endl;	

	return 0;
}





















