// MaximumProduct
// Problem link : https://leetcode.com/problems/maximum-product-of-word-lengths/
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
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007

int mask[100001][1] ={0};
int count[100001][1] ={0};

void FindBinary(vector<string>& words){

	for(int i = 0 ; i < words.size() ; i++){
		int characters = 0;
		int ans = 0;
		for(int j = 0 ; j < words[i].length() ; j++){
			int digit = word[i][j] - 'a';
			ans |= (1<<digit);
			characters++;
		}
		
		mask[i][0] =ans;
		count[i][0] = characters;
	}
}

int maxProduct(vector<string>& words) {
	FindBinary(words);
	int n = words.size();
	int ans = 0;
	for(int i = 0 ;i < n-1; i++){
		for(int j = i+1;j<n;j++){
			if(!(mask[i][0] & mask[j][0])){
				int op1 = count[i][0]*count[j][0];
				ans = max(ans,op1);
			}
		}
	}
	return ans;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	return 0;
}





















