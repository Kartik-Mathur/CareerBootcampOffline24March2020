// TravelCards
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001

ll TravelCards(){
	ll n,a,b,k,f;
	
	map<pair<string,string>, ll> h;

	cin>>n>>a>>b>>k>>f;
	string prev_dest = "";
	for(int i=0;i<n;i++){
		string start_dest,end_dest;
		cin>>start_dest>>end_dest;
		ll price;

		if(prev_dest == start_dest){
			// It is a transhipment, a rupee lagenge
			price = b;
		}
		else{
			// Not a transhpiment, b rupee lagenge
			price = a;
		}
		prev_dest = end_dest;

		if(start_dest>end_dest) swap(start_dest,end_dest);

		if(h.find({start_dest,end_dest}) != h.end()){
				// Price update krdo
			h[make_pair(start_dest,end_dest)] += price;
		}
		else{
			// First time insert krdo
			h[make_pair(start_dest,end_dest)] = price;
		}
	}
	vector<ll> v;
	ll total_cost = 0;
	for(auto node:h){
		v.push_back(node.second);
		total_cost += node.second;
	}

	sort(v.rbegin(),v.rend());

	for(int i=0;i<k;i++){
		if(v[i]>=f) total_cost=total_cost-v[i]+f;
		else break;
	}
	
	return total_cost;
}


int main(){

	cout<<TravelCards()<<endl;


	return 0;
}