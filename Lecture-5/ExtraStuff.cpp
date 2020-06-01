// ExtraStuff
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


int main(){

	char a[]="111..//11.;102,]87]66,5,4,3,23,ABC,DEF";

	char *ans = strtok(a,"./;],");

	while(ans!=NULL){
		cout<<ans<<endl;
		ans = strtok(NULL,"./;],");
	}



	return 0;
}