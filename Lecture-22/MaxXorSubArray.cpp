// MaximumXorPair
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

//  CLASS NODE //
class node{
public:
	int value;
	node* left;// 0
	node* right;// 1
};

class trie{
	node* root;
public:
	trie(){
		root = new node();
	}

	void insert(int val){
		node* temp = root;
		for(int i = 31 ; i >= 0 ; i--){
			int bit = (val>>i)&1;
			if(bit){
				if(temp->right == NULL) temp->right = new node();

				temp = temp->right;
			}
			else{
				if(temp->left == NULL) temp->left = new node();

				temp = temp->left;
			}
		}
		temp->value = val;
	}

	int maxxor_helper(int val){
		node* temp = root;
		for(int i = 31 ; i>=0 ; i--){
			int bit = (val>>i)&1;
			if(bit){
				if(temp->left) temp=temp->left;
				else temp = temp->right;
			}
			else{
				// bit -> 0
				if(temp->right) temp = temp->right;
				else temp=temp->left;
			}
		}

		return (val^(temp->value));
	}

	int maxxor(int* arr,int n){
		int max_ans = 0;
		int val = 0;
		for(int i = 0 ; i < n ; i++){
			val ^= arr[i];
			insert(val);
			int ans = maxxor_helper(val);
			// cout<<ans<<' ';
			max_ans = max(max_ans,ans);
		}
		// cout<<endl;
		return max_ans;
	}

};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int arr[100];
	int n ;
	cin>>n;
	F(arr,n);
	trie t;

	cout<<t.maxxor(arr,n)<<endl;


	return 0;
}





















