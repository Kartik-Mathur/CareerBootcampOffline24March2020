// DimaAndSalad
#include <iostream>
using namespace std;
#define ll long long
#define Size 100001
int Shift = 1e5+2;
ll dp[101][Size];

ll n,k;
ll *taste,*cal;

ll DimaAndSalad(int i, ll sum){
	// Base case
	if(i == n){	
		if(sum == 0) return 0;
		return -1e12;
	}
	if(dp[i][sum+Shift] != -1) return dp[i][sum+Shift];

	// Recursive case
	ll op1 = taste[i] + DimaAndSalad(i+1,(taste[i]-k*cal[i])+sum);
	ll op2 = 0 + DimaAndSalad(i+1,sum);
	dp[i][sum+Shift] = max(op1,op2);
	return max(op1,op2);
}

int main(){
	cin>>n>>k;
	taste = new ll[n];
	cal = new ll[n];

	memset(dp,-1,sizeof dp);

	for(int i=0;i<n;i++) cin>>taste[i];
	for(int i=0;i<n;i++) cin>>cal[i];

	ll ans = DimaAndSalad(0,0);
	if(ans<=0) cout<<-1;
	else cout<<ans;


	cout<<endl;
	return 0;
}