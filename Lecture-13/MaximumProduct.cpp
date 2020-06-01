// Problem link : https://codeforces.com/problemset/gymProblem/100886/G
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

string a, b;
pair<ll,string> dp[ 20 ][ 2 ][ 2 ][ 2 ];


pair<ll,string> solve(ll pos,bool ta, bool tb, bool st){
	if(pos == a.size()){
		return {1,""};
	}
	if(dp[pos][ta][tb][st].fi != -1)
		return dp[pos][ta][tb][st];

	pair<ll,string> ans(-1,"");

	ll lb = (ta?a[pos]-'0':0);
	ll ub = (tb?b[pos]-'0':9);
	for(ll i = lb; i<= ub; i++){
		ll val;
		if(st == 0 && i==0){
			val = 1;
		}
		else{
			val = i;
		}
		auto x = solve(pos+1,ta&(i==lb),tb&(i==ub),st|(i>0));
		if(val*x.fi>ans.fi){
			ans.fi = val*x.fi;
			if(st == 0 && i == 0)
				ans.si = x.si;
			else{
				reverse(x.second.begin(),x.second.end());
				x.si.pb('0'+i);
				reverse(x.second.begin(),x.second.end());
				ans.si = x.si;
			}
		}
	}
	return dp[pos][ta][tb][st] = ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	for(ll i = 0 ;i < 20; i++)
		for(ll j = 0; j<2 ; j++)
			for(ll k = 0; k<2 ; k++)
				for(ll l = 0 ; l<2 ; l++)
					dp[i][j][k][l].fi = -1;


	cin>>a>>b;

	reverse(a.begin(),a.end());
	while(a.size()<b.size())
		a.pb('0');
	reverse(a.begin(),a.end());

	auto x = solve(0,1,1,0);
	cout<<x.si<<endl;

	return 0;
}





















