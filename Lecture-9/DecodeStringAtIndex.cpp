// DecodeStringAtIndex.cpp
// /https://leetcode.com/problems/decoded-string-at-index/
#include <iostream>
using namespace std;
string decodeAtIndex(string a, int k) {
	stack<pair<string,long long int> s;
	// First create the stack so that we can process it
	for(int i=0;i<a.length();i++){
		string x = "";
		while(i<a.length() && (a[i]>'9' || a[i]<'0')){
			x += a[i++];
		}
		long long int l = (x.length() + (s.empty()?0:s.top().second))*(a[i]-'0');
		s.push({x,l});
		if(l>=k) break;
	}
	// Now find the character

	while(!s.empty()){
		auto p = s.top();
		string x = p.first;
		long long int l = p.second;
		s.pop();

		k = k%(x.length() +(s.empty()?0:s.top().second));
		if(k == 0) k = x.length() +(s.empty()?0:s.top().second);
		if(s.empty()){
			string ans = "";
			ans += x[k-1];
			return ans;
		}
		if(k>s.top().second){
			string ans = "";
			ans += x[k-s.top().second-1];
			return ans;
		}
	}
	return "";
}
int main(){
	


	cout<<endl;
	return 0;
}