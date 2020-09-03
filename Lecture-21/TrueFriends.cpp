// Problem link : https://www.spoj.com/problems/TFRIENDS/
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


vector<ll> order;
bool visited[101] = {0};
vector<ll> Component[101];
ll n,m;
vector<ll> h[101],hrev[101];

void dfs(ll node){
	visited[node] = 1;
	for(auto children:h[node]){
		if(!visited[children])
			dfs(children);
	}
	order.pb(node);
}

void dfst(ll node,ll comp_no){
	visited[node] =1;
	Component[comp_no].pb(node);

	for(auto children:hrev[node]){
		if(!visited[children])
			dfst(children,comp_no);
	}	
}

void scc(){
	memset(visited,false,sizeof visited);

	for(ll i = 0; i < n ; i++){
		if(!visited[i])
			dfs(i);
	}

	memset(visited,false,sizeof visited);
	ll comp_no = 0;
	for(ll i = n-1 ; i>= 0 ; i--){
		if(!visited[order[i]]){
			dfst(order[i],comp_no);
			comp_no++;
		}
	}
	cout<<comp_no<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i = 0 ; i< n ; i++ ){
			for(ll j = 0 ; j < n ; j++){
				char ch;
				cin>>ch;
				if(ch == 'Y'){
					h[i].pb(j);
					hrev[j].pb(i);
				}
			}
		}
		scc();
		for(ll i = 0 ; i < 101 ; i++){
			h[i].clear();
			hrev[i].clear();
		}
		order.clear();
	}

	return 0;
}