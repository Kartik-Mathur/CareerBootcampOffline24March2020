// HolidayAccomodation
// Problem link : https://www.spoj.com/problems/HOLI/
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
ll n;
template<typename T>
class Graph{
	unordered_map<T,list<pair<T,ll> > > h;
public:
	void addEdge(T u, T v,ll dist){
		h[u].pb({v,dist});
		h[v].pb({u,dist});
	}

	ll dfs(T node,unordered_map<T,bool> &visited,ll* count,ll &ans){ // dfs is giving the count of subtrees nodes
		visited[node] = true;
		count[node] = 1;

		for(auto children:h[node]){
			ll dx = children.si;
			if(!visited[children.fi]){
				count[node] += dfs(children.fi,visited,count,ans);
				ll right = count[children.fi];
				ll left = n - right;
				ans += 2*min(left,right)*dx;
			}
		} 
		return count[node];
	}

	ll holiday(){
		unordered_map<T,bool> visited;
		ll * count = new ll[n];
		
		for(ll i = 0 ; i < n ; i++)
			count[i] = 0;
		ll ans = 0;
		dfs(0,visited,count,ans);
		return ans;
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll t,counter=1;
	cin>>t;
	while(t--){
		Graph<ll> g;
		cin>>n;
		for(ll i = 1 ; i<n ; i++){
			ll x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x-1,y-1,z);
		}
		cout<<"Case #"<<counter<<": "<<g.holiday()<<endl;
		counter++;
	}

	return 0;
}





















