// JourneyToTheMoon
// Problem link : https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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
ll n,p;


template<typename T>
class Graph{
	unordered_map<T,list<T> > h;
public:
	void addEdge(T u,T v,bool bidir=true){
		h[u].pb(v);
		if(bidir)
			h[v].pb(u);
	}

	void dfs(T node, unordered_map<T,bool> &visited,ll &count){
		visited[node] = true;
		count++;

		for(auto children:h[node]){
			if(!visited[children])
				dfs(children,visited,count);
		}
	}

	void JourneyToTheMoon(){
		unordered_map<T,bool> visited;

		ll total = n*(n-1)/2;
		ll ans = 0 ;

		dfs(0,visited,ans);
		total -= ans*(ans-1)/2;

		for(auto node:h){
			ans = 0;
			if(!visited[node.fi]){
				dfs(node.fi,visited,ans);
				total -= ans*(ans-1)/2;
			}
		}
		cout<<total<<endl;
	}
};


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif	

	Graph<ll> g;

	cin>>n>>p;
	for(ll i = 0 ; i < p ; i++){
		ll x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	g.JourneyToTheMoon();

	return 0;
}





















