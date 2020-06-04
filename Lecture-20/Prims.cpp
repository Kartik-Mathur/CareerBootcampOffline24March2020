// Prims
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
#define pii pair<ll,ll>
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
#define inf 1000000000
class Graph{
	ll v;
	list<pii> *l;
public:
	Graph(ll V){
		v = V;
		l = new list<pii>[V];
	}

	void addEdge(ll u , ll v , ll d){
		l[u].pb({v,d});
		l[v].pb({u,d});
	}
	
	ll FindMin(unordered_map<ll,bool> visited,unordered_map<ll,ll> weight,ll v){
		ll minVertex = -1;
		for(ll i = 0 ; i < v ; i++){
			if(!visited[i] and (minVertex == -1 || weight[minVertex]>weight[i])){
				minVertex = i;
			}
		}
		return minVertex;
	}

	void Prims(){
		unordered_map<ll,bool> visited;
		unordered_map<ll,ll> parent;
		unordered_map<ll,ll> weight;

		for(ll i = 0 ; i < v ; i++){
			visited[i] = false;
			weight[i] = inf;
		}

		parent[0] = -1;
		weight[0] = 0;

		for(ll i = 0 ; i < v - 1 ; i++){
			ll minVertex = FindMin(visited,weight,v);
			visited[minVertex] = true;
			for(auto children: l[minVertex]){
				if(!visited[children.fi]){
					if(weight[children.fi]>children.si){
						weight[children.fi] = children.si;
						parent[children.fi] = minVertex;	
					}
				}
			}
		}

		for(ll i = 1 ; i < v ; i++){
			cout<<i<<" is connected to "<<parent[i]<<" with weight "<<weight[i]<<endl;
		}
	}
};

ll n , m;

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;

	Graph g(n);
	for(ll i = 0 ; i < n ; i++){
		ll u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		g.addEdge(u,v,w);
	}
	g.Prims();


	return 0;
}





















