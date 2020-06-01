// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
vector<int> ans;
int K;

int NodesAtDistK(TreeNode* root,int target){
	if(root == NULL){
		return -1;
	}
	else if(root->val == target){
		FindAllNodes(root,0);
		return 1;
	}
	else{
		int left = NodesAtDistK(root->left,target);	
		int right = NodesAtDistK(root->right,target);
		if(left!=-1){
			if(left == K){
				ans.push_back(root->val);
			}
			FindAllNodes(root->right,left+1);
			return left+1;
		}
		else if(right!=-1){
			if(right == K){
				ans.push_back(root->val);
			}
			FindAllNodes(root->left,right+1);
			return right+1;
		}
		else{ 
            return -1;
        }
	}
}

void FindAllNodes(TreeNode* root,int dist){
	if(root == NULL) return;
	if(dist == K){
		ans.push_back(root->val);
		return;
	}
	FindAllNodes(root->left,dist+1);
	FindAllNodes(root->right,dist+1);
}
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->K = K;
        
        NodesAtDistK(root,target->val);
        return ans;
    }
};