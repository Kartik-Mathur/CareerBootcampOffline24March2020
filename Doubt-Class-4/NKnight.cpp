#include <iostream>
#include <vector>
using namespace std;
int n;
int Count = 0;
vector<pair<int,int> > ans;
bool board[200][200] = {0};
bool isValid(int i,int j){
	return j>=0 && j<n && i>=0 && i<n;
}
// i-2,j-1
bool KyaSafeHai(int i,int j){
	if(isValid(i-2,j-1) && board[i-2][j-1]) return false;
	if(isValid(i-1,j-2) && board[i-1][j-2]) return false;
	if(isValid(i+1,j-2) && board[i+1][j-2]) return false;
	if(isValid(i+2,j-1) && board[i+2][j-1]) return false;
	if(isValid(i+2,j+1) && board[i+2][j+1]) return false;
	if(isValid(i+1,j+2) && board[i+1][j+2]) return false;
	if(isValid(i-1,j+2) && board[i-1][j+2]) return false;
	if(isValid(i-2,j+1) && board[i-2][j+1]) return false;
	return true;
}

bool Knight(int placed,int row,int col){
	if(placed == n){
		// Print the Positions of the Knight, inside ans
		for(int i=0;i<ans.size();i++){
			cout<<"{"<<ans[i].first<<"-"<<ans[i].second<<"} ";
		}
		cout<<" ";
		Count++;
		return false;
	}
	if(row == n) return false;
	if(col == n){
		return Knight(placed,row+1,0);
	}

	if(KyaSafeHai(row,col)){
		board[row][col] = 1;
		ans.push_back({row,col});
		bool KyaBaakiPlaceHuye = Knight(placed+1,row,col+1);
		if(KyaBaakiPlaceHuye) return true;
		board[row][col] = 0;
		ans.pop_back();
	}
	return Knight(placed,row,col+1);
}

int main(){
	
	cin>>n;
	Knight(0,0,0);

	cout<<endl<<Count<<endl;
	return 0;
}