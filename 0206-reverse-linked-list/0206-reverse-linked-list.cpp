class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // store next node
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev forward
            curr = nextTemp;                 // move curr forward
        }

        return prev; // new head
    }
};