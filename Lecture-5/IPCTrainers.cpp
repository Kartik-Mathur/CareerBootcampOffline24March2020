// IPCTrainers
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001

ll IPCTrainers(){
	ll total_trainers, days;
	cin>>total_trainers>>days;
	ll startday[AS]={0},lectures[AS]={0},sadness[AS]={0};
	priority_queue<pair<ll,ll> > q;

	for(ll i=0;i<total_trainers;i++){
		cin>>startday[i]>>lectures[i]>>sadness[i];
		q.push({sadness[i],i});
	}
	ll lecturesTaken[AS]={0};
	set<ll> s;
	for(int i=1;i<=days;i++){
		s.insert(i);
	}

	while(!q.empty()){
		auto x = q.top();
		q.pop();
		ll ii = x.second;

		ll start = startday[ii];
		ll end = start + lectures[ii] - 1;
		for(int i=start;i<=end;i++){
			auto f = s.lower_bound(i);
			if(f ==s.end()){
				break;
			}
			else{
				lecturesTaken[ii]++;
				s.erase(f);
			}
		}
	}

	ll sadness_kitniHui = 0;
	for(int i=0;i<total_trainers;i++){
		sadness_kitniHui += (lectures[i]-lecturesTaken[i])*sadness[i];
	}
	return sadness_kitniHui;
}

int main(){

	ll t;
	cin>>t;
	while(t--){
		cout<<IPCTrainers()<<endl;
	}


	return 0;
}