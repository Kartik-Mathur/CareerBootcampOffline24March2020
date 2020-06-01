// LCA https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <iostream>
using namespace std;

class node{
public:
	bool ContainsP;
	bool ContainsQ;
	TreeNode* n;
};

node* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
	// Base case
	if(root == NULL){
		return NULL;
	}

	// left mei kaun kaunsi hai P and Q mei se batao?
	node* left = LCA(root->left,p,q);
	if(left!=NULL && left->n!=NULL) return left;
	// Check whether there is P and Q in right or not?
	node* right = LCA(root->right,p,q);
	if(right!=NULL && right->n!=NULL) return right;

	node *x = new node();

	if(left!=NULL && right!=NULL){
		x->n = root;
		x->ContainsP = x->ContainsQ = true;
		return x;
	}
	else if(root->val == p->val){
		x->ContainsP = true;
		x->ContainsQ = (left)?left->ContainsQ:false || (right)?right->ContainsQ:false;
		if(x->ContainsP && x->ContainsQ) x->n = root;
		return x;
	}
	else if(root->val == q->val){
		x->ContainsQ = true;
		x->ContainsP = (left)?left->ContainsP:false || (right)?right->ContainsP:false;
		if(x->ContainsP && x->ContainsQ) x->n = root;
		return x;
	}
	else if(left) return left;
	else if(right) return right;
	else return NULL;
}



int main(){
	


	cout<<endl;
	return 0;
}