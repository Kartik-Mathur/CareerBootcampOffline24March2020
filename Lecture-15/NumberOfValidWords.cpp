// NumberOfValidWords
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


vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
	unordered_map<int,int> wmc; // key:Mask, value : Number of times that mask occurs
	// key : number of words that belongs to the same mask

	for(auto w:words){
		int mask = 0 ;
		// int cnt = 0; // to count the unique characters
		for(auto ch:w){
			int digit = ch-'a';
			// if(mask&(1<<digit)) continue;
			mask |= (1<<digit);
			// cnt++;
			// if(cnt>7) break;
		}
		if(__builtin_popcount(mask)>7)
			continue;
		wmc[mask]++;
	}

	vector<int> ans(puzzles.size(),0);

	for(int i = 0 ; i < puzzles.size() ; i++){
		string p = puzzles[i];

		for(int j = 0 ; j < (1<<6) ; j++){
			int pmask = (1<<(p[0]-'a'));
			for(int k = 0 ; k < 6 ; k++){
				if(j&(1<<k))
					pmask |= (1<<(p[k+1]-'a'));
			}
			ans[i] += wmc[pmask];
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





















