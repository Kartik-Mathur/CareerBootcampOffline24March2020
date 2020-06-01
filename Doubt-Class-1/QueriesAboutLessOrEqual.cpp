// QueriesAboutLessOrEqual
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

ll BS(ll *a,ll s,ll e,ll val){

	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]<=val){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return s;
}

void Queries(ll*a ,ll *b,ll n,ll m){
	sort(a,a+n);

	for(int i=0;i<m;i++){
		int val = b[i];
		cout<<BS(a,0,n-1,val)<<' ';
	}
	cout<<endl;
}

int main(){
	ll n,m;
	cin>>n>>m;
	ll*a = new ll[n];
	ll *b = new ll[m];

	F(a,n);
	F(b,m);

	Queries(a,b,n,m);

	return 0;
}