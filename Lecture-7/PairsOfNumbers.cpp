// PairsOfNumbers
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

int ans = INT_MAX;

void Fun(int a,int b,int cnt){
	// base case
	if(a == 1 && b == 1) ans = min(ans,cnt);

	if(a-b>0) Fun(a-b,b,cnt+1);
	if(b-a>0) Fun(a,b-a,cnt+1);
}

void Pairs(int n){
	if(n == 1) {cout<<0<<endl; return;}
	for(int x = 1;x<n;x++){
		Fun(x,n-x,1);
	}
	cout<<ans<<endl;
}

int main(){
	int n;
	cin>>n;
	Pairs(n);


	return 0;
}





















