// DecayTree
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
#include <iomanip>
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
map<ll,ll> m;
int H;

double DecayTree(int root,int h,ll potential){
	if(h == H) return max(m[root],potential);
	if(potential>m[root]) return potential;
	int left = 2*root;
	int right = left+1;
	return 0.5*(DecayTree(left,h+1,max(m[root]-m[left],potential)) + DecayTree(right,h+1,max(m[root]-m[right],potential)) );
}

int main(){
	
	cin>>H;

	int q;
	cin>>q;

	while(q--){
		string s;
		cin>>s;
		if(s == "add"){
			int node,e;
			cin>>node>>e;
			while(node>0){
				m[node] += e;
				node /= 2;
			}
		}
		else{
			cout<<fixed<<setprecision(10)<<DecayTree(1,0,0)<<endl;
		}
	}

	return 0;
}





















