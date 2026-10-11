/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode*list1 , ListNode*list2 )
    {
        ListNode dummy(0);
        ListNode * current = &dummy;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1 -> val <= list2 -> val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current -> next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        if(list1 != nullptr)
        {
            current -> next = list1;

        }
        else
        {
            current->next = list2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
        {
            return nullptr;
        }
        int interval = 1;
        while(interval<n)
        {
            for(int i =0;i+interval <n ; i+= 2*interval)
            {
                lists[i] = mergeTwoLists(lists[i] , lists[i+interval]);
            }
            interval = interval * 2;
        }
        return lists[0];
    }
};