// RatInMaaze
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

int ans = 0;
bitset<30> col,ld,rd;
// bool col[100]={0},ld[100]={0},rd[100]={0};

void NQueen(int i,int n){
	if( i== n ){
		ans++;
		return;
	}

	for(int j = 0; j<n ; j++){
		if(!col[j] && !rd[i+j] && !ld[j-i+n-1]){
			col[j] = rd[i+j] = ld[j-i+n-1] = 1;
			NQueen(i+1,n);
			col[j] = rd[i+j] = ld[j-i+n-1] = 0;
		}
	}

}

int main(){

	int n;
	cin>>n;
	NQueen(0,n);
	cout<<ans<<endl;

	return 0;
}
















