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
#define inf 1000000000
ll n,r,c,q;
ll NodeSeCap[10005],CapSeNode[10005];
unordered_map<ll,list<ll> > h;
unordered_map<ll,list<ll> > th;


void bfs(){

	for(ll i = 0 ; i < n ; i++){
		CapSeNode[i] = NodeSeCap[i] = inf;
	}
	queue<ll> q;
	q.push(c);
	CapSeNode[c] = NodeSeCap[c] = 0;
	

	while(!q.empty()){
		ll node = q.front();
		q.pop();
		for(auto children:h[node]){
			if(CapSeNode[children]>CapSeNode[node]+1){
				CapSeNode[children] = CapSeNode[node]+1;
				q.push(children);
			}
		}
		for(auto children:th[node]){
			if(NodeSeCap[children]>NodeSeCap[node]+1){
				NodeSeCap[children] = NodeSeCap[node]+1;
				q.push(children);
			}
		}
	}

}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t;
	ll counter = 1;
	cin>>t;
	while(t--){

		cin>>n>>r>>c>>q;
		cout<<"Case "<<counter<<":"<<endl;
		counter++;
		for(ll i = 0 ; i < r; i++){
			ll u,v;
			cin>>u>>v;
			h[u].pb(v);
			th[v].pb(u);
		}

		bfs();

		for(ll i = 0 ; i < q; i++){
			ll u,v;
			cin>>u>>v;
			ll ans = NodeSeCap[u] + CapSeNode[v];
			if(ans >=inf)
				cout<<"Not possible to go from "<<u<<" to "<<v<<"."<<endl;
			else{
				cout<<"The shortest distance from "<<u<<" to "<<v<<" is "<<ans<<"."<<endl;
			}
		}
		h.clear();
		th.clear();
	}

	return 0;
}





















