// ClassyNumbers
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[ 10005 ][ 105 ][ 2 ];
string s;
ll d;

ll Solve(ll pos, ll sum, bool tight){
	if(pos == s.length())
		return sum == 0;
	if(dp[pos][sum][tight] != -1)
		return dp[pos][sum][tight];

	ll ans = 0;
	
	ll end = ((tight)?(s[pos]-'0'):9);
	for(ll i = 0; i<=end ;i++){
		ans =  (ans +Solve(pos+1,(sum+i)%d,tight&(i == end)))%mod;
	}
	return dp[pos][sum][tight] = ans;
}

int main(){
	cin>>s;
	cin>>d;
	memset(dp,-1,sizeof(dp));

	cout<<(Solve(0,0,1)-1+mod)%mod<<endl;

	return 0;
}