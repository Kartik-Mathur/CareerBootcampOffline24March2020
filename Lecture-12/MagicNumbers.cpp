// MagicNumbers
#include <iostream>
using namespace std;
#define ll long long 
#define mod 1000000007

ll dp[ 2005 ][ 2005 ][ 2 ][ 2 ][ 2 ];
string a,b;
ll m,d;
string s;

ll Solve(ll pos,ll mo,bool tight,bool even,bool st){
	if(pos == s.length())
		return mo == 0;
	if(dp[pos][mo][tight][even][st] != -1)
		return dp[pos][mo][tight][even][st];

	ll ans = 0;

	ll end = ((tight)?(s[pos]-'0'):9);
	if(st == 0){
		ans = (ans + Solve(pos+1,mo,tight&(s[pos] == '0'),0,st))%mod;
		for(ll i = 1; i<=end ;i++){
			if(i != d)
				ans = (ans + Solve(pos+1,(mo*10+i)%m,tight&(i == end),1,1))%mod;
		}
	}
	else{
		for(ll i = 0;i<=end;i++){
			if(even and (i == d))
				ans = (ans + Solve(pos+1,(mo*10+i)%m,tight&(i==end),!even,1))%mod;
			else if( !even and ( i!= d))
				ans = (ans + Solve(pos+1,(mo*10+i)%m,tight&(i==end),!even,1))%mod;
		}
	}
	return dp[pos][mo][tight][even][st] = ans;
}

int main(){
	cin>>m>>d;
	cin>>a>>b;
	// f(b) - f(a) + a == magic
	memset(dp,-1,sizeof dp);
	s = b;
	ll ans = Solve(0,0,1,0,0)%mod;

	s = a;
	memset(dp,-1,sizeof dp);
	ans = (ans - Solve(0,0,1,0,0)+mod)%mod;

	ll mo = 0;
	bool flag = true;
	for(ll i = 0;i<a.length();i++){
		if(i%2 == 0 && (a[i]-'0')!=d){ // if i%2 == 0, that means position is odd, thus it should not have d
			flag = false;
			break;
		}
		if(i%2 && (a[i]-'0') ==d ){
			flag = false;
			break;
		}
		mo = (mo*10 + i)%m;
	}
	if(mo == 0 and flag){
		ans = (ans+1)%mod;
	}
	cout<<ans<<endl;

	return 0;
}