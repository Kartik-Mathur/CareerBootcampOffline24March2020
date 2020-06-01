// https://leetcode.com/problems/asteroid-collision/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& a) {
	
	stack<int> s;
	int n = a.size();
	for(int i=0;i<n;i++){
		int x = a[i];
		if(!s.empty() && s.top()>0 && x<0){
			// Collision will take place
			bool flag = true;
			while(!s.empty() && s.top()>0 && x<0){

				if(abs(x) == abs(s.top())){
					flag = false;
					s.pop();
					break;
				}
				else if(abs(x)>abs(s.top())){
					flag = true;
					s.pop();
					continue;
				}
				else{
					flag = false;
					break;
				}
			}
			if(flag) s.push(x);
		}
		else{
			// No collision
			s.push(x);
		}
	}
	vector<int> ans(s.size());
	int k = s.size()-1;
	while(!s.empty()){
		ans[k--] = s.top();
	}
	return ans;
}

int main(){
	


	cout<<endl;
	return 0;
}