// OddEvenLinkedList
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if(head == NULL || head->next == NULL){
    		return head;
    	}

    	ListNode* evenh=NULL,*oddh=NULL,*p=NULL,*c=NULL,*n=NULL;
    	oddh = head;
    	evenh = head->next;
    	c = head;
    	int jump = 0;
    	while(c && c->next){
    		n = c->next;
    		c->next = n->next;
    		p = c;
    		c = n;
    		jump++;
    	}
    	if(jump % 2 == 0){
    		c->next = evenh;
    	}
    	else{
    		p->next = evenh;
    	}
    	return oddh;
    }
};