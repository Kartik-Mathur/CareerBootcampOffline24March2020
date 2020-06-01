// IsThisJEE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long int
#define inf 1e9
#define D double
#define PI 3.1415926535
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

D derivative(D x,D b,D c){
	return (sin(x)*(2*x+b) - (x*x+b*x+c)*cos(x));
}

D IsThisJEE(D b,D c){

	D s = 0;
	D e = PI/2;
	D ans;
	int count =0;
	while(s<=e){

		D mid = (s+e)/2;
		D val = derivative(mid,b,c);
		if(val<0){
			s = mid;
			ans = mid;
		}
		else{
			ans = mid;
			e = mid;
		}

		count++;
		if(count==100){
			break;
		}
	}
	return (ans*ans+b*ans+c)/sin(ans);
}

int main(){
	int t;
	cin>>t;

	while(t--){
		D b,c;

		cin>>b>>c;
		D ans = IsThisJEE(b,c);

		cout<<setprecision(11)<<ans<<endl;
	}

	return 0;
}