// CrucialEquation.cpp
// Euclid: https://www.spoj.com/problems/CEQU/
#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int eea(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1,y=0;
		// cout<<x<<" "<<y<<endl;
		return a;
	}

	int x1,y1;
	int ans = eea(b,a%b,x1,y1);

	x = y1;
	y = x1-(a/b)*y1;
	// cout<<x<<" "<<y<<endl;
	return ans;
}

int moduleInverse(int a,int m){
	int x,y; // a and m should be co-prime!!!!!!!
	eea(a,m,x,y);
	return x;
}

bool diophantine(int x,int y,int c){
	if(c%gcd(x,y) != 0){
		return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	int count = 1;
	while(t--){
		int x,y,c;cin>>x>>y>>c;
		cout<<"Case "<<count++<<": ";
		if(diophantine(x,y,c)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}	


	return 0;
}