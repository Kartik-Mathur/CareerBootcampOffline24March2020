// WineProblem
#include <iostream>
using namespace std;
int a[1000]={2,3,5,1,4};
int n = 5;
int dp[100][100];

int wine(int i,int j,int day){
	if(i>j) 
		return 0;

	if(dp[i][j] != -1)  
		return dp[i][j];

	int op1,op2;
	op1 = op2 = INT_MIN;

	op1 = day*a[i] + wine(i+1,j,day+1);
	op2 = day*a[j] + wine(i,j-1,day+1);
	return dp[i][j] = max(op1,op2);
}

int bottomUp(){
	int dp[100][100]={0};

	for(int i=n;i>=0;i--){
		for(int j=0;j<=n;j++){
			if(i>j)
				dp[i][j] = 0;
			else {
				int cd = n-(j-i);
				int op1 = a[i]*cd + dp[i+1][j];
				int op2 = a[j]*cd + dp[i][j-1];
				dp[i][j] = max(op1,op2);
			}
		}
	}
	return dp[0][n];
}

int main(){
	memset(dp,-1,sizeof dp);
	cout<<wine(0,n-1,1)<<endl;
	cout<<bottomUp()<<endl;


	return 0;
}