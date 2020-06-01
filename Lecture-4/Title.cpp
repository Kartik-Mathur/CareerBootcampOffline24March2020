// Title
// https://codeforces.com/contest/59/problem/C
// Problem link : 
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
#define AS 2000
bool map[30] = {0};
void Title(char *a,int k){
	int i=0;
	int j = strlen(a)-1;

	while(i<j){
		if(a[i] == '?' && a[j] == '?'){i++; j--; continue;}
		else if(a[i] != '?' && a[j] == '?') {a[j] = a[i]; map[a[i]-'a'+1] = true;i++; j--; }
		else if(a[i] == '?' && a[j] != '?') {a[i] = a[j];  map[a[i]-'a'+1] = true; i++; j--;}
		else if(a[i] == a[j]){ map[a[i]-'a'+1] = true; i++; j--;}
		else{
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
	}
	// Here i == j
	if(i == j && a[i]!='?'){
		map[a[i] -'a'+1] = true;
	}

	while(i>=0){
		while(k>1 && map[k] == true){
			k--;
		}

		if(a[i] == '?' && a[j] == '?') {
			a[i] = a[j] = 'a'+k-1;
			map[k]= true;
			i--;
			j++;
		}
		else{
			i--;
			j++;
		}
	}
	if(k == 1 && map[k] == true){
		cout<<a<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}

}

int main(){
	int k;
	cin>>k;
	char a[AS];
	cin>>a;
	Title(a,k);
	

	return 0;
}
