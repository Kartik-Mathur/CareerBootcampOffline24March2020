// BinaryTreeCamera https://leetcode.com/problems/binary-tree-cameras/
#include <iostream>
using namespace std;

unordered_map<TreeNode*,bool> h;
int camera;

void PlaceCamera(TreeNode* root,TreeNode* parent){
	// base case
	if(root == NULL) return;

	PlaceCamera(root->left,root);
	PlaceCamera(root->right,root);

	if(parent==NULL && !h.count(root)|| !h.count(root->left) || !h.count(root->right)){
		camera++;
		h[parent] = h[root] = h[root->left] = h[root->right] = true;
	}
}

int minCameraCover(TreeNode* root) {
	camera = 0;
	h.insert({NULL,true});
	PlaceCamera(root,NULL);
	return camera;
}

int main(){
	


	cout<<endl;
	return 0;
}