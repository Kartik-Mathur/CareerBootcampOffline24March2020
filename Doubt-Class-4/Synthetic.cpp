// Synthetic : https://atcoder.jp/contests/abc119/tasks/abc119_c
#include <iostream>
using namespace std;
#define ll long long
ll a,b,c,n;
ll bamboos[1001]={0};

ll Synthetic(ll x,ll y,ll z,int i){
	if(i == n){
		if(x<=0||y<=0||z<=0) return 1e12;
		return abs(x-a)+abs(y-b)+abs(z-c);
	}

	ll op1 = Synthetic(x,y,z,i+1);
	ll op2 = Synthetic(x+bamboos[i],y,z,i+1) + ((x>0)?10:0);
	ll op3 = Synthetic(x,y+bamboos[i],z,i+1) + ((y>0)?10:0);
	ll op4 = Synthetic(x,y,z+bamboos[i],i+1) + ((z>0)?10:0);
	return min(op1,min(op2,min(op3,op4))); 
}

int main(){
	
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++) cin>>bamboos[i];
	cout<<Synthetic(0,0,0,0);
	cout<<endl;
	return 0;
}