// Diameter.cpp https://leetcode.com/problems/diameter-of-binary-tree/
#include <iostream>
using namespace std;

class Pair{
public:
	int dia;
	int height;
};

Pair Diameter(TreeNode* root){
	// Base case
	Pair p;
	if(root == NULL){
		p.height = p.dia = 0;
		return p;
	}
	// Recursive case	 
	int op1,op2,op3;
	op1=op2=op3=INT_MIN;
	Pair left = Diameter(root->left);
	Pair right = Diameter(root->right);

	op1 = left.height+right.height;
	op2 = left.dia;
	op3 = right.dia;

	p.height = max(left.height,right.height)+1;
	p.dia = max(op1,max(op2,op3));
	return p;
}

int diameterOfBinaryTree(TreeNode* root) {
	Pair ans = Diameter(root);
	return ans.dia;
}

int main(){
	


	cout<<endl;
	return 0;
}