// CountGoodSubstrings: https://codeforces.com/contest/451/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define AS 200001
ll Count[2][2]={0};

void CountGoodSubstrings(string s){
	int n = s.length();
	ll even=0,odd=0;
	for(int i=0;i<n;i++){
		odd++;
		if(i&1){ // Even position par add kar rhe hai
			// if(s[i] == 'a'){
			// 	odd += count[s[i]-'a'][0];
			// 	count[s[i]-'a'][0]++;
			// 	even += count[s[i]-'a'][1];

			// }
			// else{
			// 	// S[i] == 'b'
			// 	odd += count[s[i]-'a'][0];
			// 	count[s[i]-'a'][0]++;
			// 	even += count[s[i]-'a'][1];
			// }
			odd += Count[s[i]-'a'][0];
			Count[s[i]-'a'][0]++;
			even += Count[s[i]-'a'][1];
		}
		else{// odd position par add kr rahe hai
			// if(s[i] == 'a'){
			// 	odd += count[s[i] - 'a'][1];
			// 	count[s[i] - 'a'][1]++;
			// 	even += count[s[i] - 'a'][0];

			// }
			// else{
			// 		// s[i] == 'b'
			// 	odd += count[s[i] - 'a'][1];
			// 	count[s[i] - 'a'][1]++;
			// 	even += count[s[i] - 'a'][0];
			// }
			odd += Count[s[i] - 'a'][1];
			Count[s[i] - 'a'][1]++;
			even += Count[s[i] - 'a'][0];
		}
	}
	cout<<even<<' '<<odd<<endl;
}

int main(){

	string s;
	cin>>s;

	CountGoodSubstrings(s);

	return 0;
}
