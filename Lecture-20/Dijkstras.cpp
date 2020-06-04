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

template<typename T>
class Graph{
	unordered_map<T,list<pair<T,ll> > > h;
public:
	void addEdge(T u,T v, ll dist){
		h[u].pb({v,dist});
		h[v].pb({u,dist});
	}

	void Dijkstras(T src,T des){
		unordered_map<T,ll> dist;
		set<pair<ll,T > > s;
		for(auto node:h){
			dist[node.fi] = INT_MAX;
		}

		dist[src] = 0;
		s.insert({0,src});

		while(!s.empty()){
			auto p = *(s.begin());
			s.erase(s.begin());
			T node = p.si;
			ll nodeDist = p.fi;

			for(auto children:h[node]){
				ll edge_dist = children.si;
				if(dist[children.fi]> nodeDist + edge_dist){
					auto f = s.find({dist[children.fi],children.fi});
					if(f!=s.end())
						s.erase(f);
					dist[children.fi] = nodeDist+edge_dist;
					s.insert({dist[children.fi],children.fi});
				}
			}
		}

		for(auto node:h){
			cout<<"Distance of "<<node.fi<<" from "<<src<<" : "<<dist[node.fi]<<endl;
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll m;
	cin>>m;
	Graph<char> g;
	for(ll i = 0 ; i < m ; i++){
		char u , v;
		int w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	g.Dijkstras('A','D');
	return 0;
}





















