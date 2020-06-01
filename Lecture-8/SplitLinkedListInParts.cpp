/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	int length(ListNode* head){
		int ans = 0;
		while(head){
			ans++;
			head = head->next;
		}
		return ans;
	}
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
    	int n = length(root);
    	ListNode* head = root;

    	int ElementsRemaining = n%k;
    	int parts = n/k;
    	int len = n/k;
    
    	vector<ListNode*> ans;

    	if(parts == 0){
    		// every segment will be of length equals to 1
    		for(int i=0;i<k;i++){
    			if(head){
    				ListNode* n= head->next;
    				head ->next = NULL;
    				ans.push_back(head);
    				head = n;
    			}
    			else{
    				ans.push_back(NULL);
    			}
    		}
    	}
    	else{
    		int count = 1;
    		while(head){
				ans.push_back(head);	

    			int x = ElementsRemaining>0?1:0;
    			ElementsRemaining--;
    			for(int i=1;i<len+x;i++){
    				head = head->next;
    			}
    			ListNode* n = head->next;
    			head->next =NULL;
    			head = n;
    			count++;
    			if(count == k){
    				ans.push_back(head);
    				break;
    			}
    		}

    	}
    	return ans;

    }
};