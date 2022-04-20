class Solution
{
public:
    int len(ListNode* head)
    {
        int lent = 0;
        while(head!=NULL)
        {
            lent++;
            head = head->next;
        }
        return lent;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        int k = len(head)-n;
        ListNode* temp = sentinel;
        while(k-->0)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return sentinel->next;
    }
};