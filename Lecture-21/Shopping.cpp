// Shopping 
// Problem link : https://www.spoj.com/problems/SHOP/
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

ll dist[ 25 ][ 25 ] = {0};
ll dx[4] = { 0 , 0 , 1 , -1 };
ll dy[4] = { 1 ,-1 , 0 ,  0 };
char a[ 25 ][ 25 ];
ll col,row;
ll src_x,src_y,des_x,des_y;

bool PosSahihai(ll x,ll y){
	return x>=0 and x<row and y>=0 and y<col and a[x][y] != 'X';
}

void Dijkstras(){
	
	dist[src_x][src_y] = 0;
	queue<pii> q;	
	q.push({src_x,src_y});

	while(!q.empty()){
		auto x = q.front();
		q.pop();
		ll ci = x.fi;
		ll cj = x.si;

		for(ll i = 0 ; i < 4 ; i++){
			ll ni = ci + dx[i];
			ll nj = cj + dy[i];

			if(PosSahihai(ni,nj) and (dist[ni][nj]>(dist[ci][cj] + (a[ci][cj] - '0') ) ) ){
				dist[ni][nj] = dist[ci][cj] + (a[ci][cj] - '0');
				q.push({ni,nj});
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

	
	cin>>col>>row;

	while(col and row){

		for(ll i = 0 ; i < row ; i++){
			for(ll j = 0 ; j < col ; j++){
				char ch; cin>>ch;
				a[i][j] = ch;
				if(ch == 'S'){
					src_x = i; src_y = j;
					a[i][j] = '0';
				}
				else if(ch == 'D'){
					des_x = i; des_y = j;
					a[i][j] = '0';
				}
				dist[i][j] = 1e9;
			}
		}
		Dijkstras();
		cout<<dist[des_x][des_y]<<endl;
		cin>>col>>row;

	}

	return 0;
}





















