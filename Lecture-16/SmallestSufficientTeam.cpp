// code
// Problem link : https://leetcode.com/problems/smallest-sufficient-team/
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

unordered_map<string,int> h;
int pmask[ 60 ];
int fimask;
int dp[ 100 ][ (1<<16) ];
bool choose[ 100 ][ (1<<16) ]={0};

int Solve(int i , int cmask , vector<vector<string>>& p){
	if(cmask == fimask)
		return 0;
	if(i == p.size()){
		return 2000;
	}
	if(dp[i][cmask] != -1)
		return dp[i][cmask];

	// For a particular person, we have two options
	// select him or leave him, if selected his skills would be added
	int inc = 1 + Solve(i+1, cmask|pmask[i] , p);
	int exc = 0 + Solve(i+1, cmask , p);

	if( inc < exc ){
		// ith person ko choose krlo
		choose[i][cmask] = true;
	}
	// else{
	// 	// ith person ko chhod do 
	// 	choose[i][cmask] = false;
	// }
	return dp[i][cmask] = min(inc,exc);
}

vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

	for(int i = 0 ; i <req_skills.size() ; i++){
		h[req_skills[i]] = i;
	}
	// Create the mask for every person
	for(int i = 0 ; i < people.size() ; i++){
		int mask = 0 ;
		for(int j = 0 ; j < people[i].size() ; j++){
			mask |= (1<<h[people[i][j]]);
		}
		pmask[i]  = mask;
	}
	fimask = (1<<req_skills.size()) - 1;
	memset(dp,-1,sizeof dp);
	Solve(0,0,people);

	int mask = 0;
	vector<int> ans;
	for(int i = 0 ; i < people.size() and mask != fimask ; i++){
		if(choose[i][mask] == true){
			ans.push_back(i);
			mask |= pmask[i];
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
	vector<string> rs;
	vector<vector<string> > p;
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		string s;cin>>s;
		rs.pb(s);
	}
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int x; cin>>x;
		vector<string> temp;
		for(int j = 0 ; j < x ;j++){
			string s;cin>>s;
			temp.pb(s);
		}
		p.pb(temp);
	}

	vector<int> ans = smallestSufficientTeam(rs,p);
	for(int i = 0 ; i < ans.size() ; i++)
		cout<<ans[i]<<" ";
	cout<<endl;

	return 0;
}





















