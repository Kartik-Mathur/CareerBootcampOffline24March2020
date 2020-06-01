//  https://leetcode.com/problems/path-sum-ii/
#include <iostream>
using namespace std;
vector<int> path;
vector<vector<int> > ans;
void FindPath(TreeNode* root, int sum){
	// Base case
	if(root == NULL){
		return;
	}
	// Recrusive case
	path.push_back(root->val);
	if(root->val == sum && !root->left && !root->right){
		ans.push_back(path);
	}
	else{
		FindPath(root->left,sum-root->val);
		FindPath(root->right,sum-root->val);
	}
	path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	FindPath(root,sum);
	return ans;
}	

int main(){
	


	cout<<endl;
	return 0;
}