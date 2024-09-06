/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define maxN 100005

struct ListNode *modifiedList(int *nums, int numsSize, struct ListNode *head) {
    int presented[maxN] = {0};
    for (int i = 0; i < numsSize; i++) {
        presented[nums[i]]++;
    }
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *curr = head;
    while (curr != NULL) {
        if (presented[curr->val]) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    struct ListNode *res = dummy->next;
    free(dummy);
    return res;
}
