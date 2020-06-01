// FillTheBag
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
ll t,n,m;
ll a[100001];
int solve(){
	ll sum = 0 ;
	ll p[65]={0};
	for(ll i = 0;i < m ; i++){
		p[int(log2(a[i]))]++;
		sum+=a[i];
	}
	if(sum<n)
		return -1;


	int i =0;
	int ans = 0;
	while(i<=60){
		if((n>>i)&1){
			if(p[i]) p[i]--;
			else{
				while(i<=60 && !p[i]){
					ans ++;
					p[i]++;
					i++;
				}
				p[i]--;
				continue;
			}
		}
		p[i+1]+=p[i]/2;
		i++;
	}
	return ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>t;
	while(t--){
		cin>>n>>m;
		F(a,m);
		cout<<solve()<<endl;
	}

	return 0;
}





















