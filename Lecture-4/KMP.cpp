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
#define AS 200001
int table[10000]={0};

void CalculateTable(char* p){
	int i=1;
	int j=0;
	int lp = strlen(p);
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

void KMP(char* s,char *p){
	CalculateTable(p);

	int i=0,j=0;
	int ls = strlen(s);
	int lp = strlen(p);

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
			cout<<"Pattern Found at Index : "<<i-j<<endl;
			j = table[j-1];
		}
	}

}

int main(){

	char s[]="ABCDABCDABCDABCDABCXABCDABC";


	char p[]="ABCDABC";

	KMP(s,p);
	// P(table,strlen(p));
	

	return 0;
}
