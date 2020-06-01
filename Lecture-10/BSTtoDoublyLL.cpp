// BSTtoDoubleLL : https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
class Solution {
	class LinkedList{
	public:
		Node* head;
		Node* tail;
	};

    LinkedList BSTtoLL(Node* root){
    	LinkedList l;
    	if(root == NULL){
    		l.head = l.tail = NULL; 
    		return l;
    	}

    	if(root->left == NULL && root->right == NULL){
    		l.head=l.tail = root;
    		root->right = root->left = root;
    		return l;
    	}
    	else if(root->left != NULL && root->right == NULL){
    		LinkedList left = BSTtoLL(root->left);
    		left.tail->right = root;
    		root->left = left.tail;
    		root->right = left.head;
    		left.head->left = root;
    		return l;
    	}
    	else if(root->left == NULL && root->right != NULL){
    		LinkedList right = BSTtoLL(root->right);
    		root->right = right.head;
    		right.left->head = root;
    		root->left = right.tail;
    		right.tail->right = root;
    		return l;
    	}
    	else{
    		// left!=NULL && right!=NULL
    		LinkedList left = BSTtoLL(root->left);
    		LinkedList right = BSTtoLL(root->right);

    	}
    }
public:
    Node* treeToDoublyList(Node* root) {
        LinkedList l = BSTtoLL(root);
        return l.head;
    }
};
