// TC: O(n)
// Sc: O(1)
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {

        // base cases

        if (!head)
            return NULL;
        if (!head->next)
        {
            delete head;
            return NULL;
        }

        // slow and fast pointer for finding mid , prev pointer which will help in changing pointer

        ListNode *slow = head, *fast = head, *prev;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // return slow; // this is the pointer which gives mid as ans

        // For deleting the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};