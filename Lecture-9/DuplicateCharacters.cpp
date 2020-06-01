// DuplicateCharacters
// https://leetcode.com/problems/remove-duplicate-letters/


#include <iostream>
using namespace std;

string removeDuplicateLetters(string a) {
	stack<char> s;
	int lastIndex[26]={0};
	bool presentInStack[26]={0};

 	for(int i=0;i<a.length();i++){
 		lastIndex[a[i]-'a'] = i;
	}

	for(int i=0;i<a.length();i++){
		char ch = a[i];

		if(!s.empty()){
			if(!presentInStack[ch-'a']){
				while(!s.empty() && s.top()>ch && lastIndex[s.top()-'a']>i){
					presentInStack[s.top()-'a'] = false;
					s.pop();
				}
				s.push(ch);		
				presentInStack[ch-'a'] = true;
			}
		}
		else{
			s.push(ch);
			presentInStack[ch-'a'] = true;
		}
	}

	char *a = new char[s.size()];
	int k = s.size();
	a[k--] = '\0';
	while(!s.empty()){
		a[k--] = s.top();
		s.pop();
	}
	string ans(a);
	return ans;
}
int main(){
	


	cout<<endl;
	return 0;
}