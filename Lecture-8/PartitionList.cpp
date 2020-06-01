// PartitionList
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* n=NULL,*b=NULL,*c,*bh,*ch;
        c = bh = ch = NULL;

        while(head){
        	n = head->next;
        	if(head->val<x){
        		if(c == NULL){
        			ch = c = head;
        			head->next = NULL;
        			head = n;
        		}
        		else{
        			c->next = head;
        			head->next = NULL;
        			c = head;
        			head = n;
        		}
        	}
        	else{
        		if(b == NULL){
        			bh = b = head;
        			head->next = NULL;
        			head = n;
        		}
        		else{
        			b->next = head;
        			head->next = NULL;
        			b = head;
        			head = n;
        		}
        	}
        }
        if(c!=NULL){
        	c->next = bh;
        	return ch;
        }
        else{
        	return bh;
        }
    }
};