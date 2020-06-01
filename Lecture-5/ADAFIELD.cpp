#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		ll n,m,q;
		cin>>n>>m>>q;
		multiset<ll> sx,sy,x,y;

		sx.insert(n);
		sy.insert(m);

		x.insert(0);
		x.insert(n);

		y.insert(0);
		y.insert(m);

		for(ll i=0;i<q;i++){
			ll a,b;
			cin>>a>>b;
			if(a == 0){
				if(x.find(b) != x.end()){
					cout<<(*(--sx.end()))*(*(--sy.end()))<<endl;	
					continue;
				}
				// x ki baat ho rhi hai
				auto small = x.lower_bound(b);
				small--;
				auto large = x.upper_bound(b);

				sx.erase(sx.find(*large-*small));
				sx.insert(*large-b);
				sx.insert(b-*small);

				x.insert(b);
				cout<<(*(--sx.end()))*(*(--sy.end()))<<endl;	
			}
			else{
				// y ki baat ho rhi hai
				if(y.find(b) != y.end()){
					ll largestXSegment = *(--sx.end());
					ll largestYSegment = *(--sy.end());
					cout<<largestXSegment*largestYSegment<<endl;	
					continue;
				}
				// x ki baat ho rhi hai
				auto small = y.lower_bound(b);
				small--;
				auto large = y.upper_bound(b);

				sy.erase(sy.find(*large-*small));
				sy.insert(*large-b);
				sy.insert(b-*small);

				y.insert(b);
				cout<<(*(--sx.end()))*(*(--sy.end()))<<endl;	
			}

		}		
	}

	return 0;
}