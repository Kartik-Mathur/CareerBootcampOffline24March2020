// AnotherProblemonString
#include <iostream>
using namespace std;
#define ll long long
ll sum[1000002]={0};
ll k;
string a;

void Solve(){

	ll s = 0;
	ll ans = 0;
	sum[0] = 1;
	for(int i=0;i<a.length();i++){
		s += a[i] - '0';
		if(s>=k) ans += sum[s-k];
		sum[s]++;
	}
	cout<<ans<<endl;
}

int main(){
	
	cin>>k;
	cin>>a;

	Solve();
	return 0;
}