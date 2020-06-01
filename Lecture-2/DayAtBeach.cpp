#include<iostream> 
#include <climits>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define PFS(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}

int main(){

	int n;
	cin>>n;

	int *a = new int[n];
	F(a,n);

	int *leftmax = new int[n+1];
	int *rightmin = new int[n+1];

	leftmax[0] = INT_MIN;

	for(int i=1;i<=n;i++){
		leftmax[i] = max(leftmax[i-1],a[i-1]);
	}

	rightmin[n] = INT_MAX;

	for(int i=n-1;i>=0;i--){
		rightmin[i] = min(rightmin[i+1],a[i]);
	}
	// PFS(leftmax,n+1);
	// cout<<endl;
	// PFS(rightmin,n+1);
	// cout<<endl;

	int partition = 1;
	for(int i = 1;i<n;i++){
		if(leftmax[i]<=rightmin[i]){
			partition++;
		}
	}
	cout<<partition<<endl;


	return 0; 
}
