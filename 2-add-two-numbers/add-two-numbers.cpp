
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        int carry = 0;
        while(l1 != nullptr || l2!=nullptr || carry !=0)
        {
            int digit1=0;
            int digit2=0;

            if(l1 != nullptr)
            {
                digit1 = l1->val;
                l1 = l1->next;
            }

            
            if(l2 != nullptr)
            {
                digit2 = l2->val;
                l2 = l2->next;
            }

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum/10;

            tail->next = new ListNode(digit);
            tail= tail->next;
        }
        return dummy.next;
        
    }
};