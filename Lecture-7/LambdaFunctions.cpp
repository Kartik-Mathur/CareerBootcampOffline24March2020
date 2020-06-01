#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;

int main(){
	// []-> Capture List
	// Syntax : 
	// auto _name = []()->return_type{

	// };
	// Simplest Lamda Functions
	[](){
		cout<<"Hello World"<<endl;
	}();

	auto HelloWorld = [](){
		cout<<"Hello World"<<endl;
	};
	HelloWorld(); // Function calling
	
	// auto Sum = [](int a,int b){
	// 	return a+b+f;
	// };
	// cout<<Sum(10,20,10.11)<<endl;

	auto Sum = [](int a,int b,float f)->float{
		return a+b+f;
	};
	cout<<Sum(10,20,10.11)<<endl;

	int a = 100,b=200,c,d,e,f,g,h,j,i,k,l=100;

	// auto Fun = [a,b](int x,int y)->int{
	// 	return a*x+y*b;
	// };
	// cout<<Fun(1,2)<<endl;

	// auto Fun = [=](int x,int y)->int{ // If we want to include multiple buckets
	// 	cout<<"L : "<<l<<endl; 
	// 	l = 200; // Not allowed to update it
	// 	return a*x+y*b;
	// };
	// cout<<Fun(1,2)<<endl;

	auto Fun = [&l,a,b](int x,int y)->int{ // If we want to update pass it by reference, l is by reference, a and b aur by value
		cout<<"L : "<<l<<endl; // & - Passes all the buckets by reference
		l = 200; // &,a - Pass all the buckets by reference except for a
		cout<<l<<endl;
		return a*x+y*b;
	};

	cout<<Fun(1,2)<<endl;	
	cout<<"L : "<<l<<endl;

	// Implementing Sort using lambda functions
	int arr[]={8,7,6,5,4,3,2,1};
	int N = sizeof(arr)/sizeof(int);
	sort(arr,arr+N,[=](int a,int b)->bool{
		return a<b;
	});
	P(arr,N);

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	int sum = 0;
	for_each(arr,arr+N,[&](int a){
		sum+=a;
	});
	cout<<sum<<endl;




	return 0;
}