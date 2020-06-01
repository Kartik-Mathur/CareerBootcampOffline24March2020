#include <iostream>
#include <vector>
using namespace std;

#define ll long long int
#define inf 1e9
#define pi 3.1415926535
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

ll RobinHood(ll n,ll k,ll* a){

	ll s = 1;
	ll e = inf+100;
	ll min=0, max=0;
	ll ans = 0 ;
	for(int i=0;i<n;i++){
		ans += a[i];
	}
	// I will get the mid after this
	while(s<=e){
		ll mid = (s+e)/2;
		ll sum = 0;
		for(int i=0;i<n;i++){
			if(mid-a[i]>=0){
				sum += mid-a[i];
			}
		}
		if(sum<=k){
			min = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	s = 1,
	e = inf+100;
	while(s<=e){
		ll mid = (s+e)/2;
		ll sum = 0;
		for(int i=0;i<n;i++){
			if(a[i]-mid>=0){
				sum+=(a[i]-mid);
			}
		}
		if(sum<=k){
			max = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	// cout<<"Max "<<max<<endl;
	// cout<<"Min "<<min<<endl;

	return max-min>0?max-min:(ans%n==0?0:1);
}

int main(){
	ll n,k;
	cin>>n>>k;

	ll*a = new ll[n+1];
	F(a,n);

	cout<<RobinHood(n,k,a)<<endl;

	return 0;
}