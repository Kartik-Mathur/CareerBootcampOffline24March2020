// https://leetcode.com/problems/largest-divisible-subset/
#include <iostream>
using namespace std;

unordered_map<int,vector<int> > h;

vector<int> FindAll(int i,vector<int> &v){
	if(h.count(i))
		return h[i];

	vector<int> ans;
	for(int j=0;j<i;j++){
		if(v[i]%v[j] == 0){
			auto x = FindAll(j,v);
			if(x.size()>ans.size())
				ans = x;
		}
	}

	ans.pb(v[i]);
	return h[i] = ans;
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
   	int n = nums.size();
   	vector<int> ans;
   	sort(nums.begin(),nums.end());

	for(int i=0;i<n;i++){
		auto x = FindAll(i,nums);
		if(ans.size()<x.size()){
			 ans = x;
		}
	}
	return ans;
}


int main(){
	


	cout<<endl;
	return 0;
}