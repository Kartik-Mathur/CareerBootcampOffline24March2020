// DivisibleSubArrays
#include<iostream> 
using namespace std;
#define ll long long int

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		ll* a = new ll[n+1];
		int *freq = new int[n+1];
		for(int i=0;i<n;i++){
			freq[i] = 0;
		}
		freq[0] = 1;

		for(int i=0;i<n;i++){
			cin>>a[i];
			if(i-1>=0){
				a[i] = ((a[i])%n+(a[i-1])%n)%n;
			}

			a[i] %= n;
			a[i] = (a[i]+n)%n;
			freq[a[i]]++;
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			ans += (freq[i])*(freq[i]-1)/2;
		}
		cout<<ans<<endl;
	}


	return 0; 
}
