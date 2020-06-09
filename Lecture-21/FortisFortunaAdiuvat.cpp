// Problem link : https://toph.co/p/fortis-fortuna-adiuvat
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
#define pii pair<ll,ll>
ll inf = 1e16;
ll n,m,x,q;
ll NodeSeHotelKaDistance[ 100005 ],HotelSeNodeKaDistance[ 100005 ];
vector<pair<ll,ll> > h[ 100005 ],hrev[ 100005 ];

void H2N(){
	
	bool* visited = new bool[n+1];

	for(ll i = 0 ; i <= n ; i++){
		HotelSeNodeKaDistance[i] = inf;
		visited[i] = false;
	}
	
	HotelSeNodeKaDistance[x] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,x});
	while(!q.empty()){
		auto node = q.top();
		ll parentDist = node.fi;
		ll parent = node.si;
		q.pop();
		if(visited[parent])
			continue;
		visited[parent] = true;
		

		for(auto children : h[parent]){
			if(HotelSeNodeKaDistance[children.fi] >  parentDist + children.si){
				HotelSeNodeKaDistance[children.fi] = parentDist + children.si;
				q.push({HotelSeNodeKaDistance[children.fi],children.fi});
			}
		}
	}
}

void N2H(){
	bool visited[100005] = {0};
	for(ll i = 0 ; i <= n ; i++){
		NodeSeHotelKaDistance[i] = inf;
	}
	NodeSeHotelKaDistance[x] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,x});
	while(!q.empty()){
		auto node = q.top();
		ll parentDist = node.fi;
		ll parent = node.si;
		q.pop();
		if(visited[parent])
			continue;
		visited[parent] = true;
		

		for(auto children : hrev[parent]){
			if(NodeSeHotelKaDistance[children.fi] >  parentDist + children.si){
				NodeSeHotelKaDistance[children.fi] = parentDist + children.si;
				q.push({NodeSeHotelKaDistance[children.fi],children.fi});
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
	ll t;cin>>t;
	ll counter = 1;
	while(t--){
		cout<<"Case "<<counter<<":"<<endl;
		counter++;
		cin>>n>>m>>x>>q;
		x--;
		for(ll i = 0 ; i < m ; i++){
			ll u,v,w;
			cin>>u>>v>>w;
			u--;v--;
			h[u].pb({v,w});
			hrev[v].pb({u,w});
		}

		H2N();
		N2H();
		for(ll i = 0 ; i < q ; i++){
			ll u,v;
			cin>>u>>v;
			u--;v--;
			ll ans = NodeSeHotelKaDistance[u] + HotelSeNodeKaDistance[v];
			if(ans >= inf)
				cout<<"Be seeing ya, John"<<endl;
			else
				cout<<ans<<endl;
		}
		for(ll i = 0 ; i <=n ; i++){
			h[i].clear();
			hrev[i].clear();
		}
	}

	return 0;
}





















