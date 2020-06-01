// SudokuSolver
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
using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001

bool isSafeToPutNumber(int mat[][9],int i,int j,int n,int number){
	for(int k=0;k<n;k++){
		if(mat[i][k]==number || mat[k][j]==number){
			return false;
		}
	}

	// Check the smaller box
	n = sqrt(n);
	int starti = (i/n)*n;
	int startj = (j/n)*n;

	for(int k=starti;k<starti+n;k++){
		for(int l=startj;l<startj+n;l++){
			if(mat[k][l] == number) return false;
		}
	}
	return true;
}

bool SudokuSolver(int mat[][9],int i,int j,int n){
	// Base case
	if(i == n){
		//Print the sudoku
		PNF(mat,n,n);
		return true;
	}

	if(j == n){
		return SudokuSolver(mat,i+1,0,n);
	}
	
	if(mat[i][j] != 0){
		return SudokuSolver(mat,i,j+1,n);
	}

	// Har cell ke liye kya kaam krna hai vo denote krte hai
	for(int number =1 ;number<=n;number++){
		if(isSafeToPutNumber(mat,i,j,n,number)){
			mat[i][j] = number;
			bool KyaBaakiSudokuSolveHua = SudokuSolver(mat,i,j+1,n);
			if(KyaBaakiSudokuSolveHua) return true;
			mat[i][j] = 0;
		}
	}
	return false;
}


int main(){
	int mat[9][9] =
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};	

	SudokuSolver(mat,0,0,9);

	return 0;
}





















