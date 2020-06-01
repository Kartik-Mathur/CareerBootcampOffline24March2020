// isValidBST : https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
    bool isBST(TreeNode* root,long long int min= -1*1e12,long long int max = 1e12){
        if(root == NULL) return true;
        
        if(root->val>min && root->val<max && isBST(root->left,min,root->val) && isBST(root->right,root->val,max)){
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};