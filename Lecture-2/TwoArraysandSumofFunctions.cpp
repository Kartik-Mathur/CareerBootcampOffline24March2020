// TwoArraysandSumofFunctions.cpp
#include<iostream> 
#include <algorithm>
using namespace std;

#define MOD 998244353
#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}


bool compare(ll a,ll b){
	return a>b;
}

int main(){

	int n;
	cin>>n;
	ll *a = new ll[n];
	ll *b = new ll[n];

	F(a,n);
	F(b,n);

	for(int i=0;i<n;i++){
		a[i] = a[i]*(i+1)*(n-i);
	}

	sort(a,a+n);
	sort(b,b+n,compare);

	ll sum = 0;

	for(int i=0;i<n;i++){
		sum += (a[i]%MOD)*(b[i]%MOD);
		sum%=MOD;
	}
	cout<<sum<<endl;

	return 0; 
}
