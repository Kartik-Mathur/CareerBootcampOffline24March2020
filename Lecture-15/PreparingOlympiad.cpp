// PreparingOlympiad
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
ll n,l,r,x;
ll a[20];
ll solve(){
 	// Logic
 	ll ans =  0;
 	for(ll k = 0 ; k < (1<<n) ; k++){
 		ll total = 0;
 		ll mi = INT_MAX;
 		ll mx = INT_MIN;
 		ll i = k;
 		ll pos = 0;
 		if(__builtin_popcount(i)>1){
 			while(i){
 				ll lastbit = i&1;
 				i = i>>1;
 				if(lastbit and mi == INT_MAX and mx == INT_MIN ){
 					mi = mx = a[pos];
 					total += a[pos];
 				}
 				else if(lastbit){
 					total += a[pos];
 					mi = min(mi,a[pos]);
 					mx = max(mx,a[pos]);
 				}
 				pos++;
 			}
 		}
 		if(mx-mi>=x and total<=r and total>=l)
 			ans++;
 	}
 	return ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>l>>r>>x;
	F(a,n);
	cout<<solve()<<endl;

	return 0;
}





















