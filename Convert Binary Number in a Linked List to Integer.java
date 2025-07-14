/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int bin = 0;
    while(head)
    {
        bin = (bin << 1) + head->val;  // same as bin = (bin * 2) + head->val;
        head = head->next;
    }
    return bin;
}
