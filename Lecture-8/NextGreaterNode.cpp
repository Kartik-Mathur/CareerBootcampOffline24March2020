class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        
        while(head){
            ListNode* temp = head;
            while(temp && temp->val<=head->val){
                temp = temp->next;
            }
            if(temp) ans.push_back(temp->val);
            else ans.push_back(0);
            
            head = head->next;
        }
        return ans;
    }
};