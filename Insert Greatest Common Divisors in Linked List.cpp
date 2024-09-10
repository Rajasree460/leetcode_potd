/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    int hcf;
    struct ListNode* temp = head;
    while(temp->next)
    {
        hcf = gcd(temp->val,temp->next->val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = hcf;
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    return head;
}
