// Problem link : 
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001
ll MAX(ll a,ll b){
	return a>b?a:b;
}

ll MaxArea(ll *a,ll n){
	if(n<=0){
		return 0;
	}
	ll area = 0,i;
	stack<ll> s;
	
	for(i=0;i<n;){

		if(!s.empty() && a[i]<=a[s.top()]){
			ll height = a[s.top()];
			s.pop();
			if(s.empty()){
				area = MAX(height*i,area);
			}
			else{
				area = MAX(area,height*(i-s.top()-1));
			}
		}
		else{
			s.push(i++);
		}
	}

	while(!s.empty()){
		ll height = a[s.top()];
		s.pop();
		if(s.empty()){
			area = MAX(height*i,area);
		}
		else{
			area = MAX(area,height*(i-s.top()-1));
		}
	}
	return area;

}

int main(){

	ll n;
	cin>>n;
	while(n!=0){
		ll a[AS] = {0};
		F(a,n);
		cout<<MaxArea(a,n)<<endl;
		cin>>n;
	}

	return 0;
}