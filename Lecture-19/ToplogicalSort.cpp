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
	void tps_dfs_helper(T node,unordered_map<T,bool> &visited,list<T> &l){
		visited[node] = true;
		for(auto children:h[node]){
			if(!visited[children]){
				tps_dfs_helper(children,visited,l);
			}
		}
		l.push_front(node);
	}
public:
	void addEdge(T u,T v,bool bidir=false){
		h[u].pb(v);
		if(bidir)
			h[v].pb(u);
	}

	void tps_dfs(){
		unordered_map<T,bool> visited;
		list<T> l;
		for(auto node:h){
			if(!visited[node.fi]){
				tps_dfs_helper(node.fi,visited,l);
			}
		}
		for(auto node:l)
			cout<<node<<" ";
		cout<<endl;
	}

	void tps_bfs(){
		unordered_map<T,ll> indegree;

		// for(auto node:h){
		// 	indegree[node.fi] = 0;
		// }

		// 1. set up indegree
		for(auto node:h){
			// Iteragte over the children and update their indegree
			for(auto children:node.si){
				indegree[children] ++;
			}
		}

		queue<T> q;
		// now update the queue
		for(auto i:h){
			T node = i.fi;
			if(indegree[node] == 0)
				q.push(node);
		}

		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto children:h[node]){
				indegree[children] --;
				if(indegree[children] == 0)
					q.push(children);
			}
		}
		return;
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
	Graph<string> g;
	for(ll i = 0 ; i  < n ; i ++){
		string x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	
	g.tps_dfs();
	g.tps_bfs();
	return 0;
}





















