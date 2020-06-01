// GregAndArray
// https://codeforces.com/contest/296/problem/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200

int main(){
	ll n,m,k;
	ll l[AS]={0},r[AS]={0},d[AS]={0},diff[AS]={0},count[AS]={0},a[AS]={0};

	cin>>n>>m>>k;
	F1(a,n);

	for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>d[i];

	for(int i=0;i<k;i++){
		ll x,y;
		cin>>x>>y;
		count[x]++;
		count[y+1]--;
	}
	// Prefix sum array of count
	for(int i=1;i<=m;i++) count[i]+=count[i-1];

	for(int i=1;i<=m;i++){
		diff[l[i]] += count[i]*d[i];
		diff[r[i]+1] -= count[i]*d[i];
	}

	// for(int i=1;i<=n;i++) diff[i]+=diff[i-1];
	// for(int i=1;i<=n;i++) cout<<diff[i]<<' ';
	for(int i=1;i<=n;i++){
		a[i]+=(diff[i]+=diff[i-1]);
	}
	P1(a,n);

	// cout<<endl;

	return 0;
}