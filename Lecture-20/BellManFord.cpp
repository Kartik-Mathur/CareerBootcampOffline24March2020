// Dijkstras
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
#define pii pair<ll,ll>
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
ll n,m;
template<typename T>
class Graph{
	unordered_map<T,list<pair<T,ll> > > h;
public:
	void addEdge(T u,T v, ll dist){
		h[u].pb({v,dist});
	}

	void BellManFord(T src){
		unordered_map<T,ll> dist;
		
		for(ll i = 0 ; i < n ; i++){
			dist[i] = INT_MAX;
		}	
		dist[src] = 0;

		ll vertices = n;
		for(ll i = 0 ; i < vertices - 1 ; i++)	{
			for(auto node:h){
				T u = node.fi;
				for(auto children:h[u]){
					T v = children.fi;
					ll edge_dist = children.si;
					if(dist[u] != INT_MAX and( dist[v] > dist[u] + edge_dist)){
						dist[v] = dist[u] + edge_dist;
					}
				}
			}
		}

		// To detect the negative cycle
		for(auto node:h){
			T u = node.fi;
			for(auto children:h[u]){
				T v = children.fi;
				ll edge_dist = children.si;
				if(dist[u] != INT_MAX and( dist[v] > dist[u] + edge_dist)){
					cout<<"Negative Cycle Present"<<endl;
					return;
				}
			}
		}	

		for(ll i = 0 ; i < n ; i++){
			cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
		}
	}

	void Print(){
		for(auto node:h){
			cout<<node.fi<<"-->";
			for(auto children:node.si)
				cout<<"("<<children.fi<<","<<children.si<<")";
			cout<<endl;
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	cin>>n>>m;
	Graph<ll> g;
	for(ll i = 0 ; i < m ; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	g.Print();
	g.BellManFord(0);
	return 0;
}





















