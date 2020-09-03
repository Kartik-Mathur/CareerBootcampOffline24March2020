// Problem link : 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
//  CLASS NODE //
class node{
public:
	char ch;
	unordered_map<char,node*> h;
	bool isTerminal;
	int freq;
	node(char c){
		ch = c;
		isTerminal = false;
		freq = 1;
	}
};

class trie{
	node* root;
public:
	trie(){
		root = new node('\0');
	}

	void insert(char *word){
		node* temp = root;
		for(int i = 0 ; word[i]!='\0' ;i++){
			char ch = word[i];
			if(temp->h.count(ch)){
				// that means ch exists
				temp = temp->h[ch];
				temp->freq = temp->freq+1;
			}
			else{
				// that means ch does not exist
				temp->h[ch] = new node(ch);
				temp = temp->h[ch];
			}
		}
		temp->isTerminal = true;
	}

	bool search(char *word){
		node* temp = root;
		for(int i = 0 ; word[i] != '\0' ;i++){
			char ch = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else return false;
		}
		return temp->isTerminal;
	}

	void printUnique(char *word){
		node* temp = root;
		for(int i = 0 ; word[i] != '\0' ;i++){
			char ch = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
				if((temp->freq == 1)){
					for(int j = 0 ; j <= i ; j++){
						cout<<word[j];
					}
					cout<<endl;
					return;
				}
			}
		}
	}
};

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	trie t;
	char words[][10]= {
		"Hello",
		"Hell",
		"Coding",
		"Code"
	};

	t.insert("Hello");
	t.insert("Hell");
	t.insert("Coding");
	t.insert("Code");
	char word[100];
	cin>>word;
	if(t.search(word)){
		cout<<word<<" exists"<<endl;
	}
	else{
		cout<<word<<" don't exists"<<endl;
	}

	cin>>word;
	if(t.search(word)){
		cout<<word<<" exists"<<endl;
	}
	else{
		cout<<word<<" don't exists"<<endl;
	}
	cin>>word;
	if(t.search(word)){
		cout<<word<<" exists"<<endl;
	}
	else{
		cout<<word<<" don't exists"<<endl;
	}	
	cin>>word;
	if(t.search(word)){
		cout<<word<<" exists"<<endl;
	}
	else{
		cout<<word<<" don't exists"<<endl;
	}	
	cin>>word;
	if(t.search(word)){
		cout<<word<<" exists"<<endl;
	}
	else{
		cout<<word<<" don't exists"<<endl;
	}
	return 0;
}





















