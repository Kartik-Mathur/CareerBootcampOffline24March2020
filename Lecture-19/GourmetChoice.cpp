// GourmetChoice
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
class dsu{
	vector<ll> parent,rank;
	ll totalComponents;
public:
	dsu(ll n){
		parent.resize(n);
		rank.resize(n);
		for(ll i = 0 ; i < n ; i++)
			parent[i] = i,rank[i] = 0;
		totalComponents = n;
	}

	ll get(ll a){
		if(a == parent[a])
			return a;
		return parent[a] = get(parent[a]); // get(parent[a]); -> this will get me the root node
	}

	void union_set(ll a,ll b){
		a = get(a); // get the root node of a
		b = get(b); // get the root node of b
		if(a != b){
			if(rank[a]<rank[b])
				swap(a,b);
			parent[b] = a;
			if(rank[a] == rank[b]) 
				rank[a]++;
			totalComponents--;
		}
	}
};

vector<pair<ll,ll> > edges;
vector<ll> adjList[3004];
ll depth[3004]={0};
bool KyaNodeAlreadyVisitedHai[3004]={0};
bool visited[3004]={0};
bool KyaCycleHai = false;


void FindDepth(ll node){
	if(visited[node])
		return;
	if(KyaCycleHai)
		return;
	if(KyaNodeAlreadyVisitedHai[node]){
		KyaCycleHai = true;
		return;
	}
	KyaNodeAlreadyVisitedHai[node] = true;

	ll d = 0;
	for(auto children:adjList[node]){
		FindDepth(children);
		d = max(d,depth[children]);
	}
	depth[node] = d+1;
	KyaNodeAlreadyVisitedHai[node] = false;
	visited[node] = true;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m;
	cin>>n>>m;
	dsu g(n+m);

	for(ll i = 0 ; i < n ; i++){
		for( ll j = 0 ; j < m ; j++){
			char ch;
			cin>>ch;
			if(ch == '=')
				g.union_set(i,n+j);
			else if( ch == '>')
				edges.pb({i,n+j});
			else
				edges.pb({n+j,i});
		}
	}

	for(auto e:edges)
		adjList[g.get(e.fi)].pb(g.get(e.si));

	for(ll i = 0 ; i < n+m; i++){
		if(!visited[g.get(i)]){
			FindDepth(g.get(i));
		}
	}

	if(KyaCycleHai){
		cout<<"No";
	}
	else{
		cout<<"Yes"<<endl;
		for(ll i = 0 ;i < n ; i++)
			cout<<depth[g.get(i)]<<' ';
		cout<<endl;
		for(ll j = 0 ; j < m ; j++)
			cout<<depth[g.get(n+j)]<<' ';
		cout<<endl;
	}
	
	return 0;
}





















