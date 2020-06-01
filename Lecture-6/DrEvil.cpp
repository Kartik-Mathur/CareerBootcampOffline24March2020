// DrEvil
// Problem link : 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<=n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define AS 200001

int DrEvil(vector<int> a,int bit){
	// Base case
	if(a.size() == 0 || bit<0){
		return 0;
	}
	// Segregagate karo, ones and zeros mei according to MSB
	vector<int> zeros,ones;
	// if size of zeros is 0, then ask only from ones the answer
		int mask = (1<<bit);
		for(int i=0;i<a.size();i++){
			if((a[i]&mask) == 0){
				// MSB is 0, insert it into the array ones
				zeros.push_back(a[i]);
			}
			else{
				// MSB is 1, insert it into the array zeros
				ones.push_back(a[i]);
			}
		}
	// if size of ones is 0, then ask only from zeros the answer
	if(ones.size() == 0){
		// In this case MSB will be zero
		return DrEvil(zeros,bit-1);
	}
	if(zeros.size() == 0){
		// MSB will be zero again
		return DrEvil(ones,bit-1);
	}
	// Otherwise take the minimum of zeros and ones jo bhi unmei se chota answer dede hume that will the answer
	// here MSB will be equals to one for sure
	return min(DrEvil(zeros,bit-1),DrEvil(ones,bit-1))+(1<<bit);
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	F(v,n);

	cout<<DrEvil(v,30)<<endl;

	return 0;
}




