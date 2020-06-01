// ADAMONEy
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
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

ll n,k=5;
vector<ll> b;
vector<ll> c({1,2,0,5,1});

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B){
	vector<vector<ll> > C(k,vector<ll>(k));
	for(ll i = 0 ; i < k ; i++)
		for(ll j = 0 ; j < k ; j++)
			for(ll l = 0 ; l < k ; l++)
				C[i][j] = (C[i][j] + (A[i][l]*B[l][j])%mod)%mod;
	
	return C;			
}

vector<vector<ll> > power(vector<vector<ll> > T, ll p){
	if(p == 1)
		return T;

	if(p&1)
		return multiply(T,power(T,p-1));
	vector<vector<ll> > ans = power(T,p/2);
	return multiply(ans,ans);
}

ll solve(){
	if( n == 0)
		return 0;

	vector<ll> F1(k);

	for(ll i = 0 ; i < k ; i++)
		F1[i] = b[i];

	// Create the transform matrix
	vector<vector<ll> > T(k,vector<ll>(k));

	for(ll i = 0 ; i < k ; i++){
		for(ll j = 0 ;  j < k ; j ++){
			if(i<k-1){
				if(j == i+1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
			else{
				// Last row->k-1th ka kaam yaha krenge
				T[i][j] = c[k-1-j];
				// i - k-1, j - 0 toh yaha par c[k-1]
				// j->1, c[k-2]
			}
		}
	}

	T = power(T,n);

	// calculate the answer
	ll ans = 0;
	for(ll i = 0 ; i < k ; i++){
		ans = (ans + (T[0][i]*F1[i])%mod)%mod;
	}
	return ans;
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
		ll num;
		for(ll i = 0 ; i < k ; i++)
			cin>>num,b.pb(num);
		cin>>n;
		if(n<k)
			cout<<b[n]<<endl;
		else
			cout<<solve()<<endl;
		b.clear();
	}


	return 0;
}





















