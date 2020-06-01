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

int ans = INT_MIN;

void UpdateState(int x[][5],int i,int a[][5]){
	for(int k=0;k<5;k++){
		for(int l=i-1;l>=0&&l>=i-5;l--){
			if(a[l][k] == -1){
				a[l][k] = 0;
				x[l][k] = -1;
			}
		}
	}
}

void RestoreState(int x[][5],int i,int a[][5]){
	for(int k=0;k<5;k++){
		for(int l=i-1;l>=0&&l>=i-5;l--){
			if(x[l][k] == -1){
				a[l][k] = -1;
			}
		}
	}
}

void Robot(int a[][5],int i,int j,int score,bool powerUsed){
	if(i<=0){
		ans = max(ans,score);
		return;
	}
	if(j<0) return;

	if(i-1>=0 && j-1>=0){
		Robot(a,i-1,j-1,score+a[i-1][j-1],powerUsed);
	} 
	if(i-1>=0){
		Robot(a,i-1,j,score+a[i-1][j],powerUsed);
	} 
	if(i-1>=0 && j+1<5){
		Robot(a,i-1,j+1,score+a[i-1][j+1],powerUsed);
	}

	if(i-1>=0 && j-1>=0 && !powerUsed){
		int x[13][5]={0};
		UpdateState(x,i,a);
		Robot(a,i-1,j-1,score+a[i-1][j-1],!powerUsed);
		RestoreState(x,i,a);
	}
	if(i-1>=0 && !powerUsed){
		int x[13][5]={0};
		UpdateState(x,i,a);
		Robot(a,i-1,j,score+a[i-1][j],!powerUsed);
		RestoreState(x,i,a);
	}
	if(i-1>=0 && j+1<5 && !powerUsed){
		int x[13][5]={0};
		UpdateState(x,i,a);
		Robot(a,i-1,j+1,score+a[i-1][j+1],!powerUsed);
		RestoreState(x,i,a);
	}
}

int main(){

	int t;
	cin>>t;
	while(t--){
		int x;
		int a[100][5]={0};
		cin>>x;
		ans = INT_MIN;
		NF(a,x,5);
		Robot(a,x,2,0,false);
		cout<<ans<<endl;
	}

	return 0;
}





















