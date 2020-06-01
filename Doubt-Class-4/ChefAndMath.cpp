// ChefAndMath
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
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001

ll ChefAndMath(ll *a,ll x,ll k,int i){
	if(x == 0 && k == 0) return 1;
	if(x<=0 || k<=0 ||i<0) return 0;

	ll ans = 0;
	if(x-a[i]>=0 && x<=k*a[i]){
		ans += ChefAndMath(a,x-a[i],k-1,i);
	}
	ans += ChefAndMath(a,x,k,i-1);
	return ans;
}

int main(){
	int q;
	cin>>q;

	ll a[50];
	a[0]=1;a[1]=2;
	for(int i=2;i<43;i++){
		a[i] = a[i-1]+a[i-2];
	}
	while(q--){
		ll x,k; cin>>x>>k;
		cout<<ChefAndMath(a,x,k,42)<<endl;
	}


	return 0;
}
