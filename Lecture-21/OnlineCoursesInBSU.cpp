// Problem link : https://codeforces.com/contest/770/problem/C
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
ll n,k;
vector<ll> ExamsDeneHaiJo;
unordered_map<ll,list<ll> > h;
vector<ll> ans;
ll visited[100005]={0};
bool isCyclic = false;

void tps(ll node){
	if(visited[node] == 2)
		return;
	visited[node] = 1;
	for(auto children:h[node]){
		if(visited[children] == 1){
			isCyclic = true;
			return;
		}
		tps(children);
	}
	visited[node] = 2;
	ans.pb(node);
}

void dfs(){

	for(auto node:ExamsDeneHaiJo){
		tps(node);
		if(isCyclic)
			break;
	}

	if(isCyclic){
		cout<<"-1"<<endl;
		return;
	}

	cout<<ans.size()<<endl;
	for(auto node:ans){
		cout<<node<<" ";
	}
	cout<<endl;
	return;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>k;
	for(ll i = 0 ; i < k ; i++){
		ll x;
		cin>>x;
		ExamsDeneHaiJo.pb(x);
	}

	for(ll u = 1 ; u <=n ; u++){
		ll m;
		cin>>m;
		if(m == 0)
			continue;
		for(ll j = 0 ; j < m ; j++){
			ll v;
			cin>>v;
			h[u].pb(v);
		}
	}
	dfs();

	return 0;
}





















