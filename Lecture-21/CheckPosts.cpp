// CheckPosts
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

vector<ll> h[100005],hrev[100005];
vector<ll> CheckPostsCost;
vector<ll> order;
bool visited[AS] = {0};
vector<ll> Component[1000];

ll n,m;
// unordered_map<ll,list<ll> > h,hrev;

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

void solve(){

	for(ll i = 1; i <= n ; i++){
		if(!visited[i])
			dfs(i);
	}

	for(ll i = 0 ; i <= n ; i++)
		visited[i] = false;

	ll comp_no = 1;
	for(ll i = order.size()-1 ; i>= 0 ; i--){
		if(!visited[order[i]]){
			dfst(order[i],comp_no);
			comp_no++;
		}
	}
	const ll inf = 1e10;
	vector<pair<ll,ll> > x;
	for(ll i = 1 ; i < comp_no ; i++){
		ll min_cost = inf;
		ll min_cost_count = 0;
		for(auto node:Component[i]){
			if(min_cost > CheckPostsCost[node]){
				min_cost = CheckPostsCost[node];
				min_cost_count = 1;
			}
			else if(min_cost == CheckPostsCost[node]){
				min_cost_count++;
			}
		}
		if(min_cost != inf)
			x.pb({min_cost,min_cost_count});
	}
	// for(ll i = 1 ; i < comp_no ; i++){
	// 	cout<<i<<"-->";
	// 	for(auto node:Component[i]){
	// 		cout<<node<<" ";
	// 	}
	// 	cout<<endl;
	// }	
	ll cost = 0,ways = 1;
	for(auto node:x){
		// cout<<node.fi<<" "<<node.si<<endl;
		cost += node.fi;
		ways = ((ways%mod)*(node.si%mod))%mod;
	}
	cout<<cost<<" "<<ways<<endl;
}
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	CheckPostsCost.pb(-1);
	for(ll i = 0 ; i < n ; i++){
		ll x;
		cin>>x;
		CheckPostsCost.pb(x);
	}
	cin>>m;
	for(ll i = 0 ; i < m ; i++){
		ll u,v; cin>>u>>v;
		h[u].pb(v);
		hrev[v].pb(u);
	}
	solve();

	return 0;
}





















