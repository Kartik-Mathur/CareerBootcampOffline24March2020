class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int freq[10001]={0};

        for(int i =0;i<G.size();i++){
        	freq[v[i]]++;
        }
        int component = 0;
        while(head){
        	if(head->val && head->next && freq[head->next]){
        		head = head->next;
        	}
        	else{
        		component++;
        		head = head->next;
        	}
        }
        return component;
    }
};