class Solution {
	ListNode* mid(ListNode* head){
		if(head == NULL || head->next == NULL) return head;
		node* slow = head;
		node* fast = head->next;
		while(fast && fast->next){
			slow = slow->next;
			fast=fast->next;
		}
		return slow;
	}

	void ReverseLL(ListNode* &head){

		ListNode* p,*c,*n;
		p = NULL;
		c = head;
		while(c){
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		head = p;
	}

public:
    void reorderList(ListNode* head) {
    	if(head == NULL || head->next == NULL) return;

        ListNode* m = mid(head);
        ListNode *h = head,*h1 = m->next;
        m->next = NULL;
        ReverseLL(h1);
        ListNode *x,*y;

        while(h1){
        	x = h->next;
        	y = h1->next;

        	h->next = h1;
        	h = x;

        	h1->next = h;
        	h1 = y;
        }
    }
};






















