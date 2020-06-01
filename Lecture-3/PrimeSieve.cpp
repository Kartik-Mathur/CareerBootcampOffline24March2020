// PrimeSieve
// Problem link : Segmented Sieve : https://www.spoj.com/problems/PRIME1/cstart=10
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001

void PrimeSieve(int N){
	if(N<2){
		return;
	}
	bool p[100000];
	memset(p,true,sizeof(p)); // initially assume all the numbers are prime

	for(int i=3;i*i<=N;i+=2){
		if(p[i]){
			for(int j=i*i;j<=N;j+=i){ // instead j = 2*i, we can start it from i*i
				p[j] = false;
			}
		}
	}
	cout<<2<<' ';
	for(int i=3;i<=N;i+=2){
		if(p[i]) cout<<i<<' ';
	}
	cout<<endl;
}

vector<ll> primes;
void CalculateAllPrimes(){
	ll N = 100000;
	bool p[N];
	memset(p,true,sizeof(p)); // initially assume all the numbers are prime

	for(ll i=3;i*i<=N;i+=2){
		if(p[i]){
			for(ll j=i*i;j<=N;j+=i){ // instead j = 2*i, we can start it from i*i
				p[j] = false;
			}
		}
	}
	// cout<<2<<' '; 
	primes.push_back(2);
	for(ll i=3;i<=N;i+=2){
		if(p[i]) primes.push_back(i);
	}	
}

void SegmentedSieve(ll a,ll b){
	bool p[b-a+1];
	memset(p,true,sizeof(p)); 

	for(ll i=0;primes[i]*primes[i]<=b;i++){
		ll start = (a/primes[i])*primes[i];
		if(start<a) start+=primes[i];

		for(ll j=start;j<=b;j+=primes[i]){
			p[j-a] = false;
		}
		if(start == primes[i]) p[start-a] = true;
	}

	for(ll j = a; j<=b ;j++){
		if(p[j-a]) cout<<j<<endl;
	}
	cout<<endl;
}


int main(){
	// int n;
	CalculateAllPrimes();
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;	
		if(a == 1) a++;
		// PrimeSieve(n);
		SegmentedSieve(a,b);

	}
	return 0;
}