/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;

NODE removeNthFromEnd(NODE head, int k) {
    if (head == NULL || k < 1)
        return head;

    // Dummy node
    NODE temp = (NODE)malloc(sizeof(*temp));
    temp->next = head;

    NODE fast ,slow;
    fast = slow = temp;

    // Move fast k+1 steps
    for (int i = 1; i <= k; i++) {
        if (fast->next == NULL) {
            free(temp);          // invalid k
            return head;
        }
        fast = fast->next;
    }
    // Then,
    // Move both pointers until fast reaches last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the target node
    NODE del = slow->next;
    slow->next = del->next;
    free(del);

    // Update head and free dummy
    head = temp->next;
    free(temp);

    return head;
}
