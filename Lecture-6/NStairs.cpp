// NStairs
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
#define PNF(a,n,m) for(int i=0;i<=n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define AS 200001

int nstairs(int n){
	if(n == 0){
		return 1;
	}
	if(n<0){
		return 0;
	}

	return (nstairs(n-1)+nstairs(n-2)+nstairs(n-3));
}

int Nstairs(int n,int k){
	if(n == 0){
		return 1;
	}
	if(n<0) return 0;

	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += Nstairs(n-i,k);
	}
	return ans;
}

int main(){

	int n;
	cin>>n;

	cout<<nstairs(n)<<endl;
	cout<<Nstairs(n,3)<<endl;


	return 0;
}












