// Problem link : https://www.spoj.com/problems/STAR3CAS/
#include <iostream>
#include <vector>
#include <climits>
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

void StairCase(int *a,int n,int stair,int steps,bool visited[]){
	// Base case
	if(stair == n){
		// Calculate the minimum steps
		ans = min(ans,steps);
		return;
	}
	// Mei stair par khada hoon
	visited[stair] = true;

	// Recursive case
	// We can either go to i+1
	if(stair+1<=n && !visited[stair+1]){
		StairCase(a,n,stair+1,steps+1,visited);
	}
	// We can either go to i+a[i]
	if(stair+a[stair]<=n && stair+a[stair]>=0 &&  !visited[stair+a[stair]]){
		StairCase(a,n,stair+a[stair],steps+1,visited);
	}
	visited[stair] = false;
	return;
}


int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool visited[10000] = {0};

		int *a = new int[n+1];
		ans = INT_MAX;

		F(a,n);
		StairCase(a,n,0,0,visited);
		cout<<ans<<endl;
	}


	return 0;
}





















