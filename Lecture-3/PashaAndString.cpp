// PashaAndString
// Problem link : https://codeforces.com/contest/525/problem/B
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

int main(){
	char a[AS];
	ll count[AS]={0};

	cin>>a;

	int len = strlen(a);
	
	int m;
	cin>>m; // Number of days

	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		count[x-1]++; 
	}
	ll sum = 0;
	for(int i=0;i<len/2;i++){
		sum+=count[i];
		sum = sum&1;
		if(sum){
			// swap ith character with len-i-1
			char temp = a[i];
			a[i] = a[len-i-1];
			a[len-i-1] = temp;
		}
	}

	cout<<a<<endl;


	return 0;
}