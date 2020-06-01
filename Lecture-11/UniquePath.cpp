// UniquePath
#include <iostream>
using namespace std;
int dp[101][101];
int uniquePaths(int m, int n) {
	// Base case
	if(m == 0 && n == 0){
		return 1;
	}
	if(m<0 || n<0) return 0;
	if(dp[m][n]!=-1) return dp[m][n];

	// Recursive case       
	dp[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1); 
	return dp[m][n];
}

int main(){
	memset(dp,-1,sizeof dp);

	int m,n;
	cin>>m>>n;
	cout<<uniquePaths(m-1,n-1)<<endl;
	return 0;
}