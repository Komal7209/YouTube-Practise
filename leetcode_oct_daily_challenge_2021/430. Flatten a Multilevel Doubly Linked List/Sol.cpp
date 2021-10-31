class Solution
{

    //main function

    Node *flatten_rec(Node *head)
    {
        Node *curr = head, *tail = head;
        while (curr)
        {
            Node *child = curr->child;
            Node *next = curr->next; //for returning the tail
            if (child)
            {
                Node *_tail = flatten_rec(child);

                _tail->next = next;
                if (next)
                    next->prev = _tail;

                curr->next = child;
                child->prev = curr;

                curr->child = nullptr;

                curr = tail;
            }
            else             //if there is no child
                curr = next; //then curr just start moving to next next
            if (curr)
                tail = curr;
        }

        return tail;
    }

public:
    Node *flatten(Node *head)
    {
        if (head)
            flatten_rec(head);
        return head;
    }
};