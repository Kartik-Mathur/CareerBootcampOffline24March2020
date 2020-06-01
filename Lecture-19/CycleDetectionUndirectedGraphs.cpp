// CycleDetectionUndirectedGraphs.cpp
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

template<typename T>
class Graph{
	unordered_map<T,list<T> > h;
	
	bool isCylic_dfs_helper(T node,unordered_map<T,bool> &visited,T parent){
		visited[node] = true;

		for(auto children:h[node]){
			if(!visited[children]){
				bool KyaCyclePresentHai = isCylic_dfs_helper(children,visited,node);
			}	
			else if(children != parent){
				return true;
			}	
		}
		return false;
	}

public:
	void addEdge(T u,T v,bool bidir=true){
		h[u].pb(v);
		if(bidir)
			h[v].pb(u);
	}

	bool isCylic_dfs(){
		unordered_map<T,bool> visited;

		for(auto i:h){
			T node = i.fi;
			if(!visited[node]){
				bool KyaCyclePresentHai = isCylic_dfs_helper(node,visited,node);
				if(KyaCyclePresentHai)
					return true;
			}
		}
		return false;
	}

	bool isCylic_bfs(T src){
		unordered_map<T,bool> visited;
		unordered_map<T,T> parent;

		parent[src] = src;
		visited[src] = true;
		queue<T> q;
		q.push(src);

		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(auto children:h[node]){
				if( (visited[children] == true) and (parent[node] != children))
					return true;
				else if(!visited[children]){
					visited[children] = true;
					parent[children] = node;
					q.push(children);
				}
			}
		}

		return false;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n;
	cin>>n;
	Graph<ll> g;
	for(ll i = 0 ; i  < n ; i ++){
		ll x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	cout<<g.isCylic_dfs()<<endl;
	cout<<g.isCylic_bfs(1)<<endl;
	return 0;
}





















