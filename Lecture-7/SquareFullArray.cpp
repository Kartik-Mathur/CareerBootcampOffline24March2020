// SquareFullArray
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
int ans = 0;

void SquareFullArray(vector<int>& A,int n,int start){

	if(start>1){
		// Check karlo kya pichle do elements squarefull hai ya nahi, if yes then continue, else not
		int num = sqrt(A[start-2]+A[start-1]);
		if(A[start-2]+A[start-1] != num*num){
			return;
		}
	}
	if(start == n){
		// Update the answer that I have got one squarefull array
		ans++;
	}

	// For the starting index bring every element to the front to check kya uske saath 
	// Square full array bann skta hai ya nahi
	if(int j=start;j<n;j++){
		if(j == start || A[start] != A[j]){
			swap(A[start],A[j]);
			SquareFullArray(A,n,start+1);
			swap(A[start],A[j]);
		}
	}
}

int numSquarefulPerms(vector<int>& A) {
    sort(A.begin(),A.end());
    SquareFullArray(A,n,0);
    cout<<ans<<endl;
}
int main(){



	return 0;
}





















