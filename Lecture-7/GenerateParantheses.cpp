// GenerateParantheses
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

void GenerateParantheses(int n,int i,char* out,int open,int close){
	// Base 
	if(i == 2*n){
		out[i] = '\0';
		cout<<out<<endl;
		return;
	}
	if(close<open){
		out[i] = ')';
		GenerateParantheses(n,i+1,out,open,close+1);
	}
	if(open<n){
		out[i] = '(';
		GenerateParantheses(n,i+1,out,open+1,close);
	}
}

int main(){
	int n;
	cin>>n;
	char out[100];
	GenerateParantheses(n,0,out,0,0);


	return 0;
}





















