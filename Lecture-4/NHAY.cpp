// NHAY
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
int table[10000]={0};

void CalculateTable(string p){
	int i=1;
	int j=0;
	int lp = p.length();

	while(i<lp){

		while(j>0 && p[i]!=p[j]){
			j = table[j-1];
		}

		if(p[i] == p[j]){
			table[i] = j+1;
			i++;
			j++;
		}
		else{
			i++;
		}

	}
}

void KMP(string s,string p){
	CalculateTable(p);

	int i=0,j=0;
	int ls = s.length();
	int lp = p.length();

	while(i<ls){

		while(j>0 && s[i] != p[j]){
			j = table[j-1];
		}

		if(s[i] == p[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
		if(j == lp){
			cout<<i-j<<endl;
			j = table[j-1];
		}
	}
	cout<<endl;

}

int main(){

	int n;

	while(cin>>n){
		string s;
		string p;
		cin>>p>>s;

		KMP(s,p);
	}

	// P(table,strlen(p));
	

	return 0;
}
