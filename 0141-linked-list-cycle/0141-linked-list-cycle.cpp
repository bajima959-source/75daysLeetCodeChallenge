/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode*head) {
        if (head == NULL || head->next == NULL)
            return false;

        ListNode*slow = head;
        ListNode*fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            if (slow == fast)            // cycle detected
                return true;
        }

        return false; // no cycle
    }
};